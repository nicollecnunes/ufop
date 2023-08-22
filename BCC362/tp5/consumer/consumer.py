import time
import os
from kafka import KafkaConsumer

def consume_messages(topic):
    print("consuming?")
    retries = 10
    for _ in range(retries):
        try:
            consumer = KafkaConsumer(
                topic,
                bootstrap_servers='kafka:9092',
                auto_offset_reset='earliest',
                group_id=None,
                api_version=(0, 10, 2)  # Specify your Kafka version here
            )
            break
        except Exception as e:
            print("Error connecting to Kafka, retrying...")
            time.sleep(5)  # Wait for 5 seconds before retrying

    else:
        print("Max retries reached. Could not connect to Kafka.")
        return

    time.sleep(20)  # Additional sleep to ensure Kafka is fully initialized

    for message in consumer:
        print(message.value.decode('utf-8'))

if __name__ == "__main__":
    #print('ccreating log4j')
    #log4j_config_path = "../log4j.properties"
    #os.environ["LOG4J_CONFIGURATION"] = f"log4j.configuration=file:{log4j_config_path}"
    topic_name = "test_topic"

    consume_messages(topic_name)
