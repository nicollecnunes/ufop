import time
import pika

credentials = pika.PlainCredentials('alexnicolle', '1234')
connection = pika.BlockingConnection(pika.ConnectionParameters('ra-inst', credentials=credentials))
channel = connection.channel()

channel.queue_declare(queue='fila_tp3')

mensagens_por_segundo = 1  
tamanho_string = 10  
maximo_mensagens = 10

def enviar_mensagem_para_fila():
    mensagem = "ALEX E NICOLLE"
    channel.basic_publish(exchange='', routing_key='fila_tp3', body=mensagem)
    print("Mensagem enviada:", mensagem)

for i in range(maximo_mensagens):
    enviar_mensagem_para_fila()
    time.sleep(1/mensagens_por_segundo)

connection.close()
