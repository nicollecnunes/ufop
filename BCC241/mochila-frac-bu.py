def knapsack_bin(list, W):
    M = [[0 for x in range(W)] for y in range(len(list))] 

    for x in range(W):
        M[0][x] = 0

    for j in range(len(list)):
        M[j][0] = 0

    for j in range(1, len(list)):
        for x in range(W):
            if list[j]['weight'] > x:
                M[j][x] = M[j-1][x]
            else:
                usa = list[j]['value'] + M[j-1][x - list[j]['weight']]
                naousa = M[j-1][x]
                M[j][x] = max(usa, naousa)
    
    return M[len(list)-1][W-1]



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