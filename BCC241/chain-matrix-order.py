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

n = len(d)-1 
m = [[-1 for x in range(n)] for y in range(n)]
c = [[-1 for x in range(n)] for y in range(n)]

for i in range(n):
    m[i][i] = 0

for l in range(1,n):
    for i in range(n-l):
        j = i + l
        m[i][j] = math.inf
        for k in range(i,j): #k vai de i ate j-1
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
print("\ncusto:", m[0][n-1]);
resultadoc(c,1, len(c)-1)
name = 'A';
printParenthesis(1, n-1, n, c)
