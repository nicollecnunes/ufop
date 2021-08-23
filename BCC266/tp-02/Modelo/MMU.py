from BlocoMemoria import BlocoMemoria
from Endereco import Endereco

class MMU:

    @staticmethod
    def testaCache1Cache2(posicaoCache1: int, posicaoCache2: int, cache1: list, cache2: list, custo: int) -> BlocoMemoria:
        if(not cache1[posicaoCache1].atualizado):
            cache1[posicaoCache1] = cache2[posicaoCache2]
        else:
            aux = cache1[posicaoCache1]
            cache1[posicaoCache1] = cache2[posicaoCache2]
            cache2[posicaoCache2] = aux
        
        cache1[posicaoCache1].custo = custo

        return cache1[posicaoCache1]
        
    @staticmethod
    def buscarNasMemorias(e: Endereco, RAM: list, cache1: list, cache2: list) -> BlocoMemoria:
        
        posicaoCache1 = e.endBlock%len(cache1)
        posicaoCache2 = e.endBlock%len(cache2)
        custo = 0
        
        if(cache1[posicaoCache1].endBlock == e.endBlock):
            custo += 10
            cache1[posicaoCache1].custo = custo
            cache1[posicaoCache1].cacheHit = 1
            return cache1[posicaoCache1]
        
        elif(cache2[posicaoCache2].endBlock == e.endBlock):
            custo += 110
            cache2[posicaoCache2].cacheHit = 2
            return MMU.testaCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)
        
        else:
            custo += 1110
            if(not cache2[posicaoCache2].atualizado):
                cache2[posicaoCache2] = RAM[e.endBlock]
                cache2[posicaoCache2].cacheHit = 3
                return MMU.testaCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)
            
            else:
                RAM[cache2[posicaoCache2].endBlock] = cache2[posicaoCache2]
                RAM[cache2[posicaoCache2].endBlock].atualizado = False

                cache2[posicaoCache2] = RAM[e.endBlock]
                cache2[posicaoCache2].cacheHit = 3
                return MMU.testaCache1Cache2(posicaoCache1, posicaoCache2, cache1, cache2, custo)
