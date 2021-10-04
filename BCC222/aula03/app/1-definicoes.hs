-- Escreva definições que possuam os seguintes tipos. Não se
-- preocupe se seu código faz ou não sentido desde que ele seja
-- aceito pelo compilador.

-- bools :: [Bool]
-- nums :: [[Int]]
-- add :: Int -> Int -> Int -> Int
-- copy :: a -> (a, a)
-- apply :: (a -> b) -> a -> b
-- swap :: (a,b) -> (b,a)

-- lista de booleanos
bools :: [Bool]
bools = [True, False, True, False]

-- lista de lista de inteiros
nums :: [[Int]]
nums = [[1,2,3],[4,5,6],[7,8,9]]

-- retorna a soma de 3 numeros
add :: Int -> Int -> Int -> Int
add x y z = x + y + z

-- retorna um par de um mesmo elemento
copy :: a -> (a, a)
copy x = (x, x)

-- aplica a uma funcao do tipo (a -> b) em a, retornando b
-- exemplo de chamada: apply length [2]
apply :: (a -> b) -> a -> b
apply funcao a = funcao a 

-- troca a ordem de um par
swap :: (a,b) -> (b,a)
swap (x, y) = (y, x)
