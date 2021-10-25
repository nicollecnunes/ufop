data Times = Zero | One | Two

question02 :: Times -> (a, a, a) -> (a, a, a)
question02 Zero xs = xs
question02 One (x,y,z) = (z,x,y)
question02 Two xs = question02 One (question02 One xs)

-- dependendo do valor de Times passado, a funcao retorna o valor alterado
-- ou chama recursivamente o caso One até que tenha sido trocado o número de vezes necessário