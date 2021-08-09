import tp01

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
op = 0
tp01.iniciaRAM()
menu()

while op != -1:
    op = int(input("Digite a opção desejada: "))
    tp01.iniciaRAM()
    if op == 0:
        tp01.montarInstAleatorias()
        tp01.maquina()
    elif op == 1:
        print("\n1) Soma")
        num1 = int(input("Digite o primeiro valor: "))
        num2 = int(input("Digite o segundo valor: "))
        print("Soma de {} + {} = {}".format(num1, num2, tp01.somar(num1,num2)))
    elif op == 2:
        print("\n2) Subtração")
        num1 = int(input("Digite o minuendo: "))
        num2 = int(input("Digite o subtraendo: "))
        print("Subtração de {} - {} = {}".format(num1, num2, tp01.subtrair(num1, num2)))
    elif op==3:
        print("\n3) Multiplicação")
        num1 = int(input("Digite o multiplicando: "))
        num2 = int(input("Digite o multiplicador: "))
        if(abs(num1)>=abs(num2)):
            print("Multiplicação de {} x {} = {}".format(num1, num2, tp01.multip(num1, num2)))
        else:
            print("Multiplicação de {} x {} = {}".format(num1, num2, tp01.multip(num2, num1)))
    elif op==4:
        print("\n4) Divisão")
        num1 = int(input("Digite o dividendo: "))
        num2 = int(input("Digite o divisor: "))
        print("Divisão de {} : {} = {}".format(num1, num2, tp01.div(num1, num2)))
    elif op ==5:
        print("\n5) Potenciação")
        num1 = int(input("Digite a base: "))
        num2 = int(input("Digite o expoente: "))
        print("Potência de {} ^ {} = {}".format(num1, num2, tp01.pot(num1, num2)))
    elif op==6:
        print("\n6) Raiz Quadrada de Quadrados Perfeitos")
        num1 = int(input("Digite o radicando: "))
        print("Raiz quadrada de {} = {}".format(num1, tp01.raizq(num1)))
    elif op==7:
        print("\n7) Fatorial")
        num1 = int(input("Digite o fatoriando: "))
        print("Fatorial de {} = {}".format(num1, tp01.fat(num1)))
    elif op ==8:
        print("\n8) Área de Quadrado")
        num1 = int(input("Digite a medida do lado: "))
        print("Área de Quadrado de lado {}U.C. = {}U.A.".format(num1, tp01.quadrArea(num1)))
    elif op ==9:
        print("\n9) Área de Retângulo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Retângulo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2, tp01.retArea(num1,num2)))
    elif op ==10:
        print("\n10) Área de Trigângulo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Triângulo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2, tp01.triArea(num1, num2)))
    elif op ==11:
        print("\n11) Área de Losango")
        num1 = int(input("Digite a diagonal maior: "))
        num2 = int(input("Digite a diagonal menor: "))
        print("Área de Losango de D {}U.C. x d {}U.C. = {}U.A.".format(num1, num2, tp01.losangArea(num1,num2)))
    elif op ==12:
        print("\n11) Área de Trapézio")
        num1 = int(input("Digite a base maior: "))
        num2 = int(input("Digite a base menor: "))
        num3 = int(input("Digite a altura: "))
        print("Área de Trapézio de B {}U.C. x b {}U.C. x h {}U.C. = {}U.A.".format(num1, num2, num3, tp01.trapezArea(num1, num2, num3)))
    elif op ==13:
        print("\n13) Área de Paralelogramo")
        num1 = int(input("Digite a medida da base: "))
        num2 = int(input("Digite a medida da altura: "))
        print("Área de Paralelogramo de base {}U.C. x altura {}U.C. = {}U.A.".format(num1, num2,  tp01.paralelArea(num1, num2)))
    elif op ==14:
        print("\n14) Área de Cubo")
        num1 = int(input("Digite a medida da aresta: "))
        print("Área de cubo de aresta {}U.C = {}U.V.".format(num1, tp01.cubArea(num1)))
    elif op ==15:
        print("\n15) Volume de Cubo")
        num1 = int(input("Digite a medida da aresta: "))
        print("Volume de cubo de aresta {}U.C = {}U.V.".format(num1, tp01.cubVol(num1)))
    elif op ==16:
        print("\n16) Área de Paralelepípedo")
        num1 = int(input("Digite a medida da aresta A: "))
        num2 = int(input("Digite a medida da aresta B: "))
        num3 = int(input("Digite a medida da aresta C: "))
        print("Área de Paralelepípedo de arestas {} x {} x {}U.C = {}U.V.".format(num1,num2,num3, tp01.paralArea(num1,num2,num3)))
    elif op ==17:
        print("\n17) Volume de Paralelepípedo")
        num1 = int(input("Digite a medida da aresta A: "))
        num2 = int(input("Digite a medida da aresta B: "))
        num3 = int(input("Digite a medida da aresta C: "))
        print("Volume de Paralelepípedo de arestas {} x {} x {}U.C = {}U.V.".format(num1,num2,num3, tp01.paralVol(num1,num2,num3)))
    elif op == 18:
        print("18) Volume de Prisma")
        num1 = int(input("Digite a área da base: "))
        num1 = int(input("Digite a altura: "))
        print("Volume de Prisma de área da base {} x altura {} = {}U.V.".format(num1,num2, tp01.prisVol(num1,num2)))
    elif op == 19:
        print("19) Volume de Pirâmide")
        num1 = int(input("Digite a área da base: "))
        num2 = int(input("Digite a altura: "))
        print("Volume de Pirâmide de área da base {} x altura {} = {}U.V.".format(num1,num2, tp01.pirVol(num1,num2)))
    elif op==20:
        print("20) Matriz Nula AxA")
        num1 = int(input("Digite o valor de A: "))
        tp01.matQuaNula(num1)
    elif op==21:
        print("20) Matriz Identidade AxA")
        num1 = int(input("Digite o valor de A: "))
        tp01.matQuaId(num1)
    elif op==22:
        print("21) Matriz Aleatória AxA")
        num1 = int(input("Digite o valor de A: "))
        tp01.matQuaRand(num1)
    elif op==23:
        print("23) Matriz Diagonal Aleatória AxA")
        num1 = int(input("Digite o valor de A: "))
        tp01.matQuaDiag(num1)
    elif op ==-2:
        menu()
    else:
        if op != -1:
            print("Opção Inválida!\n")
        continue
    print("\n\n")
print("Finalizando a máquina...")
