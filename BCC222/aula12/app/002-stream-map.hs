-- Crie a função que aplica uma função a todos os elementos de um Stream

data Stream a
    = a :> Stream a
        deriving (Eq, Ord, Show)

streamMap :: (a -> b) -> Stream a -> Stream b
streamMap f (x:>xs) = (Stream (f x)) (streamMap f xs)