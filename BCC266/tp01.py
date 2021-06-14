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
        #print("meu deus parece q essa ram nao tem é nada uai\n")
        
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
        RAM[end] = conteudo
    elif opcode == 3: #trazer
        end = int(umaInstrucao[2])
        retorno = RAM[end]
        
def maquina():
    PC = 0 #primeira instrução a ser processada
    opcode = INT_MAX
    while opcode != -1:
        umaInstrucao = [0,0,0,0]
        umaInstrucao = memoriaInstrucoes[PC]
        opcode = umaInstrucao[0]
        
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
    
    maquina()
        
def instSoma(end1, end2, end3):
    umaInstrucao = [0,end1,end2,end3]
    return umaInstrucao

def instSubt(end1, end2, end3):
    umaInstrucao = [1,end1,end2,end3]
    return umaInstrucao


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

    umaInstrucao = instSoma(0, 1, 1) #end1 + end1 e guarda o resultado no end1
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

    umaInstrucao = instSubt(0, 1, 1)
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = [-1] * 4 #ghhalt
    memoriaInstrucoes[1] = umaInstrucao

    maquina()
    
    resultado = trazMemo(1)
    maquinaInt(umaInstrucao)
    
    return resultado

def multip(num1, num2): #??
    umaInstrucao = [0] * 4
    
    umaInstrucao = instLevaPMemo(num1, 0)#leva o valor n1 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    umaInstrucao = instLevaPMemo(0, 1)#leva o valor 0 pra posicao 1
    memoriaInstrucoes[1] = umaInstrucao
    
    for i in range(num2): #tentar criar uma funcao pra ficar aqui dentro
        umaInstrucao = instSoma(0, 1, 1) #vai montar 0 | 0 | 1 | 1
        #print(i)
        # somar | end0 tem o num1 | end1 inicialmente tem 0 | é pra onde vai o resultado (substituir). nas outras vezes do for, ja vai reaproveitar    
        memoriaInstrucoes[i+2] = umaInstrucao #+2 pq ja usei 0 e 1
    
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[num2+2] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global
    
    resultado = trazMemo(1)
    maquinaInt(umaInstrucao)
    
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
        umaInstrucao = instSubt(1,0,1) #subtrai num1(end1) de num2(end0) e coloca no end 1
        maquinaInt(umaInstrucao)
        umaInstrucao = instSoma(2,3,3) #soma o end2+end3 e poe no end3 (resultado)
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
    print (ram0)
    
    for i in range(num2): #tentar criar uma funcao pra ficar aqui dentro
        ram0 = multip(num1, ram0)
        print(ram0)
        
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
        #print("linha 260 somando ram1: {} + i: {} ".format(ram1, i))
        ram1 = somar(ram1, i)
        #print("linha 261 somando ram2: {} + 1".format(ram2))
        ram2 = somar(ram2, 1)
        if (ram1==ram0):
            resultado = trazMemo(2)
            maquinaInt(umaInstrucao)
            
            return resultado
        elif (ram1>ram0):
            print("Não é um quadrado perfeito.")
            return "∄ em N"
        
def fat(num1):
    umaInstrucao = instLevaPMemo(1, 0)#leva o valor 1 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    ram0 = trazMemo(0)
    
    for i in range(1,num1+1): #tentar criar uma funcao pra ficar aqui dentro
        ram0 = multip(ram0, i)
        print(ram0)
        
    umaInstrucao = [0] * 4
    
    umaInstrucao = instLevaPMemo(ram0, 0)#leva o valor ram0 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
     
    umaInstrucao = [-1] * 4 #halt
    memoriaInstrucoes[1] = umaInstrucao #multiplicador pq i vai ate ele +2

    maquina() #maquina leva pra memoria. sem parametro pq e variavel global
    
    resultado = trazMemo(0)
    maquinaInt(umaInstrucao)
    
    return resultado

def trapezArea(num1, num2, num3): 
    ram0 = somar(num1,num2)
    ram0 = div(ram0, num3)
    
    umaInstrucao = instLevaPMemo(ram0, 5)#leva o valor ram0 pra posicao 0
    memoriaInstrucoes[0] = umaInstrucao
    
    maquinaInt(umaInstrucao)
    
    resultado = trazMemo(5)
    return resultado
    

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
        if(num1>=num2):
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
        print("Área de Quadrado de lado {}U.C. = {}U.A.".format(num1, multip(num1,num1)))
    elif op ==9:
        print("\n9) Área de Retângulo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Retângulo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2, multip(num1,num2)))
    elif op ==10:
        print("\n10) Área de Trigângulo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Triângulo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2, div(multip(num1,num2),2)))
    elif op ==11:
        print("\n11) Área de Losango")
        num1 = int(input("Digite a diagonal maior: "))
        num2 = int(input("Digite a diagonal menor: "))
        print("Área de Losango de D {}U.C. x d {}U.C. = {}U.A.".format(num1, num2, div(multip(num1,num2),2)))
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
        print("Área de Paralelogramo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2, multip(num1,num2)))
    elif op ==-2:
        menu()
    else:
        if op != -1:
            print("Opção Inválida!\n")
        continue
    print("\n\n")
print("Finalizando a máquina...")