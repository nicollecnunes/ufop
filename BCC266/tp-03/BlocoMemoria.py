class BlocoMemoria:

    palavra: list
    endBlock: int
    atualizado: bool
    custo: int
    cacheHit: int
    ultimoUso: int

    def __init__(self):
        self.endBlock = -1
        self.atualizado = False
        self.custo = 0
        self.cacheHit = 0
        self.ultimoUso: 2**31-1