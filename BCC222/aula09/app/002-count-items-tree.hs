data Tree a
  = Leaf
  | Node a (Tree a) (Tree a)
  deriving (Eq, Ord, Show)

foldTree :: (a -> b -> b -> b) -> b -> Tree a -> b
foldTree _ v Leaf = v
foldTree f v (Node x l r)
     =  f x (foldTree f v l)
            (foldTree f v r)

tree = Node 75 (Node 50 (Node 24 (Node 15 Leaf Leaf) (Node 33 Leaf Leaf)) (Node 57 Leaf Leaf)) (Node 84 Leaf Leaf)

-- Implemente uma função que calcula o número de elementos
-- presente em uma árvore usando foldTree.

counItemsTree :: Tree a -> Int
counItemsTree = foldTree (\_ acLeft acRight ->  1 + acLeft + acRight) 0 