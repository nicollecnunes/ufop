-- Implemente a função removeAll que, a partir de um inteiro x
-- e uma lista de inteiros xs, remove todas as ocorrências de x da
-- lista xs. Apresente duas implementações: 

--1) usando recursividade
removeAllRec :: Int -> [Int] -> [Int]
removeAllRec _ [] = []
removeAllRec n xs
    | ((n `elem` xs) == False) = xs
    | n == (head xs) = removeAllRec n (tail xs)
    | otherwise = (head xs) : removeAllRec n (tail xs)

-- 2) usando list comprehensions
removeAllComp :: Int -> [Int] -> [Int]
removeAllComp _ [] = []
removeAllComp n xs = [y | y <- xs, y /= n]
