-- Defina uma função para testar se uma lista possui 2 elementos
-- ou menos. Faça isso de duas formas:
-- 1) usando casamento de padrão, com uma equação para cada possibilidade
-- 2) usando a função length, de tipo: length :: [a] -> Int

-- forma 1: casamento de padrão
casamentoPadrao :: [Int] -> Bool
casamentoPadrao [] = True -- possui 2 ou menos elementos (0 <= 2)
casamentoPadrao [_] = True -- possui 2 ou menos elementos (1 <= 2)
casamentoPadrao [_, _] = True -- possui 2 ou menos elementos (2 <= 2)
casamentoPadrao _ = False -- outro casos

-- forma 2: usando a funcao predefinida length
doisOuMenos :: [Int] -> Bool
doisOuMenos xs = if (length(xs) <= 2) then True
                                else False
                                