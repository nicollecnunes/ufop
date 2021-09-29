-- Defina a função minList que retorna o menor inteiro de uma
-- lista de números fornecida como entrada. Siga cada um dos
-- passos anteriores para sua solução.

minList :: [Int] -> Int
minList [] = 0
minList (x : []) = x
minList (x : xs)
    | x <= minList' = x
    | otherwise = minList'
        where 
            minList' = minList xs