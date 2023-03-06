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

n = len(d) -1
m = [[-1 for x in range(n+1)] for y in range(n+1)]
c = [[-1 for x in range(n+1)] for y in range(n+1)]

for i in range(1,n+1):
    m[i][i] = 0

for l in range(2,n+1):
    for i in range(1,n-l+1+1):
        j = i + l - 1
        m[i][j] = math.inf
        for k in range(i,j-1+1): #k vai de i ate j-1
            q = m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j] #q = mij
            if (q < m[i][j]):
                m[i][j] = q
                c[i][j] = k #c tem o valor do k. que e a escolha, que criou o menor q


#para criar os parenteses
def resultadoc(s, i, j):
    if (i != j):
        resultadoc(s, i, s[i][j])
        resultadoc(s, s[i][j] + 1, j)
        print("A" + str(i) + " * A" + str(j))
        
def printParenthesis(i , j, n, bracket):
    global name
    if (i == j):
        print(name, end = "");
        name = chr(ord(name) + 1)
        return;
     
    print("(", end = "");
    printParenthesis(i, bracket[i][j], n, bracket);
    printParenthesis(bracket[i][j] + 1, j, n, bracket);
    print(")", end = "");

imprime(m)
imprime(c)
print("\ncusto:", m[1][n]);
#resultadoc(c,1, len(c)-1)
name = 'A';
printParenthesis(1, n, n+1, c)