{-# LANGUAGE InstanceSigs #-}
-- Implemente uma instância de Show para Person de forma que
-- o resultado da conversão para string de um valor de tipo
-- Person exiba apenas o campo name deste registro

data Person
    = Person {
        name :: String
        , age :: Int
}

instance Show Person where
     show (Person name _) = "Nome: " ++ name