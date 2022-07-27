class Pessoa:
    def __init__(self, nome):
        self.nome = nome

    def __str__(self):
        return self.nome

class CalculadoraSimples:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def soma(self):
        return self.a + self.b

    def subtrai(self):
        return self.a - self.b

    def multiplica(self):
        return self.a * self.b

    def divide(self):
        return self.a / self.b

class Calculadora:
    def soma(self, a, b):
        return a + b

    def subtrai(self, a, b):
        return a - b

    def multiplica(self, a, b):
        return a * b

    def divide(self, a, b):
        return a / b

class CalculadoraSimples:
    def __init__(self, nome, preco, quantidade):
        self.nome = nome
        self.preco = preco
        self.quantidade = nome

    def valorCompra(self):
        return self.preco * self.quantidade

    def infoPedido(self):
        return "Compra de " + self.quantidade + " " + self.nome + " a R$ " + self.preco + " cada."