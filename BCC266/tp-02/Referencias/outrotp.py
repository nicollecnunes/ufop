import random
import sys
from pprint import pprint
from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from Instrucao import Instrucao
from MMU2 import buscarNasMemorias

INT_MAX = sys.maxsize
INT_MIN = (sys.maxsize * -1) - 1

cachesM1 = [8, 16, 32]
cachesM2 = [32, 64, 128]
cachesM3 = [16, 64, 256]
cachesM4 = [8, 32, 128]
cachesM5 = [16, 32, 64]

tamanhoRam = 1000
tamanhoCache1 = cachesM5[0]
tamanhoCache2 = cachesM5[1]
tamanhoCache3 = cachesM5[2]
tamanhoPrograma = 10001
quantidadePalavrasBloco = 4

memoriaInstrucoes = []
RAM = [BlocoMemoria()] * tamanhoRam
cache1 = [BlocoMemoria()] * tamanhoCache1
cache2 = [BlocoMemoria()] * tamanhoCache2
cache3 = [BlocoMemoria()] * tamanhoCache3

def montarRam():
    for i in range(tamanhoRam):
        aux = BlocoMemoria()
        aux.setEndBloco(i)
        palavras = [0] * quantidadePalavrasBloco
        for j in range(quantidadePalavrasBloco):
            palavras[j] = random.randint(0, 1000000)
        aux.setPalavras(palavras)
        RAM[i] = aux

def montarCacheVazia(tamanho, qqCache):
    for i in range(tamanho):
        aux = BlocoMemoria()
        aux.setEndBloco(INT_MIN)
        qqCache[i] = aux

def montarInstrucoesProgramaAleatorio():
    for _n in range(len(memoriaInstrucoes), tamanhoPrograma):
        memoriaInstrucoes.append(Instrucao())

    for i in range(tamanhoPrograma - 1):
        umaInstrucao = Instrucao()
        umaInstrucao.setOpcode(random.randint(0, 2))

        add1 = Endereco()
        add1.setEndBloco(random.randint(0, tamanhoRam - 1))
        add1.setEndPalavra(random.randint(0, quantidadePalavrasBloco - 1))
        umaInstrucao.setAdd1(add1)

        add2 = Endereco()
        add2.setEndBloco(random.randint(0, tamanhoRam - 1))
        add2.setEndPalavra(random.randint(0, quantidadePalavrasBloco - 1))
        umaInstrucao.setAdd2(add2)

        add3 = Endereco()
        add3.setEndBloco(random.randint(0, tamanhoRam - 1))
        add3.setEndPalavra(random.randint(0, quantidadePalavrasBloco - 1))
        umaInstrucao.setAdd3(add3)

        memoriaInstrucoes[i] = umaInstrucao
    
    umaInstrucao = Instrucao()
    umaInstrucao.setOpcode(-1)

    memoriaInstrucoes[tamanhoPrograma-1] = umaInstrucao


def montarInstrucaoGerador():
    for _n in range(len(memoriaInstrucoes), tamanhoPrograma):
        memoriaInstrucoes.append(Instrucao())
    
    try:
        file = open('instrucoes.txt', 'r')
        file.readline()
        fileLines = file.read().split('\n')
        for i in range(tamanhoPrograma - 1):
            palavras = [0] * 7
            palavras = fileLines[i].split(' ')
            
            umaInstrucao = Instrucao()
            umaInstrucao.setOpcode(int(palavras[0]))

            e1 = Endereco()
            e1_endBloco = int(palavras[1])
            e1_endPalavra = int(palavras[2])
            e1.setEndBloco(e1_endBloco)
            e1.setEndPalavra(e1_endPalavra)
            umaInstrucao.setAdd1(e1)

            e2 = Endereco()
            e2_endBloco = int(palavras[3])
            e2_endPalavra = int(palavras[4])
            e2.setEndBloco(e2_endBloco)
            e2.setEndPalavra(e2_endPalavra)
            umaInstrucao.setAdd2(e2)

            e3 = Endereco()
            e3_endBloco = int(palavras[5])
            e3_endPalavra = int(palavras[6])
            e3.setEndBloco(e3_endBloco)
            e3.setEndPalavra(e3_endPalavra)
            umaInstrucao.setAdd3(e3)

            memoriaInstrucoes[i] = umaInstrucao

        file.close()

        umaInstrucao = Instrucao()
        umaInstrucao.setOpcode(-1)
        memoriaInstrucoes[tamanhoPrograma - 1] = umaInstrucao

    except NameError:
        print("Erro ao abrir arquivo!")

def maquina():
    PC = 0
    opcode = INT_MAX
    custo = 0
    hitC1 = 0
    missC1 = 0
    hitC2 = 0
    missC2 = 0
    hitC3 = 0
    missC3 = 0

    totalMisses = 0
    totalHits = 0

    while opcode != -1:
        umaInstrucao = Instrucao()
        umaInstrucao = memoriaInstrucoes[PC]
        opcode = umaInstrucao.getOpcode()

        if opcode != -1:
            dadoMemoriaAdd1 = buscarNasMemorias(umaInstrucao.getAdd1(), RAM, cache1, cache2, cache3)
            dadoMemoriaAdd2 = buscarNasMemorias(umaInstrucao.getAdd2(), RAM, cache1, cache2, cache3)
            dadoMemoriaAdd3 = buscarNasMemorias(umaInstrucao.getAdd3(), RAM, cache1, cache2, cache3)

            custo += dadoMemoriaAdd1.getCusto()
            custo += dadoMemoriaAdd2.getCusto()
            custo += dadoMemoriaAdd3.getCusto()

            if dadoMemoriaAdd1.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 2:
                hitC2 += 1
                missC1 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 3:
                hitC3 += 1
                missC1 += 1
                missC2 += 1
            elif dadoMemoriaAdd1.getCacheHit() == 4:
                missC1 += 1
                missC2 += 1
                missC3 += 1

            if dadoMemoriaAdd2.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 2:
                hitC2 += 1
                missC1 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 3:
                hitC3 += 1
                missC1 += 1
                missC2 += 1
            elif dadoMemoriaAdd2.getCacheHit() == 4:
                missC1 += 1
                missC2 += 1
                missC3 += 1

            if dadoMemoriaAdd3.getCacheHit() == 1:
                hitC1 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 2:
                hitC2 += 1
                missC1 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 3:
                hitC3 += 1
                missC1 += 1
                missC2 += 1
            elif dadoMemoriaAdd3.getCacheHit() == 4:
                missC1 += 1
                missC2 += 1
                missC3 += 1

            if opcode == 0:
                pass
            elif opcode == 1:
                conteudo1 = dadoMemoriaAdd1.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                conteudo2 = dadoMemoriaAdd2.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                soma = conteudo1 + conteudo2
                dadoMemoriaAdd3.getPalavras()[umaInstrucao.getAdd3().getEndPalavra()] = soma
                #dadoMemoriaAdd3.setAtualizado()
                #print('+', soma)
            elif opcode == 2:
                conteudo1 = dadoMemoriaAdd1.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                conteudo2 = dadoMemoriaAdd2.getPalavras()[umaInstrucao.getAdd1().getEndPalavra()]
                sub = conteudo1 - conteudo2
                dadoMemoriaAdd3.getPalavras()[umaInstrucao.getAdd3().getEndPalavra()] = sub
                #dadoMemoriaAdd3.setAtualizado()
                #print('-', sub)
                
            PC += 1

    totalHits = hitC1 + hitC2 + hitC3
    totalMisses = missC1 + missC2 + missC3

    print('Custo total do programa: {0}'.format(custo))
    print('Hit e Misses do programa:')
    print('C1 hit: {0} | C1 miss: {1}'.format( hitC1, missC1 ))
    print('C2 hit: {0} | C2 miss: {1}'.format( hitC2, missC2 ))
    print('C3 hit: {0} | C3 miss: {1}'.format( hitC3, missC3 ))
    print('Total de Hits: {0}'.format(totalHits))
    print('Total de Misses: {0}'.format(totalMisses))
    """
    taxaC1 = (hitC1 * 100) / (hitC1 + missC1)
    taxaC2 = (hitC2 * 100) / (hitC2 + missC2)
    taxaC3 = (hitC3 * 100) / (hitC3 + missC3)
    taxaRam = 100 - (taxaC1 + taxaC2 + taxaC3 )
    print("{0}% | {1}% | {2}% | {3}% |".format(taxaC1, taxaC2, taxaC3, taxaRam))
    """

def atualizaRam():
    for i in range(len(cache1)):
        if cache1[i].getPalavras() != RAM[cache1[i].getEndBloco()].getPalavras():
            RAM[cache1[i].getEndBloco()].setPalavras(cache1[i].getPalavras())
    for i in range(len(cache2)):
        if cache2[i].getPalavras() == RAM[cache2[i].getEndBloco()].getPalavras():
            RAM[cache2[i].getEndBloco()].setPalavras(cache2[i].getPalavras())
    for i in range(len(cache3)):
        if cache3[i].getPalavras() == RAM[cache3[i].getEndBloco()].getPalavras():
            RAM[cache3[i].getEndBloco()].setPalavras(cache3[i].getPalavras())
    
if __name__ == "__main__":
    montarRam()
    montarCacheVazia(tamanhoCache1, cache1)
    montarCacheVazia(tamanhoCache2, cache2)
    montarCacheVazia(tamanhoCache3, cache3)
    #montarInstrucoesProgramaAleatorio()
    montarInstrucaoGerador()
    maquina()
    atualizaRam()
    print('#Done!')