-- Dizemos que um número n é primo se ele é divisível por 1 e por
-- ele mesmo. Crie uma função Haskell que retorne todos os
-- números primos em um dado intervalo


-- retorna os numeros primos de determinado intervalo
primes :: Int -> [Int]
primes n = [x | x <- [1..n], init(divisores x) == [1]]

-- retorna se o numero n é primo ou não
prime :: Int -> Bool
prime n = if init(divisores n) == [1] then True
                                      else False
                                      
-- verifica se cada x, de 1 a n é divisível por n
-- se sim, x é adicionado na lista
divisores :: Int -> [Int]
divisores n = [x | x <- [1..n], n `mod` x == 0]