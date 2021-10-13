-- I A função takeWhile é definida como:
-- takeWhile :: (a -> Bool) -> [a] -> [a]
-- takeWhile _ [] = []
-- takeWhile p (x : xs)
-- | p x = x : takeWhile p xs
-- | otherwise = []
-- Implemente takeWhile usando foldr.

takeWhileFoldr :: (a -> Bool) -> [a] -> [a]
takeWhileFoldr p xs = foldr step [] xs
    where step x ys = if (f x) then (x:ys) else []
