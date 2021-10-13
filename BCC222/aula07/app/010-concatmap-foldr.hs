-- I Uma implementação óbvia de concatMap é:
-- concatMap :: (a -> [b]) -> [a] -> [b]
-- concatMap f = concat . map f

-- Porém, é possível expressar essa função da seguinte forma
-- concatMap f = foldr step []
-- where ...
-- Apresente a implementação de concatMap utilizando foldr

concatMap :: (a -> [b]) -> [a] -> [b]
concatMap f = foldr step []
    where step x acc = (f x) ++ acc