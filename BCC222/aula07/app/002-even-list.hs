-- Considera a função even :: Int -> Bool que determina se
-- um inteiro é ou não par. Usando-a defina a função
-- evenList :: [Int] -> [Bool] de forma que:
-- evenList [1, 2, 3] == [False, True, False]

evenList :: [Int] -> [Bool]
evenList xs = map even xs
  where
    even x 
      | x `mod` 2 == 0 = True
      | otherwise = False