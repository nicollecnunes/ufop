\begin{code}
module Main where
import Prelude hiding ((++), elem, reverse, map)

main :: IO ()
main = return ()


elem :: Eq a => a -> [a] -> Bool
elem _ [] = False
elem x (y : ys) = x == y || elem x ys

-- Questão 1. Prove o seguinte teorema: Para todas listas xs, ys e elemento x, se
-- elem x xs = True então elem x (xs ++ ys) = True.


\end{code}
