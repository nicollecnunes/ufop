-- Implemente uma função para selecionar todos os elementos de
-- uma lista de números inteiros que estão em um certo intervalo
-- numérico fornecido como parâmetro

-- Apresente uma implementação usando filter.
-- Apresente uma implementação usando recursão.

selectFilter :: [Int] -> Int -> Int -> [Int]
selectFilter xs a b = filter (<b) (filter (>a) xs)

selectRec :: [Int] -> Int -> Int -> [Int]
selectRec [] _ _ = []
selectRec xs a b = if ((head xs > a) && (head xs < b))
                    then (head xs) : selectRec (tail xs) a b
                    else selectRec (tail xs) a b