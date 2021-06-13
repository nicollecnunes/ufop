import random
import sys
import numpy as np

INT_MAX = sys.maxsize
RAM = [0] * 100
retorno = 0
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
            retorno = RAM[end]
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

def TrazMemo(end):
    return(RAM[end])
    


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
    maquina()
    
    return RAM[1]
    
    
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

    umaInstrucao = [-1] * 4 #ghhalt
    memoriaInstrucoes[1] = umaInstrucao

    maquina()
    
    return RAM[1]

def multip(num1, num2): #??
    umaInstrucao = [0,0,0,0]
    
    umaInstrucao = instLevaPMemo(num1, 0)#leva o valor n1 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(0, 1)#leva o valor 0 pra posicao 1
    memoriaInstrucoes[1] = umaInstrucao
    
    for i in range(num2): #tentar criar uma funcao pra ficar aqui dentro
        umaInstrucao = instSoma(0, 1, 1) #vai montar 0 | 0 | 1 | 1
        # somar | end0 tem o num1 | end1 inicialmente tem 0 | é pra onde vai o resultado (substituir). nas outras vezes do for, ja vai reaproveitar    
        memoriaInstrucoes[i+2] = umaInstrucao #+2 pq ja usei 0 e 1
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[num2+2] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global
    
    return RAM[1]

def div(num1, num2):
    aux = num1
    umaInstrucao = [0,0,0,0]
    
    umaInstrucao = instLevaPMemo(num2, 0)#leva o valor n2 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(num1, 1)#leva o valor n1 pra posicao 1
    memoriaInstrucoes[1] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(1, 2)#leva o valor 1 pra posicao 2. vai ser o aux
    memoriaInstrucoes[2] = umaInstrucao
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[3] = umaInstrucao
    
    maquina()
    
    ram0 = 
    
    for i in range(num1): #tentar criar uma funcao pra ficar aqui dentro
        umaInstrucao = instSubt(1, 0, 1) #vai montar 1 | 1 | 0 | 1
        # subt | end0 tem o num2 | end1 tem num1 | é pra onde vai o resultado (substituir). nas outras vezes do for, ja vai reaproveitar    
        memoriaInstrucoes[i+3] = umaInstrucao #+2 pq ja usei 0 e 1
        aux = subtrair(aux, num2)
        if (aux<=num2):
            break
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[num2+2] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global
    
    return 0
    

def menu():
    print("+-+-+-+-+-+-+-+ +-+-+-+")
    print("|M|A|Q|U|I|N|A| |N|I|C|")
    print("+-+-+-+-+-+-+-+ +-+-+-+\n")

    print("1) Instruções Aleatorias")
    print("2) Soma")
    print("3) Subtração")
    print("4) Multiplicação")
    print("5) Divisão")

    print("-1) Sair\n")

    
#principal
op = INT_MAX
iniciaRAM()

while op != -1:
    menu()
    op = int(input("Digite a opção desejada: "))
    iniciaRAM()
    if op == 1:
        montarInstAleatorias()
        maquina()
    elif op == 2:
        num1 = int(input("Digite o primeiro valor: "))
        num2 = int(input("Digite o segundo valor: "))
        somar(num1, num2)
        print("Soma de {:.0f} + {:.0f} = {}".format(num1, num2,somar(num1,num2)))
    elif op == 3:
        num1 = int(input("Digite o minuendo: "))
        num2 = int(input("Digite o subtraendo: "))
        subtrair(num1, num2)
        print("Subtração de {:.0f} - {:.0f} = {}".format(num1, num2,subtrair(num1, num2)))
    elif op==4:
        num1 = int(input("Digite o multiplicando (de preferência  o menor número): "))
        num2 = int(input("Digite o multiplicador: "))
        multip(num1, num2)
        print("Multiplicação de {:.0f} x {:.0f} = {}".format(num1, num2,multip(num1, num2)))
    elif op==5:
        num1 = int(input("Digite o dividendo: "))
        num2 = int(input("Digite o divisor: "))
        div(num1, num2)
        print("Divisão de {:.0f} : {:.0f} = {}".format(num1, num2,div(num1, num2)))
        
    else:
        if op != -1: print("Opção Inválida!\n")
        continue
    print("\n\n")
print("Finalizando a máquina...")