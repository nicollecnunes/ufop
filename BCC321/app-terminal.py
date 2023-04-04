import psycopg2  # pip install psycopg2
import psycopg2.extras
from getpass import getpass
import os
# from prettytable import PrettyTable


def connect():
    """ Connect to the PostgreSQL database server """

    conn = None

    # table = PrettyTable()

    print("Digite as credencias do banco de dados que deseja conectar: ")
    DB_HOST = input("HOST (IP): ")
    DB_NAME = input("Nome: ")
    DB_USER = input("User: ")
    DB_PASS = getpass("Password: " )

    print('Conectando ao banco de dados PostgreSQL...' )
    conn = psycopg2.connect(dbname=DB_NAME, user=DB_USER, password=DB_PASS, host=DB_HOST)
    cur = conn.cursor()

    print ( 'Versão do PostgreSQL: ' )

    cur.execute ( 'SELECT version()' )
    db_version = cur.fetchone()

    print(db_version)

    return cur, conn

def consulta_view(cur, conn):

    x = input("Digite as colunas que deseja consultar: ")
    y = input("Digite a condição que deseja para realizar a consulta: ")

    os.system('clear')
    print(f"\nConsulta:\nSELECT {x} \nFROM carteira_investimentos \nWHERE {y}")

    cur.execute (f"SELECT {x} FROM carteira_investimentos WHERE {y} ")

    rows = cur.fetchall( )

    # table = PrettyTable([f"{x}"])

    print("\n--------------------------------DATA OUTPUT--------------------------------")

    for row in rows:
        print ( f"[{row}]" )
        # table.add_row([f"{row}"])

    # print(table)
    # conn.close()

def deleta_usuario(cur, conn):

    id = input ("Digite o codigo do usuário que deseja deletar: ")

    cur.execute (f"DELETE FROM resulta_em WHERE codigo_usuario = {id}")
    cur.execute (f"DELETE FROM consulta WHERE codigo_usuario = {id}")
    cur.execute (f"DELETE FROM usuario WHERE codigo = {id}")

    conn.commit()

    os.system ( 'clear' )
    print ( f"\nConsulta:\nDELETE FROM resulta_em WHERE codigo_usuario = {id} \nDELETE FROM consulta WHERE codigo_usuario = {id} \nDELETE FROM usuario WHERE codigo = {id}" )

    cur.execute ( f"SELECT * FROM usuario" )

    rows = cur.fetchall ( )
    print("--------------------------------DATA OUTPUT--------------------------------")
    for row in rows:
        print ( f"[{row}]" )



def consulta_livre(cur, conn):

    _SELECT = input("SELECT: ")
    _FROM = input("FROM: ")
    _WHERE = input("WHERE: ")

    os.system ( 'clear' )
    print (f"\nConsulta:\nSELECT {_SELECT} \nFROM {_FROM} \nWHERE {_WHERE}" )

    cur.execute(f"SELECT {_SELECT} FROM {_FROM} WHERE {_WHERE}")

    rows = cur.fetchall ( )

    print("--------------------------------DATA OUTPUT--------------------------------")
    for row in rows:
        print ( f"[{row}]" )

def main():
    print("Conecte-se ao servidor de banco de dados PostgreSQL")
    cur, conn = connect()

    key = True

    while key:

        os.system ( 'clear' )

        print("Bem vindo ao painel de consultas!\n")

        print("1. Consultar view (carteira_investimentos). ")
        print("2. Deletar usuário específicado. ")
        print("3. Realizar consulta livre. ")
        print("4. Fechar conexão com o DB e sair. \n")

        option = input("Digite a opcao desejada: ")

        if option == '1':
            consulta_view(cur, conn)
            input ( "Pressione ENTER para continuar" )
        elif option == '2':
            deleta_usuario(cur, conn)
            input ( "Pressione ENTER para continuar" )
        elif option == '3':
            consulta_livre(cur, conn)
            input ( "Pressione ENTER para continuar" )
        elif option == '4':
            conn.close ( )
            key = False

    return "Clossing conection..."


if __name__ == '__main__':
    main()
