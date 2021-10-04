-- A função takeList recebe como entrada um número inteiro n
-- e uma lista xs e retorna, como resultado, uma lista contendo os
-- primeiros n de xs. Implemente takeList seguindo os passos
-- apresentados para definir uma função recursiva.


-- Init vai removendo o ultimo elemento e takeList é
-- chamada recursivamente para ver se o tamanho da lista == n
takeList :: Int -> [Int] -> [Int]
takeList n xs
      | length xs < n = []
      | length xs == n = xs
      | otherwise = takeList n (init xs)