import sys
from time import time
from pprint import pprint
from BlocoMemoria import BlocoMemoria

def buscarNasMemorias(e, RAM, cache1, cache2, cache3):
    custo = 0

    conjunto = e.getEndBloco() % 2

    cache1Conjunto = int(len(cache1) / 2)
    cache2Conjunto = int(len(cache2) / 2)
    cache3Conjunto = int(len(cache3) / 2)

    if conjunto == 0:
        forRangeStartC1 = 0
        forRangeStartC2 = 0
        forRangeStartC3 = 0
        forRangeEndC1 = cache1Conjunto
        forRangeEndC2 = cache2Conjunto
        forRangeEndC3 = cache3Conjunto
    elif conjunto == 1:
        forRangeStartC1 = cache1Conjunto
        forRangeStartC2 = cache2Conjunto
        forRangeStartC3 = cache3Conjunto
        forRangeEndC1 = len(cache1)
        forRangeEndC2 = len(cache2)
        forRangeEndC3 = len(cache3)

    for posicaoCache1 in range(forRangeStartC1, forRangeEndC1):
        if cache1[posicaoCache1].getEndBloco() == e.getEndBloco():
            custo += 10
            cache1[posicaoCache1].setCusto(custo)
            cache1[posicaoCache1].setCacheHit(1)
            cache1[posicaoCache1].setTimeUtilizado(time())
            return cache1[posicaoCache1]

    for posicaoCache2 in range(forRangeStartC2, forRangeEndC2):
        if cache2[posicaoCache2].getEndBloco() == e.getEndBloco():
            custo += 110
            cache2[posicaoCache2].setCacheHit(2)
            cache2[posicaoCache2].setTimeUtilizado(time())
            return testaCache1Cache2(posicaoCache2, cache1, cache2, custo, forRangeStartC1, forRangeEndC1)

    for posicaoCache3 in range(forRangeStartC3, forRangeEndC3, forRangeEndC3):
        if cache3[posicaoCache3].getEndBloco() == e.getEndBloco():
            custo += 610
            cache3[posicaoCache3].setCacheHit(3)
            cache3[posicaoCache3].setTimeUtilizado(time())
            return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo, forRangeStartC1, forRangeEndC1, forRangeStartC2, forRangeEndC2)
        
    custo += 1610
    posicaoCache3 = espacoLivreCache(cache3, forRangeStartC3, forRangeEndC3)
    if posicaoCache3 != -1:
        cache3[posicaoCache3] = RAM[e.getEndBloco()]
        cache3[posicaoCache3].setCacheHit(4)
        cache3[posicaoCache3].setTimeUtilizado(time())
        return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo, forRangeStartC1, forRangeEndC1, forRangeStartC2, forRangeEndC2)
    else:
        posicaoCache3 = leastRecentlyUsed(cache3, forRangeStartC3, forRangeEndC3) #melhor posição na cache
        cache3[posicaoCache2].setNotAtualizado()
        RAM[cache3[posicaoCache3].getEndBloco()] = cache3[posicaoCache3]
        cache3[posicaoCache3] = RAM[e.getEndBloco()]
        cache3[posicaoCache3].setCacheHit(4)
        cache3[posicaoCache3].setTimeUtilizado(time())
        return testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo, forRangeStartC1, forRangeEndC1, forRangeStartC2, forRangeEndC2)


def testaCache1Cache2(posicaoCache2, cache1, cache2, custo, forRangeStartCache, forRangeEndCache):
    posicaoCache1 = espacoLivreCache(cache1, forRangeStartCache, forRangeEndCache)
    if posicaoCache1 != -1:
        cache1[posicaoCache1] = cache2[posicaoCache2]
    else:
        posicaoCache1 = leastRecentlyUsed(cache1, forRangeStartCache, forRangeEndCache)
        aux = BlocoMemoria()
        aux = cache1[posicaoCache1]
        cache1[posicaoCache1] = cache2[posicaoCache2]
        cache2[posicaoCache2] = aux
    cache1[posicaoCache1].setAtualizado()
    cache1[posicaoCache1].setTimeUtilizado(time())
    cache1[posicaoCache1].setCusto(custo)
    return cache1[posicaoCache1]

def testaCache2Cache3(posicaoCache3, cache1, cache2, cache3, custo, forRangeStartCache1, forRangeEndCache1, forRangeStartCache2, forRangeEndCache2):
    posicaoCache2 = espacoLivreCache(cache2, forRangeStartCache2, forRangeEndCache2)
    if posicaoCache2 != -1:
        cache2[posicaoCache2] = cache3[posicaoCache3]
    else:
        posicaoCache2 = leastRecentlyUsed(cache2, forRangeStartCache2, forRangeEndCache2)
        aux = BlocoMemoria()
        aux = cache2[posicaoCache2]
        cache2[posicaoCache2] = cache3[posicaoCache3]
        cache3[posicaoCache3] = aux
    cache2[posicaoCache2].setTimeUtilizado(time())
    cache2[posicaoCache2].setCusto(custo)
    return testaCache1Cache2(posicaoCache2, cache1, cache2, custo, forRangeStartCache1, forRangeEndCache1)

def espacoLivreCache(cache, forRangeStartCache, forRangeEndCache):
    for posicaoCache in range(forRangeStartCache, forRangeEndCache):
        if not cache[posicaoCache].isAtualizado():
            return posicaoCache
    return -1

def leastRecentlyUsed(cache, forRangeStartCache, forRangeEndCache): #LRU
    minTime = time()
    index = -1
    for i in range(forRangeStartCache, forRangeEndCache):
        if cache[i].getTimeUtilizado() < minTime:
            minTime = cache[i].getTimeUtilizado()
            index = i
    return index