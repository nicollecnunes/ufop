-- Implemente a função indexOf que, a partir de um inteiro x e
-- uma lista de inteiros xs, retorna a posição de x na lista xs.
-- Caso x não pertença a lista, o valor -1 deve ser retornado.

indexOf :: Int -> [Int] -> Int
indexOf n [] = -1
indexOf n (x:xs)
  | n == x = 0
  | otherwise = indexOf' xs n 1
  where
      -- Essa funcao tem o acumulador i e vai comparando
      -- se n é igual a cabeça de cada lista recursivamente
    indexOf' (y:ys) n i
      | y == n = i
      | ys == [] = -1
      | otherwise = indexOf' ys n (i + 1)