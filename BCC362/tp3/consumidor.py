import pika

def callback(ch, method, properties, body):
    print("Mensagem recebida:", body.decode())

credentials = pika.PlainCredentials('alexnicolle', '1234')
connection = pika.BlockingConnection(pika.ConnectionParameters('ra-inst', credentials=credentials))

channel = connection.channel()

channel.queue_declare(queue='fila_tp3')
channel.basic_consume(queue='fila_tp3', on_message_callback=callback, auto_ack=True)

print('Aguardando mensagens...........')
channel.start_consuming()
