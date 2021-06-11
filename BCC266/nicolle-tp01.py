# Nicolle Canuto Nunes
# 20.1.4022
# BCC266

#opcode -> o que a instrução vai fazer
#halt parar
# opcode | x | y | z
#x,y,z são ENDEREÇOS, não conteúdos 

import random
import sys

INT_MAX = sys.maxsize
memoriaInstrucoes = []
RAM = [0] * 100

def iniciaRAM():
    for i in range(100):
        RAM[i] = random.randint(0, 1001)
        

def maquina():
    PC = 0
    opcode = INT_MAX
    while opcode != -1:
        umaInstrucao = [0] * 4
        umaInstrucao = memoriaInstrucoes[PC]
        opcode = umaInstrucao[0]
        if opcode == 0:
            RAM[umaInstrucao[2]] = umaInstrucao[1]
        elif opcode == 1:
            end1 = umaInstrucao[1]
            end2 = umaInstrucao[2]
            cntRAM1 = RAM[end1]
            cntRAM2 = RAM[end2]
            soma = cntRAM1 + cntRAM2
            RAM[umaInstrucao[3]] = soma
        elif opcode == 2:
            end1 = umaInstrucao[1]
            end2 = umaInstrucao[2]
            cntRAM1 = RAM[end1]
            cntRAM2 = RAM[end2]
            sub = cntRAM1 - cntRAM2
            RAM[umaInstrucao[3]] = sub
        elif opcode == 3:
            umaInstrucao[1] = RAM[umaInstrucao[2]]
        PC += 1
        
def adicionaInstru(end1, end2, end3):
    umaInstrucao = [0] * 4
    umaInstrucao[0] = 1 #??
    umaInstrucao[1] = end1
    umaInstrucao[2] = end2
    umaInstrucao[3] = end3
    return umaInstrucao

def subInstru(end1, end2, end3):
    umaInstrucao = [0] * 4
    umaInstrucao[0] = 2 #??
    umaInstrucao[1] = end1
    umaInstrucao[2] = end2
    umaInstrucao[3] = end3
    return umaInstrucao


def levaPraMemo(x, end):
    umaInstrucao = [0] * 4 #0000
    umaInstrucao[0] = 0
    umaInstrucao[1] = x
    umaInstrucao[2] = end
    umaInstrucao[3] = -1
    return umaInstrucao


def somar(num1, num2):    
    for n in range(len(memoriaInstrucoes), 3): # 0 1 2
        memoriaInstrucoes.append(0)

    umaInstrucao = levaPraMemo(num1, 0)
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = levaPraMemo(num2, 1)
    memoriaInstrucoes[1] = umaInstrucao

    umaInstrucao = [-1] * 4
    memoriaInstrucoes[2] = umaInstrucao
    
    maquina()

    umaInstrucao = adicionaInstru(0, 1, 1) #??
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = [-1] * 4
    memoriaInstrucoes[1] = umaInstrucao

    maquina()
    
    
def subtrair(num1, num2):
    for n in range(len(memoriaInstrucoes), 3):
      memoriaInstrucoes.append(0)

    umaInstrucao = levaPraMemo(num1, 0)
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = levaPraMemo(num2, 1)
    memoriaInstrucoes[1] = umaInstrucao

    umaInstrucao = [-1] * 4
    memoriaInstrucoes[2] = umaInstrucao
    
    maquina()

    umaInstrucao = subInstru(0, 1, 1)
    memoriaInstrucoes[0] = umaInstrucao

    umaInstrucao = [-1] * 4
    memoriaInstrucoes[1] = umaInstrucao

    maquina()

    

#principal
op = INT_MAX        

print("+-+-+-+-+-+-+-+ +-+-+-+")
print("|M|A|Q|U|I|N|A| |N|I|C|")
print("+-+-+-+-+-+-+-+ +-+-+-+\n")

print("1) Instruções Aleatorias")
print("2) Soma")
print("3) Subtração")

print("-1) Sair\n")


while op != -1:
        op = int(input("Digite a opção desejada: "))
        iniciaRAM()
        if op == 1:
            ##random aqui
            maquina()
        elif op == 2:
            num1 = float(input("Digite o primeiro valor: "))
            num2 = float(input("Digite o segundo valor: "))
            somar(num1, num2)
            print("Soma de {:.2f} + {:.2f} = ".format(num1, num2))
        elif op == 3:
            num1 = float(input("Digite o minuendo: "))
            num2 = float(input("Digite o subtraendo: "))
            subtrair(num1, num2)
            print("Subtração de {:.2f} - {:.2f} = ".format(num1, num2))
        else:
            if op != -1: print("Opção Inválida!\n")
            continue
        print("{:.2f}".format(RAM[1]))
        
print("Finalizando a máquina...")
