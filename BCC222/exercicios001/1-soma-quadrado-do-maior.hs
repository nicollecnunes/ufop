-- Implemente uma função que, a partir de 3 números inteiros,
-- retorne a soma dos quadrados dos dois maiores números.

maior3::Int->Int->Int->Int
maior3 x y z | x > y = if y > z then x * x + y * y else x * x + z * z
 | otherwise = if x > z then x * x + y * y else y * y + z * z