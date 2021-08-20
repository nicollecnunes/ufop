from BlocoMemoria import BlocoMemoria
from Endereco import Endereco
from time import time
import sys
class MMU:
    
    @staticmethod
    def testaCache1Cache2(posicaoConjuntoCache1: int, posicaoConjuntoCache2: int, posicaoCache1: int, posicaoCache2: int, cache1: list, cache2: list, custo: int) -> BlocoMemoria:
        if(not cache1[posicaoConjuntoCache1].blocos[posicaoCache1].atualizado):
            cache1[posicaoConjuntoCache1].blocos[posicaoCache1] = cache2[posicaoConjuntoCache2].blocos[posicaoCache2]
        else:
            aux = cache1[posicaoConjuntoCache1].blocos[posicaoCache1]
            cache1[posicaoConjuntoCache1].blocos[posicaoCache1] = cache2[posicaoConjuntoCache2].blocos[posicaoCache2]
            cache2[posicaoConjuntoCache2].blocos[posicaoCache2] = aux
        
        cache1[posicaoConjuntoCache1].blocos[posicaoCache1].custo = custo
        
        return cache1[posicaoConjuntoCache1].blocos[posicaoCache1]
    
    @staticmethod
    def testaCache2Cache3(posicaoConjuntoCache1: int, posicaoConjuntoCache2: int, posicaoConjuntoCache3: int,  posicaoCache1: int, posicaoCache2: int, posicaoCache3: int, cache1: list, cache2: list, cache3: list, custo: int) -> BlocoMemoria:
        if(not cache2[posicaoConjuntoCache2].blocos[posicaoCache2].atualizado):
            cache2[posicaoConjuntoCache2].blocos[posicaoCache2] = cache3[posicaoConjuntoCache3].blocos[posicaoCache3]
        else:
            aux = cache2[posicaoConjuntoCache2].blocos[posicaoCache2]
            cache2[posicaoConjuntoCache2].blocos[posicaoCache2] = cache3[posicaoConjuntoCache3].blocos[posicaoCache3]
            cache3[posicaoConjuntoCache3].blocos[posicaoCache3] = aux
        
        cache2[posicaoConjuntoCache2].blocos[posicaoCache2].custo = custo
        return MMU.testaCache1Cache2(posicaoConjuntoCache1, posicaoConjuntoCache2, posicaoCache1, posicaoCache2, cache1, cache2, custo)

    @staticmethod
    def encontraEspaco(posicaoConjuntoCache: int, cache: list):
        last_block_index = 0
        #percorrendo os blocos do conjunto que se deseja encontrar espaco
        for bloco in cache[posicaoConjuntoCache].blocos:
            #caso encontre um espaco vazio este sera utilizado
            if(bloco.endBlock < 0):
                return cache[posicaoConjuntoCache].blocos.index(bloco)
            #caso nao encontre, vai ser necessario colocar o novo valor no lugar do dado mais antigo, portanto a medida
            #q os blocos do conjunto sao percorrido vamos atualizando o index do elemento mais antigo do conjunto
            if(bloco.ultimoUso < cache[posicaoConjuntoCache].blocos[last_block_index].ultimoUso):
                last_block_index = cache[posicaoConjuntoCache].blocos.index(bloco)
        return last_block_index
    
    @staticmethod
    def readFromHD(endBloco):
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

    @staticmethod
    def buscarNasMemorias(e: Endereco, RAM: list, cache1: list, cache2: list, cache3: list) -> BlocoMemoria:
        #definindo a posicao do conjunto de cada bloco
        posicaoConjuntoCache1 = e.endBlock%len(cache1)
        posicaoConjuntoCache2 = e.endBlock%len(cache2)
        posicaoConjuntoCache3 = e.endBlock%len(cache3)
        

        #posicao disponivel dentro do conjunto
        posicaoCache1 = None
        posicaoCache2 = None
        posicaoCache3 = None
        custo = 0

        #percorrendo o conjunto do cache 1 designado para aquele endereco
        for bloco in cache1[posicaoConjuntoCache1].blocos:
            if(bloco.endBlock == e.endBlock):
                custo += 10
                bloco.custo = custo
                bloco.cacheHit = 1
                #atualizando a ultima vez que esse recurso foi usado
                bloco.ultimoUso = time()
                return bloco
        
        for bloco in cache2[posicaoConjuntoCache2].blocos:
            if(bloco.endBlock == e.endBlock):
                custo += 110
                bloco.cacheHit = 2
                bloco.ultimoUso = time()
                '''
                caso o valor seja encontrado na cache 2, nos precisamos enviar ele para a cache 1,
                so que para fazer isso, eu preciso saber a posicao do valor na cache 2 e uma posicao
                na cache 1 que vai receber o valor da cache 2, esse metodo encontraEspaco faz nada mais
                do que isso
                '''
                posicaoCache1 = MMU.encontraEspaco(posicaoConjuntoCache1,cache1)
                posicaoCache2 = cache2[posicaoConjuntoCache2].blocos.index(bloco)
                return MMU.testaCache1Cache2(posicaoConjuntoCache1, posicaoConjuntoCache2, posicaoCache1, posicaoCache2, cache1, cache2, custo)
        
        for bloco in cache3[posicaoConjuntoCache3].blocos:
            if(bloco.endBlock == e.endBlock):
                custo += 1110
                bloco.cacheHit = 3
                bloco.ultimoUso = time()
                #onde no cache 2 que vamos passar o valor
                posicaoCache1 = MMU.encontraEspaco(posicaoConjuntoCache1,cache1)
                posicaoCache2 = MMU.encontraEspaco(posicaoConjuntoCache2,cache2)
                posicaoCache3 = cache3[posicaoConjuntoCache3].blocos.index(bloco)
                return MMU.testaCache2Cache3(posicaoConjuntoCache1, posicaoConjuntoCache2, posicaoConjuntoCache3, posicaoCache1, posicaoCache2, posicaoCache3,cache1, cache2, cache3, custo)
                
        #Verifica se o valor esta na ram, caso sim executa normalmente
        #Caso nao, primeiro acessa o hd, atualiza o valor na ram, e continua
        

        if(RAM[e.endBlock].endBlock == -1):
            RAM[e.endBlock] = MMU.readFromHD(e.endBlock)
            custo += 111110
            cacheHit = 5
        else:
            cacheHit = 4
            custo += 11110

        posicaoCache1 = MMU.encontraEspaco(posicaoConjuntoCache1,cache1)
        posicaoCache2 = MMU.encontraEspaco(posicaoConjuntoCache2,cache2)
        posicaoCache3 = MMU.encontraEspaco(posicaoConjuntoCache3,cache3)

        if(not cache3[posicaoConjuntoCache3].blocos[posicaoCache3].atualizado):
            cache3[posicaoConjuntoCache3].blocos[posicaoCache3] = RAM[e.endBlock]
            cache3[posicaoConjuntoCache3].blocos[posicaoCache3].cacheHit = cacheHit
            cache3[posicaoConjuntoCache3].blocos[posicaoCache3].ultimoUso = time()
            return MMU.testaCache2Cache3(posicaoConjuntoCache1, posicaoConjuntoCache2, posicaoConjuntoCache3, posicaoCache1, posicaoCache2, posicaoCache3,cache1, cache2, cache3, custo)
        else:
            RAM[cache3[posicaoConjuntoCache3].blocos[posicaoCache3].endBlock] = cache3[posicaoConjuntoCache3].blocos[posicaoCache3]
            RAM[cache3[posicaoConjuntoCache3].blocos[posicaoCache3].endBlock].atualizado = False

            cache3[posicaoConjuntoCache3].blocos[posicaoCache3] = RAM[e.endBlock]
            cache3[posicaoConjuntoCache3].blocos[posicaoCache3].cacheHit = cacheHit
            cache3[posicaoConjuntoCache3].blocos[posicaoCache3].ultimoUso = time() 
            return MMU.testaCache2Cache3(posicaoConjuntoCache1, posicaoConjuntoCache2, posicaoConjuntoCache3, posicaoCache1, posicaoCache2, posicaoCache3,cache1, cache2, cache3, custo)