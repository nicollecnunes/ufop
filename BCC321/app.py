# app.py
from flask import Flask, render_template, request, redirect, url_for, flash
import psycopg2  # pip install psycopg2
import psycopg2.extras
import numpy as np
import re
from datetime import datetime

app = Flask(__name__)
app.secret_key = "bcc321-bd"

DB_HOST = "localhost"
DB_NAME = "sampledb"
DB_USER = "postgres"
DB_PASS = "admin"

conn = psycopg2.connect(dbname=DB_NAME, user=DB_USER, password=DB_PASS, host=DB_HOST)
cur = conn.cursor()

# with open('init.sql', 'r') as file:
#     initSQL = file.read()

#     cur.execute(initSQL)
#     conn.commit()


@app.route('/')
def Index():
    
    cur.execute('SELECT * FROM usuario')
    list_users = cur.fetchall()
    # list_users = [[123, 'Nicolle', 'nicollecnunes', 'Diamantina'], [234, 'Nicolle', 'nicollecnunes', 'Diamantina'], [543, 'Nicolle', 'nicollecnunes', 'Diamantina']]
    return render_template('index.html', list_users=list_users, list_ativos=[])


@app.route('/delete/<string:id>', methods=['POST', 'GET'])
def delete_user(id):
    # cur = conn.cursor(cursor_factory=psycopg2.extras.DictCursor)

    cur.execute (f"DELETE FROM resulta_em WHERE codigo_usuario = {id}")
    cur.execute (f"DELETE FROM consulta WHERE codigo_usuario = {id}")
    cur.execute (f"DELETE FROM usuario WHERE codigo = {id}")
    conn.commit()

    return redirect(url_for('Index'))

@app.route('/consultar-ativos/<string:id>', methods=['POST', 'GET'])
def consultar_ativos(id):
    # cur = conn.cursor(cursor_factory=psycopg2.extras.DictCursor)
    # s = 'SELECT CodigoAtivo, Tipo FROM FundoInvestimentos WHERE CodigoUsuario = {0}'.format(id)

    # cur.execute(s)
    # list_ativos = cur.fetchall()

    s2 = 'SELECT nome_usuario FROM carteira_investimentos WHERE codigo_usuario = {0}'.format(id)
    cur.execute(s2)
    nome_user = "".join(cur.fetchone()) 

    cur.execute('select nome_usuario, codigo_ativo from carteira_investimentos where codigo_usuario = {0}'.format(id))
    list_ativos = cur.fetchall()

    # nome_user = "Nicolle"
    # list_ativos = [[1, 'Tipo B'], [3, 'Tipotipo']]
    return render_template('index.html', list_ativos=list_ativos, nome_user=nome_user)


@app.route('/consulta-por-data/<de>/<ate>')
def consulta_por_data(de=None, ate=None):
    cur = conn.cursor(cursor_factory=psycopg2.extras.DictCursor)
    # s = 'SELECT * FROM tabela WHERE {0} BETWEEN data1 AND {1}'

    # novoDe = datetime.strptime(de, "%Y-%m-%d").strftime('%d-%m-%Y')
    # novoAte = datetime.strptime(ate, "%Y-%m-%d").strftime('%d-%m-%Y')

    cur.execute(f"SELECT * FROM investimento WHERE data_compra BETWEEN '{de} 00:00:00'::timestamp AND '{ate} 00:00:00'::timestamp")
    list_investimentos = cur.fetchall()

    # list_investimentos = [[550, 23, '02-02-2022'], [550, 23, '02-02-2022']]
    return render_template('index.html', list_investimentos=list_investimentos, dataDe=de, dataAte=ate)

@app.route('/investimentos-por-analistas')
def investimentos_analistas():
    # cur = conn.cursor(cursor_factory=psycopg2.extras.DictCursor)
    # s = 'SELECT * from'

    cur.execute("SELECT i.codigo_usuario, c.nss_analista, a.nome, i.data_compra, i.valor_corrente, i.quantidade, i.codigo_ativo FROM investimento AS i, resulta_em AS r, consulta AS c, analista AS a WHERE i.codigo_usuario = r.codigo_usuario AND i.data_compra = r.data_compra AND i.codigo_usuario = c.codigo_usuario AND a.nss = c.nss_analista")
    list_investimentos_analistas = cur.fetchall()

    # list_investimentos_analistas = [['nome analista 1', 53350, 2, '02-02-2022' ], ['nome analista 2', 50, 23, '02-02-2022']]
    return render_template('index.html', list_investimentos_analistas=list_investimentos_analistas)

@app.route('/', methods=['POST'])
def consulta_personalizada():
    consulta = request.form['text']
    # cur = conn.cursor(cursor_factory=psycopg2.extras.DictCursor)
    # s = consulta

    cur.execute(consulta)
    resultado_consulta = cur.fetchall()
    
    column = re.findall("SELECT\s*(.+?(?=FROM))", request.form['text'])
    search_column = ''.join(column)

    matches = re.findall("[^,\s][^\,]*[^,\s]*", search_column)
    lista_categorias = matches

    # cur.execute(f"SELECT column_name FROM information_schema.columns WHERE table_name = '{search_column}';")
    # lista_categorias = (''.join(x) for x in np.asarray(cur.fetchall()))

    #esse lista categorias seria o cabeçalho da tabela, pq dependendo da consulta retorna coisa diferente
    #n sei como pegar isso, se for dificil deixa vazio mesmo

    # lista_categorkias = []
    # resultado_consulta = [['resul.tado', 53350, 2, 'aaaa',
    #                        '02-02-2022'], ['resul.tado', 53350, 2, 'aaaa', '02-02-2022'], ]
    return render_template('index.html', resultado_consulta=resultado_consulta, lista_categorias=lista_categorias)

# cur.execute('SELECT * FROM carteira_investimentos')
# recset = cur.fetchall()
# for rec in recset:
#     rec = np.asarray(rec)
#     print(f"{rec}")

if __name__ == "__main__":
    app.run(debug=True)
# </string:id></id></id>


