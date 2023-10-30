# -*- coding: utf-8 -*-
"""ListaFourier_PDI_Student.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/10Z3QzhNbT2m0Tu5n3s-9-_bJs4pnpKoS

# Carregar as bibliotecas
"""

import numpy as np
import math
from skimage import io, data, filters, util, color, transform, exposure
from scipy import ndimage, stats, fft
import matplotlib.pyplot as plt
from skimage.util import img_as_float, img_as_uint, img_as_ubyte

"""# Questão 1
<p align="justify">
Calcular a transformada de Fourier das seguientes imagens. Logo, compare sua semelhança usado a similaridade de cossenos.
<p>

<p>A similaridade de cossenos é definida da seguinte forma:
$$\frac{\sum{A*B}}{\sqrt{\sum{A^2}} \sqrt{\sum{B^2}}}$$
onde $A$ e $B$ são vetores.




<ol>
  <li>Implemente a função que calcule a similaridade de cossenos.</li>
  <li>Rotacione a imagem <i>A </i> em 30 e 60 graus. Logo, calcular a transformada de Fourier da letra A e das duas versões rotacionadas.  Depois, determine a semelhança entre elas usando a função que calcula a similaridade de cossenos.</li>
  <li>Compare a semelhança dos coeficientes de Fourier das letras <i>A, B</i>, e <i>V</i></li>
  <li>Compare a semelhança dos coeficientes de Fourier das letras <i>B</i>, e a versão de <i>B</i> trasladada</li>
  <li><i>Transforme as imagens de coordenadas cartesianas para coordenadas polares. Depois calcule a transformada de Fourier e determine a semelhança entre elas.</li>
</ol>
</p>



<table><tr>
<td> <img src="https://drive.google.com/uc?id=1h4QeEvRgB7wbAY9MocKGaaKDdniiQWQ6" alt="Drawing"  width="300"/> </td>
<td> <img src="https://drive.google.com/uc?id=1WV7pcoGXW6cJh74OjBwiD41gGcXfRMft" alt="Drawing"  width="300"/> </td>
<td> <img src="https://drive.google.com/uc?id=1soqJU7p5e59FBYBi1f5g34_4en8Q1e0k" alt="Drawing"  width="300"/> </td>
<td> <img src="https://drive.google.com/uc?id=1V5hZKGaQ-wlCjVnYgOG6WnnPih5nF7ET" alt="Drawing"  width="300"/> </td>
</tr></table>

### 2.1 Cálculo da similaridade de cossenos
"""

def cossine_sim(vecA, vecB):
  sim = np.sum(vecA*vecB) / (math.sqrt(np.sum(vecA**2)) * math.sqrt(np.sum(vecB**2)))
  return sim

print( cossine_sim(np.array([[2,4],[1,6]]), np.array([[3,5],[20,6]])) )

"""### 2.2 Rotacionar *A* em 30 e 60 graus. Depois calcule a Transformade Fourier das 3 imágenes. Finalmente, compare a letra A com as duas versões rotacionadas."""

A = io.imread('https://drive.google.com/uc?id=1h4QeEvRgB7wbAY9MocKGaaKDdniiQWQ6', as_gray = True)
A_30 = transform.rotate(A, 30, resize=False)
A_60 = transform.rotate(A, 60, resize=False)
f,ax = plt.subplots(1,3,figsize=(16,16))
ax[0].imshow(A, cmap='gray')
ax[1].imshow(A_30, cmap='gray')
ax[2].imshow(A_60, cmap='gray')

fA = fft.fftshift(fft.fft2(A))
fA_30 = fft.fftshift(fft.fft2(A_30))
fA_60 = fft.fftshift(fft.fft2(A_60))

print(f'Distancia entre A e A30: {cossine_sim(np.abs(fA), np.abs(fA_30))}')
print(f'Distancia entre A e A60: {cossine_sim(np.abs(fA), np.abs(fA_60))}')

"""###  2.3 Calcule a Transformade Fourier das letras *A, B* e *V*. Depois, compare os coeficientes de Fourier da letra A com a letra B, e com a letra V."""

B = io.imread('https://drive.google.com/uc?id=1WV7pcoGXW6cJh74OjBwiD41gGcXfRMft', as_gray = True)
V = io.imread('https://drive.google.com/uc?id=1V5hZKGaQ-wlCjVnYgOG6WnnPih5nF7ET', as_gray = True)
Bt = io.imread('https://drive.google.com/uc?id=1soqJU7p5e59FBYBi1f5g34_4en8Q1e0k', as_gray = True)

fB = fft.fftshift(fft.fft2(B))
fV = fft.fftshift(fft.fft2(V))

print(f'Distancia entre A e B: {cossine_sim(np.abs(fA), np.abs(fB))}')
print(f'Distancia entre A e V: {cossine_sim(np.abs(fA), np.abs(fV))}')

"""### 2.4 Calcule a transformada de Fourier das letras *B* e *Bt* traslada e compare seus coeficientes."""

fB = fft.fftshift(fft.fft2(B))
fBt = fft.fftshift(fft.fft2(Bt))

print(f'Distancia entre B e Bt: {cossine_sim(np.abs(fB), np.abs(fBt))}')

"""### 2.5 Transforme as 3 letras A de coordenadas cartesianas para coordenadas polares. Use a função <i>skimage.transform.warp_polar(image, center=None, radius=None, output_shape=None, scaling='linear', multichannel=False, channel_axis=None, **kwargs)</i>. Logo, calcule a transformada de Fourier da imagens transformadas e compare elas. Verifique se a distancian entre elas aumentou ou disminuiu"""

Ap = transform.warp_polar(A, output_shape=A.shape)
A_30p =  transform.warp_polar(A_30, output_shape=A_30.shape)
A_60p =  transform.warp_polar(A_60, output_shape=A_60.shape)

f,ax = plt.subplots(1,3,figsize=(16,16))
ax[0].imshow(Ap, cmap='gray')
ax[1].imshow(A_30p, cmap='gray')
ax[2].imshow(A_60p, cmap='gray')

fAp = fft.fftshift(fft.fft2(Ap))
fA_30p = fft.fftshift(fft.fft2(A_30p))
fA_60p = fft.fftshift(fft.fft2(A_60p))

print(f'Distancia entre A e A30: {cossine_sim(np.abs(fAp), np.abs(fA_30p))}')
print(f'Distancia entre A e A60: {cossine_sim(np.abs(fAp), np.abs(fA_60p))}')

"""## Questao 3
<p> A ideia principal do $\textit{unsharp masking}$ é que o desfoque da imagem remova os detalhes de uma imagem, mas se adicionarmos esses detalhes de volta à imagem dimensionada por um determinado fator, os detalhes seriam aprimorados e obteríamos uma imagem ``mais nítida''. O  $\textit{unsharp masking}$ é, portanto, definido como abaixo:
$$f + \alpha(f - f*g)$$
onde $f*g$ é a imagem suavizada, $f$ é a imagem original e $\alpha$ é um fator de escala. Implementar a função $\textit{unsharp masking}$
</p>
"""

def gridFourier(M, N):
    u = np.arange(0, M)
    v = np.arange(0, N)

    u = u - np.floor(M/2)
    v = v - np.floor(N/2)
    U, V = np.meshgrid(u, v)
    return U, V

def passa_freq(img, mask):
    fimg = fft.fftshift( fft.fft2(img) )
    fimgM = fimg * mask
    nimg = np.abs(fft.ifft2(fft.ifftshift(fimgM)))
    return nimg, fimg, fimgM

def mask_gaussiana(width, height, sigma):
    U, V = gridFourier(width, height)
    D = np.sqrt(U**2 + V**2)
    H = np.exp( -D**2/(2*sigma**2)  )
    return H

def highboost(img, radio = 30, k = 1):
  sigma = radio
  lin, col = img.shape
  mask = mask_gaussiana(col, lin, sigma)

  img_suavizada, fimg, fimgM = passa_freq(img, mask)

  img_nitida = img + k*(img - img_suavizada)
  img_nitida = np.clip(img_nitida, 0,1)
  return img_nitida, img_suavizada, mask, fimg, fimgM

def log_imshow(img):
    return np.log( np.abs(img)+1 )

img = data.chelsea()
img = color.rgb2gray(img)
img_nitida, img_suave, mask, fimg, fimgM = highboost(img, radio = 30, k = 5)

_, ax = plt.subplots(1,2,figsize=(20,8))
ax[0].imshow(img, cmap='gray')
ax[0].title.set_text('Imagem Original')
ax[1].imshow(mask, cmap='gray')
ax[1].title.set_text('Mascara')


_, bx = plt.subplots(1,2,figsize=(20,8))
bx[0].imshow(log_imshow(fimg), cmap='gray')
bx[0].title.set_text('Fourier Original')
bx[1].imshow(log_imshow(fimgM), cmap='gray')
bx[1].title.set_text('Fourier * Mask')

_, cx = plt.subplots(1,2,figsize=(20,8))
cx[0].imshow(img_suave, cmap='gray')
cx[0].title.set_text('Imagem Suavizada')
cx[1].imshow(img_nitida, cmap='gray')
cx[1].title.set_text('Imagem Nitida')