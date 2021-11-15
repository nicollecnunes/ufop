--  Defina uma instância de Applicative para listas e árvores
-- binárias.

data IntTree a
    = ILeaf
    | INode a (IntTree a) (IntTree a)
    deriving (Eq, Ord, Show)

instance Functor IntTree where
  fmap _ ILeaf         = ILeaf
  fmap f (INode x l r) = INode (f x) (f <$> l) (f <$> r)

instance Applicative IntTree where
  pure x                            = INode x ILeaf ILeaf
  ILeaf <*> _                        = ILeaf
  _ <*> ILeaf                        = ILeaf
  (INode x l1 r1) <*> (INode y l2 r2) = INode (x y) (l1 <*> l2) (r1 <*> r2)


