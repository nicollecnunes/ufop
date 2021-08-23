import random
from MMU import MMU
from Endereco import Endereco
from Instrucao import Instrucao
from BlocoMemoria import BlocoMemoria

class TP2_sala_de_aula_interrupcoes:
    
    tamanhoHD: int = 1000
    tamanhoRAM: int = 1000
    tamanhoCache1: int = 16
    tamanhoCache2: int = 32
    tamanhoPrograma: int = 10001
    tamanhoProgramaTI: int = 101
    qdePalavrasBloco: int = 4

    memoriaInstrucoes: list = []
    ram: list = []
    cache1: list = []
    cache2: list = []

    custo: int = 0
    missC1: int = 0
    hitC1: int = 0
    missC2: int = 0
    hitC2: int = 0

    def montarCacheVazia(self,tamanho: int, qqCache: list) -> None:
        for i in range(tamanho):
            aux = BlocoMemoria()
            aux.endBlock = -(2**31-1)

            qqCache.append(aux)

    def montarRam(self) -> None:
        for i in range(self.tamanhoRAM):
            aux = BlocoMemoria()
            aux.endBlock = i
            palavras = []
            for j in range(self.qdePalavrasBloco):
                palavras.append(random.randint(0,999999))
            aux.palavra = palavras
            self.ram.append(aux)
    
    def montarInstrucaoGerador(self, nome: str, tamanho: int) -> None:

        with open(nome+'.txt', 'r') as reader:
            line = reader.readline()
            umaInstrucao = None
            while(line!=""):
                
                palavras = line.split(":")
                umaInstrucao = Instrucao()

                umaInstrucao.opcode = int(palavras[0])

                e1 = Endereco()
                e1_endBlock = int(palavras[1])
                e1_endPalavra = int(palavras[2])
                e1_endPalavra = e1_endPalavra%4
                e1.endBlock = e1_endBlock
                e1.endPalavra = e1_endPalavra
                umaInstrucao.add1 = e1

                e2 = Endereco()
                e2_endBlock = int(palavras[3])
                e2_endPalavra = int(palavras[4])
                e2_endPalavra = e2_endPalavra%4
                e2.endBlock = e2_endBlock
                e2.endPalavra = e2_endPalavra
                umaInstrucao.add2 = e2

                e3 = Endereco()
                e3_endBlock = int(palavras[5])
                e3_endPalavra = int(palavras[6])
                e3_endPalavra = e3_endPalavra%4
                e3.endBlock = e3_endBlock
                e3.endPalavra = e3_endPalavra
                umaInstrucao.add3 = e3

                self.memoriaInstrucoes.append(umaInstrucao)
                line = reader.readline()
            umaInstrucao = Instrucao()
            umaInstrucao.opcode = -1

            self.memoriaInstrucoes.append(umaInstrucao)

    def maquina(self, PC: int, programa: str) -> None:
        opcode = (2**31)-1

        while(opcode!=1):
            
            umaInstrucao = self.memoriaInstrucoes[PC]
            opcode = umaInstrucao.opcode

            if(opcode!=-1):
                dadoMemoriaAdd1 = MMU.buscarNasMemorias(umaInstrucao.add1, self.ram, self.cache1, self.cache2)
                dadoMemoriaAdd2 = MMU.buscarNasMemorias(umaInstrucao.add2, self.ram, self.cache1, self.cache2)
                dadoMemoriaAdd3 = MMU.buscarNasMemorias(umaInstrucao.add3, self.ram, self.cache1, self.cache2)

                self.custo += dadoMemoriaAdd1.custo
                self.custo += dadoMemoriaAdd2.custo
                self.custo += dadoMemoriaAdd3.custo

                if(dadoMemoriaAdd1.cacheHit == 1):
                    self.hitC1+=1
                elif(dadoMemoriaAdd1.cacheHit == 2):
                    self.missC1+=1
                    self.hitC2+=1
                elif(dadoMemoriaAdd1.cacheHit == 3):
                    self.missC1+=1
                    self.missC2+=1

                if(dadoMemoriaAdd2.cacheHit == 1):
                    self.hitC1+=1
                elif(dadoMemoriaAdd2.cacheHit == 2):
                    self.missC1+=1
                    self.hitC2+=1
                elif(dadoMemoriaAdd2.cacheHit == 3):
                    self.missC1+=1
                    self.missC2+=1

                if(dadoMemoriaAdd3.cacheHit == 1):
                    self.hitC1+=1
                elif(dadoMemoriaAdd3.cacheHit == 2):
                    self.missC1+=1
                    self.hitC2+=1
                elif(dadoMemoriaAdd3.cacheHit == 3):
                    self.missC1+=1
                    self.missC2+=1

                print("Custo até o momento do programa em execução: ",self.custo)
                print("Hits e Misses até o momento - C1 hit | C1 miss | C2 hit | C2 miss: ",self.hitC1," | ",self.missC1," | ",self.hitC2," | ",self.missC2)

                if(opcode == 0):
                    print("Não há demanda por levar dados externos para as memórias")
                    if(programa == "programa"):
                        #nexInt(4) = 0<=x<4 = 0-3
                        #randInt(3) = 0<=x<=3 = 0-3
                        cache = random.randint(0,3)
                        if(cache==0):
                            print()
                            print("INICIO - TRATADOR DE INTERRUPÇÃO")
                            self.montarInstrucaoGerador("tratador_interrupcao", self.tamanhoProgramaTI)
                            self.maquina(0, "tratador_interrupcao")
                            print("FIM - TRATADOR DE INTERRUPÇÃO")
                            print()

                            self.montarInstrucaoGerador("programa", self.tamanhoPrograma)
                
                elif(opcode == 1):
                    conteudo1 = dadoMemoriaAdd1.palavra[umaInstrucao.add1.endPalavra]
                    conteudo2 = dadoMemoriaAdd2.palavra[umaInstrucao.add2.endPalavra]
                    soma = conteudo1 + conteudo2

                    dadoMemoriaAdd3.palavra[umaInstrucao.add3.endPalavra] = soma
                    dadoMemoriaAdd3.atualizado = True

                    print("somando ",soma)
                    
                elif(opcode == 2):
                    conteudo1 = dadoMemoriaAdd1.palavra[umaInstrucao.add1.endPalavra]
                    conteudo2 = dadoMemoriaAdd2.palavra[umaInstrucao.add2.endPalavra]
                    sub = conteudo1 - conteudo2

                    dadoMemoriaAdd3.palavra[umaInstrucao.add3.endPalavra] = sub
                    dadoMemoriaAdd3.atualizado = True

                    print("subtraindo ",sub)
            
                PC+=1
            
            if(programa == "programa"):
                #nexInt(4) = 0<=x<4 = 0-3
                #randInt(3) = 0<=x<=3 = 0-3
                cache = random.randint(0,3)
                if(cache==0):
                    print()
                    print("INICIO - TRATADOR DE INTERRUPÇÃO")
                    self.montarInstrucaoGerador("tratador_interrupcao", self.tamanhoProgramaTI)
                    self.maquina(0, "tratador_interrupcao")
                    print("FIM - TRATADOR DE INTERRUPÇÃO")
                    print()

                    self.montarInstrucaoGerador("programa", self.tamanhoPrograma)
        
        print("Custo até o momento do programa em execução: ",self.custo)
        print("Hits e Misses até o momento - C1 hit | C1 miss | C2 hit | C2 miss: ",self.hitC1," | ",self.missC1," | ",self.hitC2," | ",self.missC2)

    def __init__(self):
        self.montarRam()
        self.montarCacheVazia(self.tamanhoCache1, self.cache1)
        self.montarCacheVazia(self.tamanhoCache2, self.cache2)
        self.montarInstrucaoGerador("programa", self.tamanhoPrograma)
        
        self.maquina(0, "programa")
        
        print("terminou")


TP2_sala_de_aula_interrupcoes()