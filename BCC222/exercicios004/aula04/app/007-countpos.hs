-- Implemente a função countPos que, a partir de uma lista de
-- números inteiros, retorna a sua quantidade de números
-- positivos


countPos :: [Int] -> Int
countPos [] = 0
countPos (x:xs) = if x > 0
                then (countPos xs) + 1
                else (countPos xs) + 0