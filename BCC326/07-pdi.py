# -*- coding: utf-8 -*-
"""Lista_CNN_Student.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/15-52GxAZ6vUwldiPn_GIkmgj83xTKrXs

# Carregar as bibliotecas
"""

import numpy as np
import matplotlib.pyplot as plt
import time
import os
import copy

import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
from datetime import datetime
from torchvision import datasets, models, transforms
from torchsummary import summary
from sklearn import metrics

"""# Base MNIST

<p>O banco de dados MNIST (<i>Modified National Institute of Standards and Technology database</i>) é um grande banco de dados de dígitos manuscritos que é comumente usado para treinar vários sistemas de processamento de imagem.</p>

<p>As imagens em preto e branco do MNIST foram normalizadas para caber em uma caixa delimitadora de $28 \times 28$ pixels e suavizadas, o que introduziu níveis de tons de cinza.

O banco de dados MNIST contém 60.000 imagens de treinamento e 10.000 imagens de teste.</p>


<img src="https://drive.google.com/uc?id=16-aNB80uPOX1ZTsbx6MPjx8dyHs4zhJa" alt="MNIST"  width="700"/> </td>

## Carregar base MNIST do módulo *datasets* do Pytorch para classificar usando Rede Neural
"""

# Carrega o conjunto de treino
train_dataset = torchvision.datasets.MNIST(
    root='.', # salva no root
    train=True, # baixa o conjunto de treino
    transform=transforms.ToTensor(), # transforma as imagens em tensores
    download=True # realiza o download das imagens
)

print(train_dataset)

# Carrega o conjunto de teste
test_dataset = torchvision.datasets.MNIST(
    root='.',
    train=False,
    transform = transforms.ToTensor(),
    download=True
)

print(test_dataset)

"""## Datalaloader usada para criar batches de imagens"""

# Data loader
# Cria automáticamente batches de imagens
batch_size = 128 # 128 imagens por batch

train_loader = torch.utils.data.DataLoader(dataset = train_dataset, # utiliza o conjunto de treino
    batch_size = batch_size, # define o número de imagens por batch
    shuffle = True # embaralha as imagens
    )

test_loader = torch.utils.data.DataLoader(dataset = test_dataset, # utiliza o conjunto de treino
    batch_size = batch_size,  # define o número de imagens por batch
    shuffle = False # Não embaralha as imagens. Para o conjunto de teste não é necessário
    )

# verificação do funcionamento do dataloader
for x, y in train_loader:
    print(f'batch de dados: {x.shape}')
    print(f'batch de etiquetas: {y.shape}')
    f, (ax1, ax2) = plt.subplots(1, 2, sharey=True)
#    ax1.imshow(np.transpose(x[0].numpy(), (1,2,0)), cmap = 'gray')
#    ax2.imshow(np.transpose(x[0].numpy(), (1,2,0)), cmap = 'gray')
    ax1.imshow(x[0].numpy()[-1,:,:], cmap = 'gray')
    ax2.imshow(x[1].numpy()[-1,:,:], cmap = 'gray')
    break

"""# Implementação a rede Lenet

<p>
A arquitetura LeNet foi proposta por um dos avôs do aprendizado profundo, Yann LeCunn. Pelos padrões de hoje, o LeNet é uma rede neural muito rasa, composta pelas seguintes camadas:

(CONV => RELU => POOL) * 2 => FC => RELU => FC => SOFTMAX
</p>

<img src="https://drive.google.com/uc?id=1hn7c0jA0tQDkxfz5LzIiOe3I4KOFydAC" alt="LeNet"  width="700"/> </td>


"""

class Lenet(nn.Module):
    def __init__(self, numChannels, classes):
        # chamar o construtor da classe Base (Pai)
        super(Lenet, self).__init__()

        # definição das camadas convolucionais
        self.conv_layers = nn.Sequential(
            # primeiro grupo convolucional
            nn.Conv2d(in_channels = numChannels, out_channels=20, kernel_size=5, stride=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
            # segundo grupo convolucional
            nn.Conv2d(in_channels = 20, out_channels=50, kernel_size=5, stride=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )
        # definiçao das camadas fully connected
        self.dense_layers = nn.Sequential(
            nn.Linear(in_features=800, out_features=500),
            nn.ReLU(),
            nn.Linear(in_features=500, out_features=classes)
        )
    def forward(self, x):
        out = self.conv_layers(x)
        out = out.view(out.size(0), -1)
        #out = nn.Flatten(out, start_dim = 1)
        out = self.dense_layers(out)
        return out

# Calcula o tamanho do mapa de características de saída depois de passar
# por uma camada de Convolução
def convolucao(W, F, S, P):
    """
    W: largura do mapa de entrada
    F: tamanho do filtro
    S: stride do filtro
    P: padding
    """
    return int( (W-F+2*P)/S+1 )

# Calcula o tamanho do mapa de características de saída depois de passar
# por uma camada de Pooling
def pooling(W, F, S):
    """
    W: largura do mapa de entrada
    F: tamanho do filtro
    S: stride do filtro
    """
    return int( (W-F)/S+1 )

tam_conv1 = convolucao(28, 5, 1, 0)
print(f'Tamanho do mapa de caracteristicas depois de pasar pela primeira camada de convolução: {tam_conv1}')
tam_pool1 = pooling(tam_conv1, 2, 2)
print(f'Tamanho do mapa de caracteristicas depois de pasar pela primeira camada de pooling: {tam_pool1}')
tam_conv2 = convolucao(tam_pool1, 5, 1, 0)
print(f'Tamanho do mapa de caracteristicas depois de pasar pela segunda camada de convolução: {tam_conv2}')
tam_pool2 = pooling(tam_conv2, 2, 2)
print(f'Tamanho do mapa de caracteristicas depois de pasar pela segunda camada de pooling: {tam_pool2}')
tam_filtros = 50 # número de filtros da segunda camada convolucional
print(f'Número de neuronios de entrada da primeira camada fully connected: {tam_pool2*tam_pool2*tam_filtros}')

"""# Definição da função de treino"""

def fit(model, criterion, optimizer, train_loader, val_loader, epochs):
    """
    model: a rede neural
    criterion: função de custo (Loss function)
    optimizer: função de otimização que minimiza a função de custo
    train_loader: conjunto de treino dividido em batches
    val_loader: conjunto de validação dividido em batches
    """
    train_losses = np.zeros( epochs )
    val_losses = np.zeros( epochs )

    for it in range(epochs):
        model.train() # setar a rede em modo treino
        t0 = datetime.now()
        train_loss = []

        for inputs, targets in train_loader:
            # mover os dados para o GPU
            inputs, targets = inputs.to(device), targets.to(device)

            # zerar os gradientes
            optimizer.zero_grad()

            # forward pass
            outputs = model(inputs)

            loss = criterion(outputs, targets)

            # backward pass e optimiza
            loss.backward()
            optimizer.step()

            train_loss.append( loss.item() )

        train_loss = np.mean(train_loss)

        val_loss = []
        for inputs, targets in val_loader:
            model.eval() # setar a rede em modo validação (pesos não são atualizados)
            # mover os dados para o GPU
            inputs, targets = inputs.to(device), targets.to(device)

            # forward pass
            outputs = model(inputs)
            loss = criterion(outputs, targets)
            val_loss.append(loss.item())
        val_loss = np.mean(val_loss)

        # salvar losses
        train_losses[it] = train_loss
        val_losses[it] = val_loss

        dt = datetime.now() - t0

        print(f'Epoch {it+1}/{epochs} Train Loss: {train_loss:.4f} Validation Loss: {val_loss} Duracao: {dt}')

    return train_losses, val_losses

"""# Modulo para avaliar o conjunto de teste"""

def predict_module(model, test_loader):

    model.eval() # a rede é colocada em modo avaliação, nenhum peso é atualizado
    predicted = np.empty((0), int)
    true_labels = np.empty((0), int)
    for inputs, targets in test_loader:
        # mover os dados para o GPU
        inputs, targets = inputs.to(device), targets.to(device)

        outputs = model(inputs)

        # obter a predição
        _, predictions = torch.max(outputs, 1)

        predicted = np.append(predicted, predictions.cpu())
        true_labels = np.append(true_labels, targets.cpu())

    return predicted, true_labels

"""## Calculo da matriz de confusão"""

def matriz_confusao(true_labels, predicted, display_labels=[0,1,2]):
    """
    true_labels: verdadeiras etiquetas (classes) do conjunto de dados avaliado
    predicted: etiquetas (classes) geradas pelo classificador
    display_labels: valores das etiquetas
    """
    matriz = metrics.confusion_matrix(true_labels, predicted)
    tot = np.sum(matriz, axis=1, keepdims=True)
    np.set_printoptions(precision=2)
    m_porc = matriz/tot
    disp = metrics.ConfusionMatrixDisplay(confusion_matrix=m_porc, display_labels=display_labels)
    disp.plot(values_format='.2f')
    plt.show()

"""## Função para graficar as funções de perda do treino e da validação"""

def plot_losses(train_losses, test_losses):
    plt.plot(train_losses, label = 'train loss')
    plt.plot(test_losses, label = 'test loss')
    plt.legend()
    plt.show()

"""# Treino"""

# Instanciar a rede
# A base MNIST consta de imagens em escala de cinza, ou seja, tem um único canal de cor
model = Lenet(numChannels=1, classes=10)

"""### A rede neural é enviada ao dispositivo disponível (CPU ou GPU)"""

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
model.to(device)
print(device)

"""## Definição das função de custo (Loss function) e do otimizador"""

# Loss para varias classes
criterion = nn.CrossEntropyLoss()
# Optimizer
#optimizer = torch.optim.Adagrad( model.parameters() )
optimizer = torch.optim.SGD(model.parameters(),
                                    lr=0.001,
                                    momentum=0.9,
                                    weight_decay=1e-3)

# treino da rede
train_losses, val_losses = fit(model, criterion, optimizer, train_loader, test_loader, epochs = 10)
# graficar as funções de perda
plot_losses(train_losses, val_losses)

"""# Teste"""

# Avaliando a rede treinada com o conjunto de teste
predicted, true_labels = predict_module(model, test_loader)
matriz_confusao(true_labels, predicted, [0,1,2,3,4,5,6,7,8,9])

"""## Questão 1
<p>
Crie uma nova rede neural convolucional. Ela deve estar composta pelas seguintes camadas:
<ul>
  <li>1 Camada convolucional com 32 filtros, um kernel de $ 3 \times 3$, stride de 2. Não será realizada nenhuma operação de padding</li>
  <li>1 camada de função de ativaçao ReLU</li>
  <li>1 Camada convolucional com 64 filtros, um kernel de $ 3 \times 3$, stride de 2. Não será realizada nenhuma operação de padding</li>
  <li>1 camada de função de ativaçao ReLU</li>
  <li>1 Camada convolucional com 128 filtros, um kernel de $ 3 \times 3$, stride de 2. Não será realizada nenhuma operação de padding</li>
  <li>1 camada de função de ativaçao ReLU</li>
  <li>1 camada fully-connected de 256 neuronios </li>
  <li>1 camada de função de ativação ReLU</li>
  <li>1 camada fully-connected do tamanho do número de classes</li>
</ul>
(CONV => RELU ) * 3 => FC => RELU => FC => SOFTMAX

A rede deve ser treinada com a base Fashion-MNIST
</p>
"""

class MinhaCNN(nn.Module):
    def __init__(self, numChannels, classes):
        # chamar o construtor da classe Base (Pai)
        super(MinhaCNN, self).__init__()

        # definição das camadas convolucionais
        self.conv1 = nn.Conv2d(numChannels, 32, kernel_size=3, stride=2, padding=0)
        self.relu1 = nn.ReLU()
        self.conv2 = nn.Conv2d(32, 64, kernel_size=3, stride=2, padding=0)
        self.relu2 = nn.ReLU()
        self.conv3 = nn.Conv2d(64, 128, kernel_size=3, stride=2, padding=0)
        self.relu3 = nn.ReLU()

        # definiçao das camadas fully connected
        self.fc1 = nn.Linear(128*2*2, 256)
        self.relu4 = nn.ReLU()
        self.fc2 = nn.Linear(256, classes)

    def forward(self, x):
        x = self.relu1(self.conv1(x))
        x = self.relu2(self.conv2(x))
        x = self.relu3(self.conv3(x))

        # Redimensionar para passar pelas camadas fully connected
        x = x.view(x.size(0), -1)

        # Passagem pelas camadas fully connected
        x = self.relu4(self.fc1(x))
        out = self.fc2(x)

        return out

"""## Calcular a dimensão de entrada da primeira camada fully connected"""

model = MinhaCNN(1, 10)
mock = torch.randn(1, 1, 28, 28)  # Amostra de entrada com tamanho 28x28


tam_conv1 = model.conv1(mock).size(2)
print(f'Tamanho do mapa de caracteristicas depois de pasar pela primeira camada de convolução: {tam_conv1}')
tam_conv2 = model.conv2(model.relu1(model.conv1(mock))).size(2)
print(f'Tamanho do mapa de caracteristicas depois de pasar pela segunda camada de convolução: {tam_conv2}')
tam_conv3 = model.conv3(model.relu2(model.conv2(model.relu1(model.conv1(mock))))).size(2)
print(f'Tamanho do mapa de caracteristicas depois de pasar pela terceira camada de convolução: {tam_conv3}')

tam_filtros = 128 # número de filtros da segunda camada convolucional
print(f'Número de neuronios de entrada da primeira camada fully connected: {tam_conv3*tam_conv3*tam_filtros}')

"""#Fashion MNIST

<p>Fashion-MNIST é um conjunto de dados de imagens de <i>Zalando's article images</i>, consistindo em um conjunto de treinamento de 60.000 exemplos e um conjunto de teste de 10.000 exemplos. Cada exemplo é uma imagem em tons de cinza 28x28, associada a um rótulo de 10 classes.</p>

<p>A base consiste de 10 classes:
<ol>
  <li>camiseta/top</li>
  <li>Calça</li>
  <li>Pulôver</li>
  <li>vestido</li>
  <li>Casaco</li>
  <li>Sandália</li>
  <li>camisa</li>
  <li>tênis</li>
  <li>bolsas</li>
  <li>Tornozelo</li>
</ol>

<img src="https://drive.google.com/uc?id=1BIHLjrMID4Em3DaL2PzKLC1Q3oY5FUDw" alt="MNIST"  width="700"/> </td>

## Carregando base Fashion-MNIST
"""

train_dataset_fashion = torchvision.datasets.FashionMNIST(
    root='.',
    train=True,
    transform=transforms.ToTensor(),
    download=True
)

test_dataset_fashion = torchvision.datasets.FashionMNIST(
    root='.',
    train=False,
    transform=transforms.ToTensor(),
    download=True
)

"""## Datalaloader usada para criar batches de imagens"""

# Data loader
# Cria automáticamente batches de imagens
batch_size = 128 # 128 imagens por batch

train_loader_fashion = torch.utils.data.DataLoader(dataset = train_dataset_fashion, # utiliza o conjunto de treino
    batch_size = batch_size, # define o número de imagens por batch
    shuffle = True # embaralha as imagens
    )

test_loader_fashion = torch.utils.data.DataLoader(dataset = test_dataset_fashion, # utiliza o conjunto de treino
    batch_size = batch_size,  # define o número de imagens por batch
    shuffle = False # Não embaralha as imagens. Para o conjunto de teste não é necessário
)

"""### Mostrando alguns exemplos da base"""

# verificação do funcionamento do dataloader
for x, y in train_loader_fashion:
    print(f'batch de dados: {x.shape}')
    print(f'batch de etiquetas: {y.shape}')
    f, (ax1, ax2) = plt.subplots(1, 2, sharey=True)
#    ax1.imshow(np.transpose(x[0].numpy(), (1,2,0)), cmap = 'gray')
#    ax2.imshow(np.transpose(x[0].numpy(), (1,2,0)), cmap = 'gray')
    ax1.imshow(x[0].numpy()[-1,:,:], cmap = 'gray')
    ax2.imshow(x[1].numpy()[-1,:,:], cmap = 'gray')
    break

class Fashion(nn.Module):
    def __init__(self, numChannels, classes):
        # chamar o construtor da classe Base (Pai)
        super(Fashion, self).__init__()

        # definição das camadas convolucionais
        self.conv_layers = nn.Sequential(
            # primeiro grupo convolucional
            nn.Conv2d(in_channels = numChannels, out_channels=20, kernel_size=5, stride=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
            # segundo grupo convolucional
            nn.Conv2d(in_channels = 20, out_channels=50, kernel_size=5, stride=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )
        # definiçao das camadas fully connected
        self.dense_layers = nn.Sequential(
            nn.Linear(in_features=800, out_features=500),
            nn.ReLU(),
            nn.Linear(in_features=500, out_features=classes)
        )
    def forward(self, x):
        out = self.conv_layers(x)
        out = out.view(out.size(0), -1)
        #out = nn.Flatten(out, start_dim = 1)
        out = self.dense_layers(out)
        return out
# Instanciar a rede
# A base MNIST consta de imagens em escala de cinza, ou seja, tem um único canal de cor
model_fashion =  Fashion(numChannels=1, classes=10)

model_fashion.to(device)
print(device)

# Loss para varias classes
criterion_fashion = nn.CrossEntropyLoss()
# Optimizer
#optimizer = torch.optim.Adagrad( model.parameters() )
optimizer_fashion = torch.optim.SGD(model_fashion.parameters(),
                                    lr=0.001,
                                    momentum=0.9,
                                    weight_decay=1e-3)

# treino da rede
train_losses_fashion, val_losses_fashion = fit(model_fashion, criterion_fashion, optimizer_fashion, train_loader_fashion, test_loader_fashion, epochs = 10)
# graficar as funções de perda
plot_losses(train_losses_fashion, val_losses_fashion)

# Avaliando a rede treinada com o conjunto de teste
predicted, true_labels = predict_module(model_fashion, test_loader_fashion)
matriz_confusao(true_labels, predicted, [0,1,2,3,4,5,6,7,8,9])

# treino da rede
train_losses_fashion, val_losses_fashion = fit(model_fashion, criterion_fashion, optimizer_fashion, train_loader_fashion, test_loader_fashion, epochs = 50)
# graficar as funções de perda
plot_losses(train_losses_fashion, val_losses_fashion)

# Avaliando a rede treinada com o conjunto de teste
predicted, true_labels = predict_module(model_fashion, test_loader_fashion)
matriz_confusao(true_labels, predicted, [0,1,2,3,4,5,6,7,8,9])

"""## Dividir em três conjuntos: treino, validação e teste"""

train_dataset_split, val_dataset_split = torch.utils.data.random_split(train_dataset_fashion, [0.8, 0.2])

"""# Questão 2
<p>
Instancie um novo modelo, função de perda e de otimização e treine com o conjunto de treino e validação. Logo, avalie a acurácia do modelo com o conjunto de teste.</p>
"""

model_fashion2 = Fashion(numChannels=1, classes=10)
model_fashion2.to(device)

criterio = nn.CrossEntropyLoss()
optimizer = optim.Adam(model_fashion2.parameters(), lr=0.001)

train_loss, loss = fit(model_fashion2, criterio, optimizer, train_loader_fashion, test_loader_fashion, epochs=10)
plot_losses(train_loss, loss)


new_predicted, new_true_labels = predict_module(model_fashion2, test_loader_fashion)

certo = 0

for previsao, labelCerto in zip(predicted, true_labels):
    if previsao == labelCerto:
        certo += 1

print(certo / len(true_labels))

