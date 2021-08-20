import random, sys, pickle
from MMU import MMU
from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from Instrucao import Instrucao
from Conjunto import Conjunto
from output import Output
from geradorInterrup import generator

class TP3:
    fileName = './instructions/instructions30-80'

    tamanhoHD: int = 1000 #quantidade de blocos do hd
    tamanhoRAM: int = 1000 #quantidade de blocos da ram
    tamanhoCache1: int = 32 #quantidade de blocos da cache1
    tamanhoCache2: int = 64 #quantidade de blocos da cache2
    tamanhoCache3: int = 128 #quantidade de blocos da cache3
    #A partir de agora as caches vão conter uma lista de conjuntos, que por sua vez contem uma lista de blocos
    tamanhoConjuntosCache1: int = 4
    tamanhoConjuntosCache2: int = 4
    tamanhoConjuntosCache3: int = 4
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

    missRAM: int = 0
    hitRAM: int = 0

    hitHD: int = 0

    output_type: int = 1
    tamanhoProgramaInterrupcao = 101

    def sincroniza(self, cache1, cache2, cache3, RAM):
        i = 0
        bloco = BlocoMemoria()
        for conj in cache1:
            for bloco in conj.blocos:
                if(bloco.atualizado):
                    RAM[i] = bloco.palavra
                    i = i + 1
        for conj in cache2:
            for bloco in conj.blocos:
                if(bloco.atualizado):
                    RAM[i] = bloco.palavra
                    i = i + 1
        for conj in cache3:
            for bloco in conj.blocos:
                if(bloco.atualizado):
                    RAM[i] = bloco.palavra
                    i = i + 1
        
                
    def maquina(self, programa):
        print("Entrei na maquina")
        PC = 0
        opcode = 0
        numInterrInternas = 0
        numInterrExternas = 0

        while(opcode!=-1):
            umaInstrucao = self.memoriaInstrucoes[PC]
            opcode = umaInstrucao.opcode

            if(opcode!=-1):
                dadoMemoriaAdd1 = MMU.buscarNasMemorias(umaInstrucao.add1, self.RAM, self.cache1, self.cache2, self.cache3)
                dadoMemoriaAdd2 = MMU.buscarNasMemorias(umaInstrucao.add2, self.RAM, self.cache1, self.cache2, self.cache3)
                dadoMemoriaAdd3 = MMU.buscarNasMemorias(umaInstrucao.add3, self.RAM, self.cache1, self.cache2, self.cache3)                
                
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
                    self.hitC3 += 1
                else:
                    self.missC1 += 1
                    self.missC2 += 1
                    self.missC3 += 1
                    self.hitRAM += 1

                #endereco 2 
                if(dadoMemoriaAdd2.cacheHit == 1):
                    self.hitC1 += 1
                elif(dadoMemoriaAdd2.cacheHit == 2):
                    self.missC1 += 1 
                    self.hitC2 += 1
                elif(dadoMemoriaAdd2.cacheHit == 3):
                    self.missC1 += 1
                    self.missC2 += 1
                    self.hitC3 += 1
                else:
                    self.missC1 += 1
                    self.missC2 += 1
                    self.missC3 += 1
                    self.hitRAM += 1
                    self.hitHD += 1

                #endereco 3
                if(dadoMemoriaAdd3.cacheHit == 1):
                    self.hitC1 += 1
                elif(dadoMemoriaAdd3.cacheHit == 2):
                    self.missC1 += 1 
                    self.hitC2 += 1
                elif(dadoMemoriaAdd3.cacheHit == 3):
                    self.missC1 += 1
                    self.missC2 += 1
                    self.hitC3 += 1
                elif(dadoMemoriaAdd3.cacheHit == 4):
                    self.missC1 += 1
                    self.missC2 += 1
                    self.missC3 += 1
                    self.hitRAM += 1
                else:
                    self.missC1 += 1
                    self.missC2 += 1
                    self.missC3 += 1
                    self.missRAM += 1

                if ((opcode == 0) and (programa=="P")):
                    chance = random.randint(0, 5) #20% de chance
                    if chance == 0:
                        numInterrInternas += 1
                        print('Iniciando Tratador de Interrupções...')

                        fileNameIntr = './interruptions/INTR'
                        tamanho = random.randint(20, self.tamanhoProgramaInterrupcao)
                        generator('./interruptions/INTR', tamanho, 10, 70)
                        self.montarProgramaGeradorComTamanho(fileNameIntr, tamanho)
                        self.maquina("I")

                        print('Finalizando Tratador de Interrupções...')
                        self.montarProgramaGerador(self.fileName)

                elif(opcode==1):
                    print(dadoMemoriaAdd1.palavra)
                    print(dadoMemoriaAdd2.palavra)
                    conteudo1 = dadoMemoriaAdd1.palavra[umaInstrucao.add1.endPalavra]
                    conteudo2 = dadoMemoriaAdd2.palavra[umaInstrucao.add2.endPalavra]
                    soma = conteudo1 + conteudo2

                    dadoMemoriaAdd3.palavra[umaInstrucao.add3.endPalavra] = soma
                    dadoMemoriaAdd3.atualizado = True

                elif(opcode==2):
                    conteudo1 = dadoMemoriaAdd1.palavra[umaInstrucao.add1.endPalavra]
                    conteudo2 = dadoMemoriaAdd2.palavra[umaInstrucao.add2.endPalavra]
                    sub = conteudo1 - conteudo2

                    dadoMemoriaAdd3.palavra[umaInstrucao.add3.endPalavra] = sub
                    dadoMemoriaAdd3.atualizado = True

                PC = PC +1

                if (programa=="P"):
                    chance = random.randint(0, 8) #12.5% de chance
                    if chance == 0:
                        numInterrExternas += 1
                        print('Iniciando Tratador de Interrupções...')

                        fileNameIntr = './interruptions/INTR'
                        tamanho = random.randint(20, self.tamanhoProgramaInterrupcao)
                        generator('./interruptions/INTR', tamanho, 10, 70)
                        self.montarProgramaGeradorComTamanho(fileNameIntr, tamanho)

                        self.maquina("I")

                        print('Finalizando Tratador de Interrupções...')
                        self.montarProgramaGerador(self.fileName)

        if (programa=="P"):
            if(self.output_type):
                Output.printResult(self.hitC1, self.missC1, self.hitC2, self.missC2, self.hitC3, self.missC3, self.hitRAM, self.custo)
            else:
                totalHits = self.hitC1 + self.hitC2 + self.hitC3 + self.hitRAM
                totalMisses = self.missC1 + self.missC2 + self.missC3    

                taxaC1 = (self.hitC1 * 100) / (self.hitC1 + self.missC1)
                taxaC2 = (self.hitC2 * 100) / (self.hitC2 + self.missC2)
                taxaC3 = (self.hitC3 * 100) / (self.hitC3 + self.missC3)
                print('Custo total do programa: {0}'.format(self.custo))
                print("===================== INFORMACOES SOBRE A MAQUINA =====================")
                print('\tCACHE1\tCACHE2\tCACHE3\t')
                print("SIZE\t{}\t{}\t{}".format(self.tamanhoCache1, self.tamanhoCache2, self.tamanhoCache3))

                print("============================ HITS & MISSES ============================")
                print('\tHIT \tMISS \t')
                print('C1\t{0}\t{1}'.format( self.hitC1, self.missC1 ))
                print('C2\t{0}\t{1}'.format( self.hitC2, self.missC2 ))
                print('C3\t{0}\t{1}'.format( self.hitC3, self.missC3 ))
                print('RAM\t{}\t-'.format(self.hitRAM))

                print("================================= TAXAS =================================")
                print('\tCACHE1\tCACHE2\tCACHE3\t')
                print("TAXA\t{:.2f}%\t{:.2f}%\t{:.2f}%".format(taxaC1, taxaC2, taxaC3))

                print('\n')
                print('Total de Hits: {0}'.format(totalHits))
                print('Total de Misses: {0}'.format(totalMisses))
        
    def montarCacheVazia(self, tamanhoBlocos: int, tamanhoConjunto: int, qqCache: list):

        #gerando a lista de conjuntos e dentro dela a de blocos
        for _ in range(tamanhoConjunto):
            conjunto = Conjunto()
            for _ in range(int(tamanhoBlocos/tamanhoConjunto)):
                aux = BlocoMemoria()
                aux.endBlock = -sys.maxsize - 1
                conjunto.blocos.append(aux)
            qqCache.append(conjunto)

    def montarRam(self):
        for i in range(self.tamanhoRAM):
            #aux = self.readFromHD(i)
            aux = BlocoMemoria()
            self.RAM.append(aux)

    def montarProgramaGerador(self, nome:str):
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

    def montarProgramaGeradorComTamanho(self, nome:str, tamanho:int):
        print("Linha 283")
        for _n in range(len(self.memoriaInstrucoes), tamanho):
            self.memoriaInstrucoes.append(Instrucao())
        
        with open(nome + ".txt", 'r') as reader:
            line = reader.readline()
            umaInstrucao = None
            for i in range(tamanho - 1):
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
            
            reader.close()

            umaInstrucao = Instrucao()
            umaInstrucao.opcode = -1
            self.memoriaInstrucoes.append(umaInstrucao)

    def readFromHD(self, endBloco):
        bloco = BlocoMemoria()
        with open('MemoriaExterna.bin', mode='rb') as f:
            line_size = int((sys.getsizeof(f.readline())-1)/2)
            f.seek(endBloco * line_size)
            line = f.readline()
            str_line = line.decode().replace('\n','').split(',')
            int_line = [int(x) for x in str_line]
            bloco.endBlock = int_line[0]
            bloco.palavra = int_line[1:]
        return bloco
    
    def __init__(self, output_type = "custom"):
        if(output_type == "normal"):
            self.output_type = 0
        elif(output_type == "custom"):
            self.output_type = 1
        self.montarRam()
        self.montarCacheVazia(self.tamanhoCache1, self.tamanhoConjuntosCache1, self.cache1)
        self.montarCacheVazia(self.tamanhoCache2, self.tamanhoConjuntosCache2, self.cache2)
        self.montarCacheVazia(self.tamanhoCache3, self.tamanhoConjuntosCache3, self.cache3)
        self.montarProgramaGerador(self.fileName)
        self.maquina("P")
        self.sincroniza(self.cache1, self.cache2, self.cache3, self.RAM)
    
def main():
    #cwd = os.getcwd()  # Get the current working directory (cwd)
    #files = os.listdir(cwd)  # Get all the files in that directory
    #print("Arquivos %r: %s" % (cwd, files))
    if(len(sys.argv)>1):
        output_type = sys.argv[1]
        TP3(output_type)
    else:
        TP3()

if __name__ == "__main__":
    main()
   
