data Tree a
  = Leaf
  | Node a (Tree a) (Tree a)
  deriving (Eq, Ord, Show)

foldTree :: (a -> b -> b -> b) -> b -> Tree a -> b
foldTree _ v Leaf = v
foldTree f v (Node x l r)
     =  f x (foldTree f v l)
            (foldTree f v r)

-- Implemente a função mapTree usando foldTree.
mapTree :: (a -> b) -> Tree a -> Tree b
mapTree f = foldTree (\rt acLeft acRight -> Node (f rt) acLeft acRight) Leaf