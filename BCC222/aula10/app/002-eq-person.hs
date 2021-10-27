{-# LANGUAGE InstanceSigs #-}
-- Implemente uma instância de Eq para o tipo Person que
-- considere duas pessoas iguais se essas possuírem o mesmo
-- nome.

data Person
    = Person {
        name :: String
        , age :: Int
}

instance Eq Person where
    (Person name _) == (Person name' _) = name == name'
    p1 /= p2 = not (p1 == p2)