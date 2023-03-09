def knapsack_bin(lista, W):
    if ((len(lista) == 0) or (W==0)):
        return 0 

    for i in range(len(list)):
        print(lista[i])
        if lista[i]['weight'] > W:
            lista.pop(i)
            return knapsack_bin(lista, W)
        
        valor = lista[i]['value']
        peso = lista[i]['weight']
        lista.pop(i)
        
        use = valor + knapsack_bin(lista, W - peso)
        not_use = knapsack_bin(lista, W)

        if (max(use, not_use) == use):
            print(f'usando o item de peso {peso} e valor {valor}')
        return max(use, not_use)


class item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
 
list = [
    { "value": 60, "weight": 1, },
    { "value": 150, "weight": 3, },
    { "value": 120, "weight": 3, },
    { "value": 160, "weight": 4, },
    { "value": 200, "weight": 5, },
    { "value": 150, "weight": 5, },
    { "value": 60, "weight": 6, },
]

print(knapsack_bin(list, 6))