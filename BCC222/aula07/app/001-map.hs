 -- Redefina a função map usando list comprehensions, ao invés de
-- recursividade.

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f xs = [ f y | y <- xs]