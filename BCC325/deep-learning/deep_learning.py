# -*- coding: utf-8 -*-
"""deep_learning.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/192LaR7W9BhY0m7Knlgp7l7dJ5zKgRe5P
"""

!ls '/content/drive/MyDrive/Colab Notebooks/datasetBrain'

from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.applications import MobileNetV2
from tensorflow.keras.layers import AveragePooling2D
from tensorflow.keras.layers import Dropout
from tensorflow.keras.layers import Flatten
from tensorflow.keras.layers import Dense
from tensorflow.keras.layers import Input
from tensorflow.keras.models import Model
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.applications.mobilenet_v2 import preprocess_input
from tensorflow.keras.preprocessing.image import img_to_array
from tensorflow.keras.preprocessing.image import load_img
from tensorflow.keras.utils import to_categorical

from sklearn.preprocessing import LabelBinarizer
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from imutils import paths
import matplotlib.pyplot as plt
import numpy as np
import os

INIT_LR = 1e-4
EPOCHS = 3
BS = 32

train_dir = '/content/drive/MyDrive/Colab Notebooks/datasetBrain/CroppedTraining'
CATEGORIES = ['no_tumor', 'yes_tumor']

data = []
labels = []

for cat in CATEGORIES:
  path = os.path.join(train_dir, cat)
  for img in os.listdir(path):
    img_path = os.path.join(path, img)
    image = load_img(img_path, target_size=(224,224))
    image = img_to_array(image)
    image = preprocess_input(image)

    data.append(image)
    labels.append(cat)

lb = LabelBinarizer()
labels = lb.fit_transform(labels)
labels = to_categorical(labels)

data = np.array(data, dtype='float32')
labels = np.array(labels)

(trainX, testX, trainY, testY) = train_test_split(data, labels, test_size=0.20, stratify=labels, random_state=42)

aug = ImageDataGenerator(
    rotation_range=20,
    zoom_range=0.15,
    width_shift_range=0.2,
    height_shift_range=0.2,
    shear_range=0.15,
    horizontal_flip=True,
    fill_mode='nearest'
)

baseModel = MobileNetV2(weights='imagenet', include_top=False,input_tensor=Input(shape=(224,224,3)))

headModel = baseModel.output
headModel = AveragePooling2D(pool_size=(7,7))(headModel)
headModel = Flatten(name='flatten')(headModel)
headModel = Dense(128, activation='relu')(headModel)
headModel = Dropout(0.5)(headModel)
headModel = Dense(2, activation='softmax')(headModel)

model = Model(inputs=baseModel.input, outputs=headModel)

for layer in baseModel.layers:
  layer.trainable = False

#print('[INFO] Compilando Model...')
opt = Adam(lr=INIT_LR, decay=INIT_LR / EPOCHS)
model.compile(loss='binary_crossentropy', optimizer=opt, metrics=['accuracy'])

H = model.fit(
    aug.flow(trainX, trainY, batch_size=BS),
    steps_per_epoch=len(trainX) //BS,
    validation_data = (testX, testY),
    validation_steps=len(testX) //BS,
    epochs = EPOCHS
)

print('[INFO] Evaluating networl')
predIdxs = model.predict(testX, batch_size=BS)

predIdxs = np.argmax(predIdxs, axis=1)

print(classification_report(testY.argmax(axis=1), predIdxs, target_names=lb.classes_))

print('[INFO] saving detector model')
model.save('tumor_detector.model', save_format='h5')

N = EPOCHS
plt.style.use('ggplot')
plt.figure()
plt.plot(np.arange(0,N), H.history['loss'], label='train_loss')
plt.plot(np.arange(0,N), H.history['val_loss'], label='val_loss')
plt.plot(np.arange(0,N), H.history['accuracy'], label='train_acc')
plt.plot(np.arange(0,N), H.history['val_accuracy'], label='val_acc')

plt.title('Training Loss and Accuracy')
plt.xlabel('Epoch #')
plt.ylabel('Loss/Accuracy')
plt.legend(loc='lower left')
plt.savefig('plot.png')

from tensorflow.keras.applications.mobilenet_v2 import preprocess_input
from tensorflow.keras.preprocessing.image import img_to_array
from tensorflow.keras.models import load_model
import matplotlib.pyplot as plt
import tensorflow as tf
import argparse
import imutils
import time
import cv2
import os

print('[INFO] loading trained model for tumor classification')
model = tf.keras.models.load_model('tumor_detector.model')
image = cv2.imread("/content/drive/MyDrive/Colab Notebooks/datasetBrain/CroppedTesting/yes_tumor/0.jpg")
img = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
img = cv2.resize(img, (224,224))
img = img_to_array(img)
img = preprocess_input(img)
img = np.expand_dims(img, axis=0)
(no_tumor, yes_tumor) = model.predict(img)[0]
label = 'no_tumor' if no_tumor > yes_tumor else 'yes_tumor'
color = (0,255,0) if no_tumor > yes_tumor else (0,0,255)
label = '{}: {:.2f}%'.format(label, max(no_tumor, yes_tumor) *100)
cv2.putText(image, label, (50, 50 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
plt.show()

print('[INFO] loading trained model for tumor classification')
model = tf.keras.models.load_model('tumor_detector.model')
image = cv2.imread("/content/drive/MyDrive/Colab Notebooks/datasetBrain/CroppedTesting/yes_tumor/7.jpg")
img = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
img = cv2.resize(img, (224,224))
img = img_to_array(img)
img = preprocess_input(img)
img = np.expand_dims(img, axis=0)
(no_tumor, yes_tumor) = model.predict(img)[0]
label = 'no_tumor' if no_tumor > yes_tumor else 'yes_tumor'
color = (0,255,0) if no_tumor > yes_tumor else (0,0,255)
label = '{}: {:.2f}%'.format(label, max(no_tumor, yes_tumor) *100)
cv2.putText(image, label, (50, 50 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, color, 2)
plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
plt.show()