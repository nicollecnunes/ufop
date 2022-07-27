
class Estoque:
    def __init__(self, qtdAtual):
        self.qtdAtual = qtdAtual
        self.qtdReposicoes = 0
        self.totalCompras = 0

    def novaCompra(self, qtdComprada):
        self.qtdAtual += qtdComprada
        self.qtdReposicoes = self.qtdReposicoes + 1
        self.totalCompras += qtdComprada
        print("Compra registrada com sucesso. Quantidade disponível: "  + str(self.qtdAtual))

    def novoGasto(self, qtdUsada):
        self.qtdAtual -= qtdUsada
        print("Gasto registrado com sucesso. Quantidade disponível: "  + str(self.qtdAtual))

    def reportUso(self):
        print("===== REPORT =====")
        if not (self.qtdReposicoes == 0):
            print("Total de reposições feitas até o momento atual: " + str(self.qtdReposicoes))
            print("Média de rolos por reposição: " + str(self.totalCompras/self.qtdReposicoes))
        print("Quantidade de rolos disponível: " + str(self.qtdAtual))

est = Estoque(50)
while True:
    print()
    print("======== CONTROLE DE ESTOQUE ========")
    print("[1] Registrar nova compra")
    print("[2] Registrar uso")
    print("[3] Imprimir report")
    print("[4] Sair")
    print(" >> ")

    opc = int(input())

    if opc == 1:
        print("Digite a quantidade da compra: ")
        print(" >> ")
        qtd = int(input())
        est.novaCompra(qtd)
    elif opc == 2:
        print("Digite a quantidade do gasto: ")
        print(" >> ")
        qtd = int(input())
        est.novoGasto(qtd)
    elif opc == 3:
        est.reportUso()
    else:
        break