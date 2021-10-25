-- Defina uma função que, a partir de uma lista de inteiros,
-- retorne a soma dos quadrados de seus elementos ímpares.
-- Defina essa função usando point-free style.

quadradoOdd :: [Int] -> Int
quadradoOdd = sum . map (\x -> x^2) . filter odd


