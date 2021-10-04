-- A função de Fibonacci pode ser definida como:
-- F(0) = 0
-- F(1) = 1
-- F(n) = F(n − 1) + F(n − 2)
-- Implemente uma função em Haskell para calcular F(n).

f :: Int -> Int
f 0 = 0
f 1 = 1
f n = f(n - 1) + f(n - 2)