-- Reimplemente a função bin2Int utilizando foldr.
type Bit = Int

bin2IntFoldr :: [Bit] -> Int
bin2IntFoldr = foldr (\ x y -> x + 2 * y ) 0
