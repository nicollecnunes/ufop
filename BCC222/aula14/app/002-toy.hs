-- Qual o kind do tipo a seguir? Apresente uma instância de `Functor`
-- para esse tipo.

-- Tipo: * -> * -> *

data Toy a b =
    Output a b
  | Bell b
  | Done
  deriving (Eq, Ord, Show)

instance Functor (Toy a) where
  fmap _ Done = Done
  fmap f (Output x y) = Output x (f y)
  fmap f (Bell y) = Bell (f y)
