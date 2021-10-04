-- A função dropList recebe como entrada um número inteiro n
-- e uma lista xs e remove os n primeiros elementos de xs.
-- Implemente dropList seguindo os passos apresentados para
-- definir uma função recursiva


-- Vai diminuindo a entrada "n" até que chegue a zero e
-- retorne a lista atual
dropList :: Int -> [Int] -> [Int]
dropList _ [] = []
dropList 0 a = a
dropList n xs = dropList (n - 1) (tail xs)