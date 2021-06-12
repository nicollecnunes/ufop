import random
import sys
import numpy as np

INT_MAX = sys.maxsize
RAM = [0] * 100
memoriaInstrucoes = np.empty((100, 4)) #mudar 100

def iniciaRAM():
    for i in range(100):
        RAM[i] = random.randint(0, 1000)
        #print("meu deus parece q essa ram nao tem é nada uai\n")
        
def maquina():
    PC = 0 #primeira instrução a ser processada
    opcode = INT_MAX
    while opcode != -1:
        umaInstrucao = [0,0,0,0]
        umaInstrucao = memoriaInstrucoes[PC]
        opcode = umaInstrucao[0] 
        #a "maquina interpretada" ta aqui mesmo
        if opcode == 0: #soma
            end1 = int(umaInstrucao[1])
            end2 = int(umaInstrucao[2])
            #print("end1 = {} e end2={}".format(end1, end2))
            cntRAM1 = RAM[end1]
            cntRAM2 = RAM[end2]
            soma = cntRAM1 + cntRAM2
            end3 = int(umaInstrucao[3])
            ("Somando {} com {} e obtendo {}\n".format(cntRAM1, cntRAM2, soma))
            RAM[end3] = soma        
        elif opcode == 1: #subtrai
            end1 = int(umaInstrucao[1])
            end2 = int(umaInstrucao[2])
            #print("end1 = {} e end2={}".format(end1, end2))
            cntRAM1 = RAM[end1]
            cntRAM2 = RAM[end2]
            sub = cntRAM1 - cntRAM2
            end3 = int(umaInstrucao[3])
            print("Subtraindo {} de {} e obtendo {}\n".format(cntRAM1, cntRAM2, sub))
            RAM[end3] = sub       
        elif opcode == 2: #levar pra memoria
            conteudo = int(umaInstrucao[1])
            end = int(umaInstrucao[2])
            RAM[end] = conteudo
        elif opcode == 3: #trazer
            end = int(umaInstrucao[2])
            umaInstrucao[1] = RAM[end]
        PC = PC +1

        
def montarInstAleatorias():
    umaInstrucao = [0,0,0,0]
    for i in range(99):#mudar pra 99
        umaInstrucao[0] = random.randint(0,1) #gera 0 ou 1
        umaInstrucao[1] = random.randint(0, 99)
        umaInstrucao[2] = random.randint(0, 99)
        umaInstrucao[3] = random.randint(0, 99)
        memoriaInstrucoes[i] = umaInstrucao
        #print(memoriaInstrucoes[i])
        
    umaInstrucao[0] = -1
    umaInstrucao[1] = -1
    umaInstrucao[2] = -1
    umaInstrucao[3] = -1
    memoriaInstrucoes[99] = umaInstrucao
    #print(memoriaInstrucoes[99])
    
    maquina()
        
def instSoma(end1, end2, end3):
    umaInstrucao = [0] * 4
    umaInstrucao[0] = 0 #opcode de soma
    umaInstrucao[1] = end1
    umaInstrucao[2] = end2
    umaInstrucao[3] = end3
    return umaInstrucao

def instSubt(end1, end2, end3):
    umaInstrucao = [0,0,0,0]
    umaInstrucao[0] = 1 #opcode de subtração
    umaInstrucao[1] = end1
    umaInstrucao[2] = end2
    umaInstrucao[3] = end3
    return umaInstrucao


def instLevaPMemo(x, end): 
    umaInstrucao = [0,0,0,0]
    umaInstrucao[0] = 2
    umaInstrucao[1] = x
    umaInstrucao[2] = end
    umaInstrucao[3] = -1
    return umaInstrucao


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

    umaInstrucao = instSoma(0, 1, 1) #end1 + end1 e guarda o resultado no end1
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[1] = umaInstrucao #mem. inst ficou assim:
    #0/end1/end2/end1
    #-1/-1/-1/1

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global
    
    
def subtrair(num1, num2):
    umaInstrucao = instLevaPMemo(num1, 0)
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = instLevaPMemo(num2, 1)
    memoriaInstrucoes[1] = umaInstrucao

    umaInstrucao = [-1] * 4
    memoriaInstrucoes[2] = umaInstrucao
    
    maquina()

    umaInstrucao = instSubt(0, 1, 1)
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = [-1] * 4
    memoriaInstrucoes[1] = umaInstrucao

    maquina()

def multip(num1, num2): #??
    res = 0
    for i in range(num1):
        somar(res,num2)
        res = RAM[1]
    
    umaInstrucao = instLevaPMemo(res, 1) #leva o num1 pra memoria no end 1
    memoriaInstrucoes[0] = umaInstrucao #montou 2 | res | 1 | -1 na linha 0

    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[1] = umaInstrucao # mem.inst ficou assim:
    # 2/res/1/-1
    #-1/-1/-1/-1     

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global

#principal
op = INT_MAX
iniciaRAM()

print("+-+-+-+-+-+-+-+ +-+-+-+")
print("|M|A|Q|U|I|N|A| |N|I|C|")
print("+-+-+-+-+-+-+-+ +-+-+-+\n")

print("1) Instruções Aleatorias")
print("2) Soma")
print("3) Subtração")
print("4) Multiplicação")

print("-1) Sair\n")


while op != -1:
        op = int(input("Digite a opção desejada: "))
        iniciaRAM()
        if op == 1:
            montarInstAleatorias()
            maquina()
        elif op == 2:
            num1 = int(input("Digite o primeiro valor: "))
            num2 = int(input("Digite o segundo valor: "))
            somar(num1, num2)
            print("Soma de {:.0f} + {:.0f} = {}".format(num1, num2,RAM[1]))
        elif op == 3:
            num1 = int(input("Digite o minuendo: "))
            num2 = int(input("Digite o subtraendo: "))
            subtrair(num1, num2)
            print("Subtração de {:.0f} - {:.0f} = {}".format(num1, num2,RAM[1]))
        elif op==4:
            num1 = int(input("Digite o multiplicando (de preferência  o menor número): "))
            num2 = int(input("Digite o multiplicador: "))
            multip(num1, num2)
            print("Multiplicação de {:.0f} x {:.0f} = {}".format(num1, num2,RAM[1]))
        else:
            if op != -1: print("Opção Inválida!\n")
            continue

print("Finalizando a máquina...")