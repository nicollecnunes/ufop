-- Implemente a função andList que produz a conjunção de uma
-- lista de booleanos fornecida como entrada.

andList :: [Bool] -> Bool
andList [a] = a
andList (x : xs) = x && andList xs

-- exemplo: [True, False]
-- = True && orList False (1)
-- = True && False
-- = False


-- Implemente a função orList que produz a disjunção de uma
-- lista de booleanos fornecida como entrada.

orList :: [Bool] -> Bool
orList [a] = a
orList (x : xs) = x || orList xs

-- exemplo: [True, False]
-- = True || orList False (1)
-- = True || False
-- = True

