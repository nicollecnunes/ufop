# Nicolle Canuto Nunes
# 20.1.4022
# BCC266

import random
import sys

INT_MAX = sys.maxsize
memoriaInstrucoes = []
RAM = [0] * 100

def iniciaRam():
    for i in range(100):
        RAM[i] = random.randint(0, 1001)
        
        
        
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
            constructorAddInstructionsProgram(num1, num2)
            print("Soma de {:.2f} + {:.2f} = ".format(num1, num2))
        elif op == 3:
            num1 = float(input("Digite o minuendo: "))
            num2 = float(input("Digite o subtraendo: "))
            constructorSubInstructionsProgram(num1, num2)
            print("Subtração de {:.2f} - {:.2f} = ".format(num1, num2))
        else:
            if op != -1: print("Opção Inválida!\n")
            continue
        print("Resultado: {:.2f}".format(RAM[1]))