-- Implemente a função filter utilizando list comprehensions ao
-- invés de recursividade.

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' p xs = [y | y <- xs, p y]