-- Defina a função minList que retorna o menor inteiro de uma
-- lista de números fornecida como entrada. Siga cada um dos
-- passos anteriores para sua solução.

minList :: [Int] -> Int
minList [] = 0
minList [x] = x
minList (x : xs) = menorDeDois x (minList xs)
    

-- Funcao que retorna o menor entre dois numeros.
-- sera usada para comparar a cabeça da lista com
-- as chamadas recursivas seguintes (cabeca do tail das outras)
menorDeDois :: Int -> Int -> Int
menorDeDois x y
    | x > y = y
    | y > x = x
    | otherwise = x

