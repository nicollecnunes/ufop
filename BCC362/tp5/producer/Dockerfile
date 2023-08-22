FROM python:3.8-slim

WORKDIR /app

COPY producer.py .

RUN pip install --upgrade pip

RUN pip install kafka-python

CMD ["python", "producer.py"]
