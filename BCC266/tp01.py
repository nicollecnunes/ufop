import random
import sys
import numpy as np

INT_MAX = sys.maxsize
RAM = [0] * 100
retorno = 0
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
    
    end = umaInstrucao[2]
    res = RAM[end]
    return res


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
    

    for i in range(abs(num2)): #tentar criar uma funcao pra ficar aqui dentro
        umaInstrucao = [0,0,1,1] #vai montar 0 | 0 | 1 | 1
        #print(i)
        # somar | end0 tem o num1 | end1 inicialmente tem 0 | é pra onde vai o resultado (substituir). nas outras vezes do for, ja vai reaproveitar    
        memoriaInstrucoes[i+2] = umaInstrucao #+2 pq ja usei 0 e 1
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[num2+2] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina()

    resultado = trazMemo(1)
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
        memoriaInstrucoes[0] = umaInstrucao
        
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
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    ram0 = trazMemo(0)
    
    for i in range(1,num1+1): 
        ram0 = multip(ram0, i)
        print(ram0)
        
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
    umaInstrucao = instLevaPMemo(pot(num1,3), 90)#leva o valor da soma pra posicao 90
    memoriaInstrucoes[0] = umaInstrucao

    maquinaInt(umaInstrucao)

    resultado = trazMemo(90)
    return resultado

def paralVol(num1,num2,num3):
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

def menu():
    print("\t\t+-+-+-+-+-+-+-+ +-+-+-+")
    print("\t\t|M|A|Q|U|I|N|A| |N|I|C|")
    print("\t\t+-+-+-+-+-+-+-+ +-+-+-+\n")
    
    print("============= Operações: Sem Sentido =================")
    print("0) Instruções Aleatorias\n")
    
    print("============= Operações: Matemática Básica ===========")
    print("1) Soma")
    print("2) Subtração")
    print("3) Multiplicação")
    print("4) Divisão")
    print("5) Potenciação")
    print("6) Raiz Quadrada")
    print("7) Fatorial\n")
    
    print("============= Operações: Geometria Plana ==============")
    print("8) Área de Quadrado")
    print("9) Área de Retângulo")
    print("10) Área de Trigângulo")
    print("11) Área de Losango")
    print("12) Área de Trapézio")
    print("13) Área de Paralelogramo\n")

    print("============= Operações: Geometria Espacial ============")
    print("14) Área de Cubo")
    print("15) Volume de Cubo")
    print("16) Área de Paralelepípedo")
    print("17) Volume de Paralelepípedo")
    print("18) Volume de Prisma")
    print("19) Volume de Pirâmide\n")


    print("============= Impressões: Matrizes =====================")
    print("20) Matriz Nula AxA")
    print("21) Matriz Identidade AxA")
    print("22) Matriz Aleatória AxA")
    print("23) Matriz Diagonal Aleatória AxA\n")
 
    
    print("============= Opções da Máquina ========================")
    print("-1) Sair")
    print("-2) Imprimir o Menu novamente\n")

    
#principal
op = INT_MAX
iniciaRAM()
menu()

while op != -1:
    op = int(input("Digite a opção desejada: "))
    iniciaRAM()
    if op == 0:
        montarInstAleatorias()
        maquina()
    elif op == 1:
        print("\n1) Soma")
        num1 = int(input("Digite o primeiro valor: "))
        num2 = int(input("Digite o segundo valor: "))
        print("Soma de {} + {} = {}".format(num1, num2, somar(num1,num2)))
    elif op == 2:
        print("\n2) Subtração")
        num1 = int(input("Digite o minuendo: "))
        num2 = int(input("Digite o subtraendo: "))
        print("Subtração de {} - {} = {}".format(num1, num2, subtrair(num1, num2)))
    elif op==3:
        print("\n3) Multiplicação")
        num1 = int(input("Digite o multiplicando: "))
        num2 = int(input("Digite o multiplicador: "))
        if(abs(num1)>=abs(num2)):
            print("Multiplicação de {} x {} = {}".format(num1, num2, multip(num1, num2)))
        else:
            print("Multiplicação de {} x {} = {}".format(num1, num2, multip(num2, num1)))
    elif op==4:
        print("\n4) Divisão")
        num1 = int(input("Digite o dividendo: "))
        num2 = int(input("Digite o divisor: "))
        print("Divisão de {} : {} = {}".format(num1, num2, div(num1, num2)))
    elif op ==5:
        print("\n5) Potenciação")
        num1 = int(input("Digite a base: "))
        num2 = int(input("Digite o expoente: "))
        print("Potência de {} ^ {} = {}".format(num1, num2, pot(num1, num2)))
    elif op==6:
        print("\n6) Raiz Quadrada de Quadrados Perfeitos")
        num1 = int(input("Digite o radicando: "))
        print("Raiz quadrada de {} = {}".format(num1, raizq(num1)))
    elif op==7:
        print("\n7) Fatorial")
        num1 = int(input("Digite o fatoriando: "))
        print("Fatorial de {} = {}".format(num1, fat(num1)))
    elif op ==8:
        print("\n8) Área de Quadrado")
        num1 = int(input("Digite a medida do lado: "))
        print("Área de Quadrado de lado {}U.C. = {}U.A.".format(num1, quadrArea(num1)))
    elif op ==9:
        print("\n9) Área de Retângulo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Retângulo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2, retArea(num1,num2)))
    elif op ==10:
        print("\n10) Área de Trigângulo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Triângulo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2, triArea(num1, num2)))
    elif op ==11:
        print("\n11) Área de Losango")
        num1 = int(input("Digite a diagonal maior: "))
        num2 = int(input("Digite a diagonal menor: "))
        print("Área de Losango de D {}U.C. x d {}U.C. = {}U.A.".format(num1, num2, losangArea(num1,num2)))
    elif op ==12:
        print("\n11) Área de Trapézio")
        num1 = int(input("Digite a base maior: "))
        num2 = int(input("Digite a base menor: "))
        num3 = int(input("Digite a altura: "))
        print("Área de Trapézio de B {}U.C. x b {}U.C. x h {}U.C. = {}U.A.".format(num1, num2, num3, trapezArea(num1, num2, num3)))
    elif op ==13:
        print("\n13) Área de Paralelogramo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Paralelogramo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2,  paralelArea(num1, num2)))
    elif op ==14:
        print("\n14) Área de Cubo")
        num1 = int(input("Digite a medida da aresta: "))
        print("Área de cubo de aresta {}U.C = {}U.V.".format(num1, cubArea(num1)))
    elif op ==15:
        print("\n15) Volume de Cubo")
        num1 = int(input("Digite a medida da aresta: "))
        print("Volume de cubo de aresta {}U.C = {}U.V.".format(num1, cubVol(num1)))
    elif op ==16:
        print("\n16) Área de Paralelepípedo")
        num1 = int(input("Digite a medida da aresta A: "))
        num2 = int(input("Digite a medida da aresta B: "))
        num3 = int(input("Digite a medida da aresta C: "))
        print("Área de Paralelepípedo de arestas {} x {} x {}U.C = {}U.V.".format(num1,num2,num3, paralArea(num1,num2,num3)))
    elif op ==17:
        print("\n17) Volume de Paralelepípedo")
        num1 = int(input("Digite a medida da aresta A: "))
        num2 = int(input("Digite a medida da aresta B: "))
        num3 = int(input("Digite a medida da aresta C: "))
        print("Volume de Paralelepípedo de arestas {} x {} x {}U.C = {}U.V.".format(num1,num2,num3, paralVol(num1,num2,num3)))
    elif op == 18:
        print("18) Volume de Prisma")
        num1 = int(input("Digite a área da base: "))
        num1 = int(input("Digite a altura: "))
        print("Volume de Prisma de área da base {} x altura {} = {}U.V.".format(num1,num2, prisVol(num1,num2)))
    elif op == 19:
        print("19) Volume de Pirâmide")
        num1 = int(input("Digite a área da base: "))
        num2 = int(input("Digite a altura: "))
        print("Volume de Pirâmide de área da base {} x altura {} = {}U.V.".format(num1,num2, pirVol(num1,num2)))
    elif op==20:
        print("20) Matriz Nula AxA")
        num1 = int(input("Digite o valor de A: "))
        matQuaNula(num1)
    elif op==21:
        print("20) Matriz Identidade AxA")
        num1 = int(input("Digite o valor de A: "))
        matQuaId(num1)
    elif op==22:
        print("21) Matriz Aleatória AxA")
        num1 = int(input("Digite o valor de A: "))
        matQuaRand(num1)
    elif op==23:
        print("23) Matriz Diagonal Aleatória AxA")
        num1 = int(input("Digite o valor de A: "))
        matQuaDiag(num1)
    elif op ==-2:
        menu()
    else:
        if op != -1:
            print("Opção Inválida!\n")
        continue
    print("\n\n")
print("Finalizando a máquina...")