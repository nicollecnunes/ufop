import Data.Char

newtype Parser s a
  = Parser {runParser :: [s] -> [(a,[s])]}

instance Functor (Parser s) where
   fmap f (Parser p)
      = Parser (\ inp -> [(f x, xs) | (x,xs) <- p inp])


sat :: (s -> Bool) -> Parser s s
sat p = Parser (\ inp -> case inp of
                           [] -> []
                           (x : xs) -> if p x
                                       then [(x,xs)]
                                       else [])

parseNumber :: Parser Char Int
parseNumber = f <$> digitChar
        where
          f (c:cs) = if c == ' ' then (ord cs - ord '0') else if cs == ' ' then (ord c - ord '0') else f cs

digitChar :: Parser Char Char
digitChar = sat isDigit


digit :: Parser Char Int
digit = f <$> digitChar
        where
          f c = (ord c - ord '0')