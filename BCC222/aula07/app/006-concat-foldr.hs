-- Implemente a concatenação de listas usando foldr.
-- (++) :: [a] -> [a] -> [a]
-- [] ++ ys = ys
-- (x : xs) ++ ys = x : (xs ++ ys)

concatFoldr :: [a] -> [a] -> [a]
concatFoldr xs ys = foldr (:) ys xs