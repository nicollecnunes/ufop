import random
import sys
import numpy as np

INT_MAX = sys.maxsize
RAM = [0] * 100
#retorno = 0
memoriaInstrucoes = np.empty((1000, 4)) #mudar 100

def iniciaRAM():
    for i in range(100):
        RAM[i] = random.randint(0, 1000)
        
def maquinaInt(umaInstrucao):
    opcode = umaInstrucao[0];
    if opcode == 0: #soma
        end1 = int(umaInstrucao[1])
        end2 = int(umaInstrucao[2])
        #print("end1 = {} e end2={}".format(end1, end2))
        soma = RAM[end1] + RAM[end2]
        end3 = int(umaInstrucao[3])
        #print("Somando {} com {} e obtendo {}\n".format(RAM[end1], RAM[end2], soma))
        RAM[end3] = soma        
    elif opcode == 1: #subtrai
        end1 = int(umaInstrucao[1])
        end2 = int(umaInstrucao[2])
        #print("end1 = {} e end2={}".format(end1, end2))
        sub = RAM[end1] - RAM[end2]
        end3 = int(umaInstrucao[3])
        RAM[end3] = sub       
    elif opcode == 2: #levar pra memoria
        conteudo = int(umaInstrucao[1])
        end = int(umaInstrucao[2])
        #print("levando pra memoria {} o {}".format(end, conteudo) )
        RAM[end] = conteudo
    elif opcode == 3: #trazer
        end = int(umaInstrucao[2])
        global retorno
        retorno = RAM[end]

        #0 soma; 1 subtrai; 2 leva; 3 traz
        
def maquina():
    PC = 0 #primeira instrução a ser processada
    opcode = 0
    while opcode != -1:
        umaInstrucao = [0,0,0,0]
        umaInstrucao = memoriaInstrucoes[PC]
        opcode = umaInstrucao[0]
        #print("estou aqui\n")
        
        maquinaInt(umaInstrucao)
        PC = PC +1
       
def montarInstAleatorias():
    umaInstrucao = [0] * 4
    for i in range(99):#mudar pra 99
        umaInstrucao[0] = random.randint(0,1) #gera 0 ou 1
        umaInstrucao[1] = random.randint(0, 99)
        umaInstrucao[2] = random.randint(0, 99)
        umaInstrucao[3] = random.randint(0, 99)
        memoriaInstrucoes[i] = umaInstrucao
        #print(memoriaInstrucoes[i])
        
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[99] = umaInstrucao
    #print(memoriaInstrucoes[99])
    
    for i in range(10):
        for j in range(4):
            print(memoriaInstrucoes[i][j])
        print()
    
    maquina()

# =============================================== OPERAÇÕES BÁSICAS ===================================

def instLevaPMemo(x, end): 
    umaInstrucao = [2,x,end,-1]
    return umaInstrucao

def trazMemo(end):
    umaInstrucao = [3,-1,end,-1]
    maquinaInt(umaInstrucao)
    return retorno #veio da maq

def somar(num1, num2):

    umaInstrucao = instLevaPMemo(num1, 0) #leva o num1 pra memoria no end 0
    memoriaInstrucoes[0] = umaInstrucao #montou 2 | num1 | 0 | -1 na linha 0

    umaInstrucao = instLevaPMemo(num2, 1) #leva n2 no end 1
    memoriaInstrucoes[1] = umaInstrucao #2|n2|1|-1 na linha 1

    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[2] = umaInstrucao # mem.inst ficou assim:
    # 2/num1/0/-1
    # 2/n2/1/-1
    #-1/-1/-1/-1
    
    maquina() #maquina leva pra memoria. sem parametro pq e variavel global

    umaInstrucao = umaInstrucao = [0,0,1,1] #end1 + end1 e guarda o resultado no end1
    memoriaInstrucoes[0] = umaInstrucao #montou 0/0/1/1
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[1] = umaInstrucao #mem. inst ficou assim:
    #0/end 0/1/end 1
    #-1/-1/-1/1
    maquina()
    
    resultado = trazMemo(1)
    maquinaInt(umaInstrucao)
    
    return resultado
      
def subtrair(num1, num2):
    umaInstrucao = instLevaPMemo(num1, 0)
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = instLevaPMemo(num2, 1)
    memoriaInstrucoes[1] = umaInstrucao

    umaInstrucao = [-1] * 4
    memoriaInstrucoes[2] = umaInstrucao
    
    maquina()

    umaInstrucao = [1,0,1,1]
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = [-1] * 4 #ghhalt
    memoriaInstrucoes[1] = umaInstrucao

    maquina()
    
    resultado = trazMemo(1)
    maquinaInt(umaInstrucao)
    
    return resultado

def multip(num1, num2): 
    umaInstrucao = [0] * 4
    
    umaInstrucao = instLevaPMemo(abs(num1), 0)#leva o valor n1 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(0, 1)#leva o valor 0 pra posicao 1
    memoriaInstrucoes[1] = umaInstrucao
    

    for i in range(abs(num2)): 
        umaInstrucao = [0,0,1,1] #vai montar 0 | 0 | 1 | 1
        #print(i)
        # somar | end0 tem o num1 | end1 inicialmente tem 0 | é pra onde vai o resultado (substituir). nas outras vezes do for, ja vai reaproveitar    
        memoriaInstrucoes[i+2] = umaInstrucao #+2 pq ja usei 0 e 1
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[num2+2] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina()

    resultado = trazMemo(1) #3/-1/1/-1
    maquinaInt(umaInstrucao)

    if(((num1>=0) and (num2>=0)) or ((num1<=0) and (num2<=0))):
        return resultado
    else:
        resultado = '-' + str(resultado)
    
    return resultado

def div(num1, num2):
    #0 soma; 1 sub; 3 traz; 2 leva
    if(num2 == 0):
        print("Impossível dividir por 0!\n")
        return "∄"
    umaInstrucao = [0] * 4
    
    umaInstrucao = instLevaPMemo(num2, 0)#leva o valor n2 pra posicao 0 (2/num2/0/-1)
    memoriaInstrucoes[0] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(num1, 1)#leva o valor n1 pra posicao 1 (2/num1/1-1)
    memoriaInstrucoes[1] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(1, 2)#leva o valor 1 pra posicao 2. vou usar pra somar no res
    memoriaInstrucoes[2] = umaInstrucao #(2/1/2/-1)
    
    umaInstrucao = instLevaPMemo(0,3) #leva 0 pro end 3. vai ser o resultado
    memoriaInstrucoes[3] = umaInstrucao #2/0/3/-1
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[4] = umaInstrucao
    
    maquina()
    
    ram0 = trazMemo(0) #traz o n2 do end0
    ram1 = trazMemo(0) #traz o n2 do end0
    
    while(ram0<=ram1):
        umaInstrucao = [1,1,0,1]  #subtrai num1(end1) de num2(end0) e coloca no end 1
        maquinaInt(umaInstrucao)
        umaInstrucao = [0,2,3,3] #soma o end2+end3 e poe no end3 (resultado)
        maquinaInt(umaInstrucao)
        
        ram1 = trazMemo(1) #traz a subtraçao parcial do end1
        
    resultado = trazMemo(3)
    maquinaInt(umaInstrucao)
        
    return resultado

def pot(num1, num2):
    umaInstrucao = instLevaPMemo(1, 0)#leva o valor 1 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    ram0 = trazMemo(0)
    if(num2 == 0):
        return ram0        
    
    for i in range(num2): #tentar criar uma funcao pra ficar aqui dentro
        ram0 = multip(num1, ram0)
        #print(ram0)
        
    umaInstrucao = [0] * 4
    
    umaInstrucao = instLevaPMemo(ram0, 0)#leva o valor ram0 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
     
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[1] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global
    
    resultado = trazMemo(0)
    maquinaInt(umaInstrucao)
    
    return resultado

def raizq(num1):
    
    umaInstrucao = [0] * 4
    
    umaInstrucao = instLevaPMemo(num1, 0)#leva o valor n1 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(0, 1)#leva o valor 0 pra posicao 1. comparar
    memoriaInstrucoes[1] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(0, 2)#leva o valor 0 pra posicao 2. count
    memoriaInstrucoes[2] = umaInstrucao
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[3] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global
    
    ram0 = trazMemo(0) #n1
    ram1 = trazMemo(1) #0
    ram2 = trazMemo(2) #0 count
    
    for i in range(1,ram0,2): #impares ate ram0
        ram1 = somar(ram1, i)
        ram2 = somar(ram2, 1)
        
        umaInstrucao = instLevaPMemo(ram2, 0)#leva o valor ram2 pra posicao 0
        
        maquinaInt(umaInstrucao)
        if (ram1==ram0):
            resultado = trazMemo(0)
            return resultado
        elif (ram1>ram0):
            print("Não é um quadrado perfeito.")
            return "∄ em N"

# ========================================== GEOMETRIA PLANA ======================================================
def fat(num1):
    umaInstrucao = instLevaPMemo(1, 0)#leva o valor 1 pra posicao 0
    
    maquinaInt(umaInstrucao)
    
    ram0 = trazMemo(0)
    
    for i in range(1,num1+1): 
        ram0 = multip(ram0, i)
        #print(ram0)
        
    umaInstrucao = [0] * 4
    
    umaInstrucao = instLevaPMemo(ram0, 0)#leva o valor ram0 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
     
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[1] = umaInstrucao 

    maquina() 
    
    resultado = trazMemo(0)
    maquinaInt(umaInstrucao)
    
    return resultado

def quadrArea(num1):
    #lxl
    umaInstrucao = instLevaPMemo(multip(num1,num1), 7)#leva o valor da multp pra posicao 7
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(7)

    umaInstrucao = instLevaPMemo(ram0, 5)#leva o valor ram0 pra posicao 5
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    resultado = trazMemo(5)

    return resultado

def retArea(num1, num2):
    #axb
    umaInstrucao = instLevaPMemo(multip(num1,num2), 12)#leva o valor da multp pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(12)

    umaInstrucao = instLevaPMemo(ram0, 5)#leva o valor ram0 pra posicao 5
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    resultado = trazMemo(5)

    return resultado

def paralelArea(num1, num2):
    #lxl
    umaInstrucao = instLevaPMemo(multip(num1,num2), 12)#leva o valor da multp pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(12)

    umaInstrucao = instLevaPMemo(ram0, 5)#leva o valor ram0 pra posicao 5
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    resultado = trazMemo(5)

    return resultado

def triArea(num1, num2):
    #(bxh)/2
    umaInstrucao = instLevaPMemo(multip(num1,num2), 12)#leva o valor da multp bxh pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = instLevaPMemo(2, 13)#leva o valor 2 pra posicao 13
    memoriaInstrucoes[1] = umaInstrucao

    maquina()

    ram0 = trazMemo(12) #bxh
    ram1 = trazMemo(13) #2

    ram0 = div(ram0, ram1)

    umaInstrucao = instLevaPMemo(ram0, 5)#leva o valor ram0 pra posicao 5
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    resultado = trazMemo(5)

    return resultado

def losangArea(num1, num2):
    #d*D)/2
    umaInstrucao = instLevaPMemo(multip(num1,num2), 12)#leva o valor da multp bxh pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = instLevaPMemo(2, 13)#leva o valor 2 pra posicao 13
    memoriaInstrucoes[1] = umaInstrucao

    maquina()

    ram0 = trazMemo(12) #bxh
    ram1 = trazMemo(13) #2

    ram0 = div(ram0, ram1)

    umaInstrucao = instLevaPMemo(ram0, 5)#leva o valor ram0 pra posicao 5
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    resultado = trazMemo(5)

    return resultado

def trapezArea(num1, num2, num3):
    #(b+B)*h)/2
    umaInstrucao = instLevaPMemo(somar(num1,num2), 9)#leva o valor da soma pra posicao 9
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(9)

    umaInstrucao = instLevaPMemo(multip(ram0,num3), 10)#leva o valor da multp (b+b)h pra posicao 10
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(10)

    umaInstrucao = instLevaPMemo(div(ram0,2), 74)#leva o valor da multp (b+b)h/2 pra posicao 10
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    resultado = trazMemo(74)
    
    return resultado
    
# ========================================== GEOMETRIA ESPACIAL ======================================================
def cubArea(num1):
    #6a^2
    umaInstrucao = instLevaPMemo(multip(num1,num1), 14)#leva o valor l^2 da soma pra posicao 14
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0= trazMemo(14)

    umaInstrucao = instLevaPMemo(multip(ram0,6), 15)#leva o valor*6 da soma pra posicao 14
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    resultado = trazMemo(15)

    return resultado

def cubVol(num1):
    #a^3
    umaInstrucao = instLevaPMemo(pot(num1,3), 90)#leva o valor da pot pra posicao 90
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    resultado = trazMemo(90)
    return resultado

def paralVol(num1,num2,num3):
    #a*b*c
    
    umaInstrucao = instLevaPMemo(multip(num1,num2), 25)#leva o valor da multp pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(25)

    umaInstrucao = instLevaPMemo(multip(ram0,num3), 26)#leva o valor da multp pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    resultado = trazMemo(26)
    return resultado

def paralArea(num1,num2,num3):
    #2(a*b + b*c + a*c)
    ram0 = multip(num1,num2)
    ram1 = multip(num1,num3)
    ram2 = multip(num2,num3)

    ram0 = somar(ram0,ram1)
    ram0 = somar(ram0,ram2)

    ram0 = multip(2,ram0)

    umaInstrucao = instLevaPMemo(ram0, 12)#leva o valor da ram0 pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    resultado = trazMemo(12)

    return resultado

def prisVol(num1, num2):
    
    umaInstrucao = instLevaPMemo(multip(num1,num2), 12)#leva o valor da multp pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(12)

    umaInstrucao = instLevaPMemo(ram0, 5)#leva o valor ram0 pra posicao 5
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    resultado = trazMemo(5)

    return resultado

def pirVol(num1,num2):
    #a*b/3
    umaInstrucao = instLevaPMemo(prisVol(num1,num2), 12)#leva o valor pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(12)

    umaInstrucao = instLevaPMemo(div(ram0,3), 13)#leva o valor pra posicao 12
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    resultado = trazMemo(13)

    return resultado

# ========================================== MATRIZES ==================================================================
def matQuaNula(num1):
    umaInstrucao = instLevaPMemo(0, 20)#leva o valor 0 pra posicao 20
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(20)

    for i in range(num1):
        for j in range(num1):
            print(ram0,"\t", end="")
        print()

def matQuaId(num1):
    umaInstrucao = instLevaPMemo(0, 20)#leva o valor 0 pra posicao 20
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(20)

    umaInstrucao = instLevaPMemo(1, 24)#leva o valor 1 pra posicao 24

    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram1 = trazMemo(24)

    for i in range(num1):
        for j in range(num1):
            if(i==j):
                print(ram1,"\t", end="")
            else:
                print(ram0,"\t", end="")
        print()

def matQuaRand(num1):
    for i in range(num1):
        for j in range(num1):
            ram0 = trazMemo(random.randint(0, 99)) #ENDEREÇO Aleatorio
            print(ram0,"\t", end="")
        print()

def matQuaDiag(num1):
    umaInstrucao = instLevaPMemo(0, 50)#leva o valor 0 pra posicao 50
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    ram0 = trazMemo(50)

    for i in range(num1):
        for j in range(num1):
            ram1 = trazMemo(random.randint(0, 99))
            if(i==j):
                print(ram1,"\t", end="")
            else:
                print(ram0,"\t", end="")
        print()

