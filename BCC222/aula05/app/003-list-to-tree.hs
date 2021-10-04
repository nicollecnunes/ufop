-- Desenvolva uma função para converter uma lista (tipo
-- IntList) em uma árvore binária (tipo IntTree).

list = (ICons 75 (ICons 84 (ICons 50 (ICons 24 (ICons 33 (ICons 57 (ICons 15 INil)))))))

data IntTree = ILeaf | INode Int IntTree IntTree 
    deriving Show

data IntList = INil | ICons Int IntList

intList2IntTree :: IntList -> IntTree
intList2IntTree INil = ILeaf
intList2IntTree x = intList2IntTree' x ILeaf
    where 
        intList2IntTree' INil tree = tree
        intList2IntTree' (ICons x xs) tree = intList2IntTree' xs (mountIntTree x tree)


mountIntTree :: Int -> IntTree -> IntTree
mountIntTree x ILeaf = INode x ILeaf ILeaf
mountIntTree x (INode y esq dir)
    | (x == y) = INode y esq dir
    | (x < y) = INode y (mountIntTree x esq) dir
    | otherwise = INode y esq (mountIntTree x dir)