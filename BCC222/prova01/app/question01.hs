question01 :: [Integer] -> [Integer]
question01 [] = []
question01 (x : xs) = 
        if odd x then x*x : question01 xs
        else x:question01 xs

-- a funcao verifica se a cabeca da lista é impar, se sim, a eleva o quadrado
-- e chama recursivamente a funcao question01 para a cauda da lista, repetindo o passo
-- caso nao seja impar, retorna-se o próprio numero (cabeca da lista) e tambem faz a chamada
-- recursiva para a cauda da lista
-- quando a lista é vazia, retorna-se uma lista vazia, finalizando o loop recursivo
