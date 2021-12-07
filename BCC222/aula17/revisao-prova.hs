-- Vamos definir um tipo de uma função para determinar
-- se uma lista é ou não ordenada.
sorted :: Ord a => [a] -> Bool
sorted [] = True
sorted [_] = True
sorted zs@(x : y : ys) = x <= y && sorted (y : ys)

-- sorted [1, 2, 3] : True
-- sorted [2, 1] : False


-- Inserção em uma lista ordenada.

-- O algoritmo insertion sort é baseado na ideia de inserir um
-- elemento em uma lista já ordenada.
insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (y : ys)
  | x <= y = x : y : ys
  | otherwise = y : insert x ys

-- insert 2 [1,3,5] : [1,2,3,5]

-- Definindo o algoritmo de ordenação.
-- A partir da definição do algoritmo de inserção de forma ordenada em listas, podemos implementar o insertion-sort.

insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (y : ys)
  | x <= y = x : y : ys
  | otherwise = y : insert x ys

isort :: Ord a => [a] -> [a]
isort []       = []
isort (x : xs) = insert x (isort xs)

-- isort [5, -1, 2, 3] : | -1 | 2 | 3 | 5 |


-- Mônadas
-- O que é uma mônada?
-- Tipo que tem pelo menos uma variável de tipo
-- Um construtor de tipo m :: * -> * que prove duas funções:
-- return : Monad m => a -> m a
-- >>= Operação que compõe mônadas
-- >>=    : Monad m => m a -> (a -> m b) -> m b
-- >>= vai remover esse valor de tipo a de dentro da mônada
-- e aplicar essa função sobre o valor de tipo a, produzindo o valor de tipo b


-- Exemplo 1: Mônada Maybe
-- Tarefa: procurar telefone e email em listas.
-- Primeiro procurar na lista de telefone e depois na de e-mails.

phonebook :: [(String, String)]
phonebook = [ ("Bob",   "01788 665242"),
              ("Fred",  "01624 556442"),
              ("Alice", "01889 985333"),
              ("Jane",  "01732 187565") ]

emails :: [(String, String)]
emails = [ ("Bob",   "bob@gmail.com"),
           ("Fred",  "fred@yahoo.com"),
           ("Alice", "alice@gmail.com"),
           ("Jane",  "jane@globo.com") ]

-- se o nome estiver nas duas listas, retorna telefone e email
-- se não, retorna nothing

-- com casamento de padrao:
contactInfo :: String -> Maybe (String, String)
contactInfo n
  = case lookup n phonebook of
    Nothing -> Nothing
    Just tel -> case lookup n emails of
      Nothing -> Nothing
      Just mail -> Just (tel, mail)

-- aqui tbm usa monada. o >>= esta implicito entre a quebra de linhas
contactInfo :: String -> Maybe (String, String)
contactInfo n
  = do
      tel <- lookup n phonebook
      mail <- lookup n emails
      return (tel, mail)

-- usando lookup abstraindo logica repetitiva usando >>=
--  (USA A FUNCAO QUE TA NA LINHA 98)
contactInfo :: String -> Maybe (String, String)
contactInfo n
    lookup n phonebook >>= \tel ->
    lookup n emails >>= \mail ->
      return (tel,mail)

-- usando a monada do tipo maybe
-- tipo: >>= :: Maybe a -> (a -> Maybe b) -> Maybe b
-- recebe valor do tipo a e retorna maybe b
instance Monad Maybe where
   return = Just
   m >>= f = case m of
               Just x -> f x -- x é o valor de tipo a
               Nothing -> Nothing


-- Exemplo 2: Mônada de listas.
-- Utilizada para representar computações não determinísticas.
-- Retornar uma lista contendo todas as possibilidades de valores de dois dados cuja soma seja igual a um valor n.
diceSum :: Int -> [(Int, Int)]
diceSum n = [1..6] >>= \ r1 -> 
            [1..6] >>= \ r2 ->
            if r1 + r2 == n then return (r1,r2) -- concatena todos os possiveis resultados
            else []

-- teste diceSum3
-- | 1 | 2 |
-- | 2 | 1 |

-- usando o do
diceSum :: Int -> [(Int, Int)]
diceSum n
  = do  
      r1 <- [1..6]
      r2 <- [1..6]
      if r1 + r2 == n then return (r1,r2)
      else []

-- com list comprehensions
diceSum :: Int -> [(Int, Int)]
diceSum n
  = [(r1, r2) | r1 <- [1..6], r2 <- [1..6], n == r1 + r2]

-- tipo de >>= para listas: >>= :: [a] -> (a -> [b]) -> [b]
-- xs :: [a]
-- f :: (a -> [b])
-- map f xs => [[b]] => tem que concatenar pra virar [b]
instance Monad [] where
  return x = [x]
  xs >>= f = concat (map f xs) -- ou concatMap f xs



-- Exemplo 3: Mônada de estado.
-- função que recebe o estado atual s e retorna o resultado
-- um par
-- Utilizada para representar computações que modificam valores.
-- Exemplo: modelando uma máquina de pilha.

data State s a = State {runState :: s -> (a, s)}

-- 
instance Functor (State s) where
  -- tipo fmap :: (a -> b) -> State s a -> State s b
  -- tipo do State: g :: s -> (a,s) resultado a e estado s
  fmap f (State g) = State (\ s -> let (a, s') = g s -- f e aplicada no primeiro componente do par
                                   in (f a, s')) -- g produz resultado a e novo estado s'

instance Applicative (State s) where
  -- tipo pure :: a -> State s a insere um valor na monada de estado
  pure x = State (\ s -> (x, s))
  -- tipo (<*>) :: State s (a -> b) -> State s a -> State s b
  f <*> x = State (\s -> let (g, s') = runState f s -- f é um state que retorna como resultado uma função
                             (y, s'') = runState x s' -- x é um state que retorna como resultado um valor de tipo a
                         in (g y, s'')) -- transição de estados s -> s' -> s''

instance Monad (State s) where
  -- tipo return :: a -> State s a
  return = pure
  -- tipo >>=  State s a -> (a ->State s b)- > State s b
  -- m é monada de estado
  -- executa a monada s, produz (a, s') 1:08
  m >>= f = State (\s -> let (a , s') = runState m s
                         in runState (f a) s')

-- atualiza o estado. atribuição
put :: s -> State s ()
put s = State (\ _ -> ((), s))

-- obter o estado atual
get :: State s s
get = State (\ s -> (s, s))

type Stack = [Int]

-- empilhar. recebe inteiro e empilha
-- o estado é a pilha; lista de int
-- modifica o estado da monada pra armazenar essa nova lista contendo o x
push :: Int -> State Stack ()
push x
  = do
      stk <- get
      put (x : stk)

-- obtem o estado atual., que vai ser uma lista de pelo menos 1 elemento
-- resultado a cabeça
pop :: State Stack Int
pop = do
        (x : xs) <- get
        put xs
        return x

-- desempilha dois elementos da lista e empilha a soma deles
add :: State Stack ()
add = do
  x <- pop
  y <- pop
  push (x + y)

-- desempilha dois elementos e empilha a multiplicação deles
mult :: State Stack ()
mult = do
  x <- pop
  y <- pop
  push (x * y)

sample :: State Stack Int
sample = do
  push 3 -- 3
  push 2 -- [2,3]
  add -- [5]
  push 5 -- [5,5]
  mult -- [25]
  pop -- [] a pilha fica vazia
  -- retorna (25, [])


-- Exemplo: Mônada para árvore binária.

data Tree a = Leaf | Node a (Tree a) (Tree a)
  deriving (Eq, Show)

instance Functor Tree where
  fmap _ Leaf = Leaf
  fmap f (Node x l r) = Node (f x) (f <$> l) (f <$> r)

instance Applicative Tree where
  pure x = Node x Leaf Leaf
  (Node f fl fr) <*> (Node x l r)
    = Node (f x) (fl <*> l) (fr <*> r)

combine :: Tree a -> Tree a -> Tree a
combine Empty r = r
combine (Node x l r) r' = Node x l (combine r r')

instance Monad Tree where
  return = pure
  (Node x l r) >>= f
    = case f x of
        Empty -> combine (l >>= f) (r >>= f)
        Node y l' r' -> Node y (combine (l >>= f) l')
                               (combine (r >>= f) r')