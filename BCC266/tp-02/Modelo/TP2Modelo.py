import random
import sys
from MMU import MMU
from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from Instrucao import Instrucao

class TP2:

    tamanhoRAM: int = 1000 #quantidade de bloco
    tamanhoCache1: int = 8
    tamanhoCache2: int = 16
    tamanhoCache3: int = 32
    tamanhoPrograma: int = 10001
    qdePalavrasBloco: int = 4

    memoriaInstrucoes: list = []
    RAM: list = []
    cache1: list = []
    cache2: list = []
    cache3: list = []

    #Registradores:
    opcode: int = 0
    PC: int = 0
    custo: int = 0
    #Caches 1 e 2, HIT e MISS
    missC1: int = 0
    hitC1: int = 0

    missC2: int = 0
    hitC2: int = 0

    missC3: int = 0
    hitC3: int = 0

    hitRAM: int = 0

    def maquina(self, PC: int, programa: str):
        opcode = 0

        while(opcode!=-1):
            umaInstrucao = self.memoriaInstrucoes[PC]
            opcode = umaInstrucao.opcode

            if(opcode!=-1):
                dadoMemoriaAdd1 = MMU.buscarNasMemorias(umaInstrucao.add1, self.RAM, self.cache1, self.cache2)
                dadoMemoriaAdd2 = MMU.buscarNasMemorias(umaInstrucao.add2, self.RAM, self.cache1, self.cache2)
                dadoMemoriaAdd3 = MMU.buscarNasMemorias(umaInstrucao.add3, self.RAM, self.cache1, self.cache2)

                self.custo += dadoMemoriaAdd1.custo
                self.custo += dadoMemoriaAdd2.custo
                self.custo += dadoMemoriaAdd3.custo

                if(dadoMemoriaAdd1.cacheHit == 1):
                    self.hitC1 += 1
                elif(dadoMemoriaAdd1.cacheHit == 2):
                    self.missC1 += 1 
                    self.hitC2 += 1
                elif(dadoMemoriaAdd1.cacheHit == 3):
                    self.missC1 += 1
                    self.missC2 += 1

                #endereco 2 
                if(dadoMemoriaAdd2.cacheHit == 1):
                    self.hitC1 += 1
                elif(dadoMemoriaAdd2.cacheHit == 2):
                    self.missC1 += 1 
                    self.hitC2 += 1
                elif(dadoMemoriaAdd2.cacheHit == 3):
                    self.missC1 += 1
                    self.missC2 += 1

                #endereco 3
                if(dadoMemoriaAdd3.cacheHit == 1):
                    self.hitC1 += 1
                elif(dadoMemoriaAdd3.cacheHit == 2):
                    self.missC1 += 1 
                    self.hitC2 += 1
                elif(dadoMemoriaAdd3.cacheHit == 3):
                    self.missC1 += 1
                    self.missC2 += 1
                
                print("Custo ate o momento do programa em execucao: ", self.custo)
                print("Hits e Misses ate o momento - C1 hit: {} | C1 miss: {} | C2 hit: {} | C2 miss: {}".format(self.hitC1, self.missC1, self.hitC2, self.missC2))

                #Levar para Cache1 dados externos
                if (opcode == 0):
                    print("Nao ha demanda para levar dados")
                    break
                elif(opcode==1):
                    #SOMA
                    conteudo1 = dadoMemoriaAdd1.palavra[umaInstrucao.add1.endPalavra]
                    conteudo2 = dadoMemoriaAdd2.palavra[umaInstrucao.add2.endPalavra]
                    soma = conteudo1 + conteudo2

                    #SALVANDO NA CACHE1
                    dadoMemoriaAdd3.palavra[umaInstrucao.add3.endPalavra] = soma
                    dadoMemoriaAdd3.atualizado = True

                    #print("SOMANDO {} + {} = {}".format(conteudo1, conteudo2, soma))
                elif(opcode==2):
                    #SUBTRACAO
                    conteudo1 = dadoMemoriaAdd1.palavra[umaInstrucao.add1.endPalavra]
                    conteudo2 = dadoMemoriaAdd2.palavra[umaInstrucao.add2.endPalavra]
                    sub = conteudo1 - conteudo2

                    #SALVANDO NA CACHE1
                    dadoMemoriaAdd3.palavra[umaInstrucao.add3.endPalavra] = sub
                    dadoMemoriaAdd3.atualizado = True

                    #print("SUBTRAINDO {} - {} = {}".format(conteudo1, conteudo2, sub))

                PC = PC +1

        print("Custo ate o momento do programa em execucao: ", self.custo)
        print("Hits e Misses ate o momento - C1 hit: {} | C1 miss: {} | C2 hit: {} | C2 miss: {}".format(self.hitC1, self.missC1, self.hitC2, self.missC2))

    def montarCacheComDados(self, tamanho:int, tipoCache: int):
        for i in range(tamanho):
            aux = BlocoMemoria()
            #FORÇANDO FICAR VAZIA
            aux.endBlock = -sys.maxsize- 1
            palavras = []
            for j in range(self.qdePalavrasBloco):
                palavras.append(random.randint(0, 999999))
            aux.palavra = palavras
            if(tipoCache == 1 ):
                self.cache1[i] = aux
            elif(tipoCache == 2):
                self.cache2[i] = aux

    def montarCacheVazia(self, tamanho: int, qqCache: list):
        for i in range (tamanho):
            aux = BlocoMemoria()
            aux.endBlock = -sys.maxsize - 1
            qqCache.append(aux)

    def montarRam(self):
        for i in range(self.tamanhoRAM):
            aux = BlocoMemoria()
            aux.endBlock = i
            palavras = []
            for j in range(self.qdePalavrasBloco):
                palavras.append(random.randint(0, 999999))
            aux.palavra = palavras
            self.RAM.append(aux)

    def montarProgramaGerador(self, nome:str, tamanho:int):
        
        with open(nome + ".txt", 'r') as reader:
            line = reader.readline()
            umaInstrucao = None
            while(line!=""):
                palavras = line.split(":")
                umaInstrucao = Instrucao()

                umaInstrucao.opcode = int(palavras[0])
                
                e1 = Endereco()
                e1.endBlock = int(palavras[1])
                e1.endPalavra = int(palavras[2])
                umaInstrucao.add1 = e1

                e2 = Endereco()
                e2.endBlock = int(palavras[3])
                e2.endPalavra = int(palavras[4])
                e2.endPalavra = e2.endPalavra%4
                umaInstrucao.add2 = e2

                e3 = Endereco()
                e3.endBlock = int(palavras[5])
                e3.endPalavra = int(palavras[6])
                e3.endPalavra = e3.endPalavra%4
                umaInstrucao.add3 = e3

                self.memoriaInstrucoes.append(umaInstrucao)
                line = reader.readline()

            umaInstrucao = Instrucao()
            umaInstrucao.opcode = -1
            
            self.memoriaInstrucoes.append(umaInstrucao) 

    def __init__(self):
        self.montarRam()
        self.montarCacheVazia(self.tamanhoCache1, self.cache1)
        self.montarCacheVazia(self.tamanhoCache2, self.cache2)
        self.montarProgramaGerador("programa", self.tamanhoPrograma)
        self.maquina(0, "programa")
        print("Terminou")
    
def main():
    TP2()

if __name__ == "__main__":
    main()
   
