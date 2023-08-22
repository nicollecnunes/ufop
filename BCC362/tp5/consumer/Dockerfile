FROM python:3.8-slim

WORKDIR /app

COPY consumer.py .

RUN pip install --upgrade pip
RUN pip install kafka-python

CMD ["python", "consumer.py"]