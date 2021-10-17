-- data Bit = O | I deriving Show
-- Modifique a implementação da serialização para utilizar essa versão
-- do tipo Bit

data Bit = O | I 
    deriving Show

bin2Int :: [Bit] ->  Int
bin2Int bs = sum [w * b | (w, b) <- zipWith f weights bs]
  where
    weights = iterate (*2) 1
    f p O = (p, 0)
    f p I = (p, 1)

int2Bin :: Int -> [Bit]
int2Bin 0 = []
int2Bin n = bitIO n : int2Bin (n `div` 2)
  where
    bitIO x = if odd (x `mod` 2)
                then I
                else O