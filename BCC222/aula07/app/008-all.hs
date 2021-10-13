--  A função all determina se todos os elementos de uma lista
-- satisfazem um predicado. Seu tipo é:
-- all :: (a -> Bool) -> [a] -> Bool
-- Implemente a função all: 1) usando recursão e 2) usando
-- foldr

allRec :: (a -> Bool) -> [a] -> Bool
allRec _ [] = True
allRec f xs =  step f xs True
    where
    step f [] b = b
    step f [x] b = step f [] ((f x) && b)
    step f (x:xs) b = step f xs ((f x) && b)


allFoldr :: (a -> Bool) -> [a] -> Bool
allFoldr f xs = foldr step True xs
  where
    step x xs = (f x) && xs