import time
from kafka import KafkaProducer
import os

def send_messages(topic, message_size, messages_per_second):
    retries = 10
    for _ in range(retries):
        try:
            producer = KafkaProducer(bootstrap_servers='kafka:9092' )
            break
        except Exception as e:
            print("Error connecting to Kafka, retrying...")
            time.sleep(5)  # Wait for 5 seconds before retrying

    else:
        print("Max retries reached. Could not connect to Kafka.")
        return

    time.sleep(20)  # Additional sleep to ensure Kafka is fully initialized

    while True:
        message = "This is a test message of size {}.".format(message_size)
        producer.send(topic, message.encode('utf-8'))
        time.sleep(1 / messages_per_second)

if __name__ == "__main__":
    #log4j_config_path = "../log4j.properties"
    #os.environ["LOG4J_CONFIGURATION"] = f"log4j.configuration=file:{log4j_config_path}"
    topic_name = "test_topic"
    message_size = 50
    messages_per_second = 1

    send_messages(topic_name, message_size, messages_per_second)
