-- Considere o tipo de dados Stream, de lista infinitas:
data Stream a
    = a :> Stream a
        deriving (Eq, Ord, Show)

-- 1. Crie a função que converte um Stream em uma lista

streamToList :: Stream a -> [a]
streamToList (x:>xs) = x:(streamToList xs)