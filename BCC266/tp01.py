import random

def iniciaRam():
    v = [None] * 10 #mudar pra 1000
    for i in range(len(v)):
        v[i] = random.randint(1,1001)
    return v
    


memoriaDados = iniciaRam()

for i in range (10):
    print("{}\n".format(memoriaDados[i])) #comentar