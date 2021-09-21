-- Defina a função
-- max3 :: Int -> Int -> Int -> Int
-- que a partir de 3 números inteiros fornecidos como entrada, retorna
-- o maior deles

max3 :: Int -> Int -> Int -> Int
max3 a b c = if ((a >= b) && (a >= c)) then a
                                    else if ((b >= a) && (b >= c))
                                    then b
                                    else c