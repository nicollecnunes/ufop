-- Dizemos que um número n e perfeito se ele e igual a soma de
-- seus fatores menores que n. Crie uma função Haskell que
-- retorna todos os números perfeitos em um dado intervalo.


-- realiza a soma dos divisores de 1 ate n, excluindo o n
-- e retorna em lista, caso a soma seja igual ao proprio numero
numerosPerfeitos :: Int -> [Int]
numerosPerfeitos n = [x | x <- [1..n], sum(init(divisores x))== x]


-- verifica se cada x, de 1 a n é divisível por n
-- se sim, x é adicionado na lista
divisores :: Int -> [Int]
divisores n = [x | x <- [1..n], n `mod` x == 0]

