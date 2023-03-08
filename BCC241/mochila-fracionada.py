# Python program for implementation of Bubble Sort

def bubbleSort(arr):
	n = len(arr)
	swapped = False
	for i in range(n-1):
		for j in range(0, n-i-1):
			if (arr[j].value / arr[j].weight) < (arr[j+1].value / arr[j+1].weight):
				swapped = True
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
		
		if not swapped:
			return
			
	
		
def knapsack_frac(lista, W):
    bubbleSort(lista)

    capacidade = W
    f = []
    totalValue = 0

    for i in range(0,len(lista)+1):
        if capacidade > lista[i].weight:
            f.append(1)
            print(f'adicionando item de peso {lista[i].weight} e valor {lista[i].value}')
            totalValue += lista[i].value
            print(f'valor total: {totalValue}' )
            capacidade = capacidade - lista[i].weight
        else:
            break
	
    if i <= len(lista):
        f.append(capacidade/lista[i].weight)
        print(f'adicionando {capacidade/lista[i].weight}% do item de valor {lista[i].value} e peso {lista[i].weight}')
        totalValue += lista[i].value * capacidade/lista[i].weight
        print(f'valor total: {totalValue}' )
	    
    for j in range(i+1, len(lista)):
        f.append(0)
	    
    return f
	    
	    

class item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
 
list = []
list.append(item(60, 10))
list.append(item(150, 30))
list.append(item(120, 30))
list.append(item(160, 40))
list.append(item(200, 50))
list.append(item(150, 50))
list.append(item(60, 60))

print(knapsack_frac(list, 60))