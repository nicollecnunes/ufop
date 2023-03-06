import math

def imprime(m):
    for l in range(len(m)):
        for c in range(len(m[0])):
            print(m[l][c], end='    ', flush=True)
        print('')
    print('-------------------------------------')

d = [10,20,3,4,30]
#a 10x20
#b 20x3
# ab 600 10x3
#c 3x4
#d 4x30
# cd 360 3x30
#ult 900 10x30 -> 900+600+360 1860

#d = [30,1,40,10,25]

numMat = len(d)-1 
m = [[-1 for x in range(numMat)] for y in range(numMat)]
mCusto = [[-1 for x in range(numMat)] for y in range(numMat)]

for i in range(numMat):
    m[i][i] = 0

for desloc in range(1,numMat):
    for i in range(numMat-desloc): #preenche o triangulo superior
        j = i + desloc
        m[i][j] = math.inf
        for k in range(i,j): #k vai de i ate j-1, testa onde encaixa parentese
            custo = m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j] #custo = mij
            if (custo < m[i][j]):
                m[i][j] = custo
                mCusto[i][j] = k #mCusto tem o valor do k. que e a escolha, que criou o menor custo


#para criar os parenteses
def resultadoc(s, i, j):
    if (i != j):
        resultadoc(s, i, s[i][j])
        resultadoc(s, s[i][j] + 1, j)
        print("A" + str(i) + " * A" + str(j))
        
def printParenthesis(i , j, numMat, bracket):
    global name
    if (i == j):
        print(name, end = "");
        name = chr(ord(name) + 1)
        return;
     
    print("(", end = "");
    printParenthesis(i, bracket[i][j], numMat, bracket);
    printParenthesis(bracket[i][j] + 1, j, numMat, bracket);
    print(")", end = "");

imprime(m)
imprime(mCusto)
print("\ncusto:", m[0][numMat-1]);
resultadoc(mCusto,1, len(mCusto)-1)
name = 'A';
printParenthesis(1, numMat-1, numMat, mCusto)
