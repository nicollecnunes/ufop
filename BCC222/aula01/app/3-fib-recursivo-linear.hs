-- Implemente uma função que calcule F(n) fazendo
-- um número linear de chamadas recursivas

--zipWith soma duas listas conforme os mesmos índices
--tail remove o primeiro elemento

fib = 1 : 1 : zipWith (+) fib (tail fib)