---
author: Programação Funcional
title: Primeiros passos com Haskell
date: Prof. Rodrigo Ribeiro
---

Objetivos
=========

- Configurar ambiente para desenvolvimento em Haskell.

- Usar o interpretador.

- Entender o modelo de execução de programas funcionais.


Setup
======

- Escolha um editor de texto: Atom,
Sublime, Visual Studio Code, Emacs, Vi(m),
etc...

- Instale o Haskell-stack:
[https://www.haskellstack.org](https://www.haskellstack.org).

Setup
=====

- Os seguintes itens são opcionais:
     - HLint: ferramenta para sugestões para código Haskell.
     - Pandoc: ferramenta para produção dos slides usados na
     disciplina.

Haskell Stack
=============

- Ferramenta para gerenciar projetos e bibliotecas.

- Instala todas as dependendências automaticamente (incluindo o compilador GHC).

Intepretador
============

- No terminal, digite `stack ghci` e você irá obter o prompt do interpretador:

~~~~~{.haskell}
Prelude*>
~~~~~~

Interpretador
=============

- Alguns comandos úteis do interpretador.
     - `:l` carrega um arquivo no interpretador.

~~~~~{.haskell}
Prelude*> :l Aula.hs
~~~~~~

Interpretador
=============

- Alguns comandos úteis do interpretador.
     - `:r` recarrega um arquivo no interpretador (útil após alterações).

~~~~~{.haskell}
Prelude*> :r
~~~~~~

Interpretador
=============

- Alguns comandos úteis do interpretador.
     - `:t` calcula o tipo de uma expressão fornecida como argumento.

~~~~~{.haskell}
Prelude*> :t True
True :: Bool
~~~~~~

Interpretador
=============

- Alguns comandos úteis do interpretador.
     - `:q` encerra a execução do interpretador.

~~~~~{.haskell}
Prelude*> :q
$>
~~~~~~

Interpretador
=============

- O GHCi é um REPL para Haskell.
- Read-Eval-Print-Loop
- Tente usar alguns operadores aritméticos:

~~~~~{.haskell}
Prelude*> 2 * (3 + 4)
14
Prelude*> (2 + 3) * 4
20
Prelude*> sqrt (3^2 + 4^2)
5.0
~~~~~~

Prelude
=======

- Biblioteca automaticamente importada por todo programa Haskell.
- Possui um grande número de tipos e funções pré-definidas.
- Exemplos:
    * Tipos numéricos: `Float`, `Double`, `Int` e `Integer`.
    * Funções usuais: +, *, -, /, div, mod, etc...
    * Importante: Haskell não possui subtyping.

Aplicação de função
===================

- Em matemática, a aplicação de uma função $f$ aos parâmetros
$x$ e $y$ é representada como $f(x,y)$.

- Em Haskell, a aplicação é representada por espaços entre as
expressões.

~~~~~{.haskell}
Prelude*> f x y
~~~~~~

Meu primeiro módulo Haskell
===========================

- Módulos Haskell devem ter nomes iniciados com letras maiúsculas.
- Chame seu arquivo como `Aula01.hs`.

\begin{code}
module Aula01 where

main :: IO ()
main = return ()
\end{code}


Definindo uma função simples
===========================

\begin{code}
double :: Int -> Int
double x = x + x
\end{code}

Componentes da definição
========================

- Assinatura

~~~~~{.haskell}
double :: Int -> Int
~~~~~~

- Equação

~~~~~{.haskell}
double x = x + x
~~~~~~

Requisitos de nomes
===================

- Tipos, módulos e classes de tipos devem possui nomes
que iniciam com uma letra maiúscula.

- Funções e variáveis devem iniciar com uma letra minúscula.


Executando o seu código
=====================

- No terminal, execute:

~~~~~~~
stack ghci Aula01.hs
~~~~~~~

ou

~~~~~
stack ghci
Prelude*> :l Aula01.hs
~~~~~

Executando sua função
=====================

~~~~~{.haskell}
Prelude*> double 5
10
Prelude*> double (double 2)
8
~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução

~~~~~{.haskell}
double 5 ==
5 + 5 ==
10
~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução


~~~~{.haskell}
double (double 2) ==
~~~~~~~

Execução do código
==================
- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução

~~~~{.haskell}
double (double 2) ==
(double 2) + (double 2) ==
~~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução


~~~~{.haskell}
double (double 2) ==
(double 2) + (double 2) ==
(2 + 2) + (double 2) ==
~~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução

~~~~{.haskell}
double (double 2) ==
(double 2) + (double 2) ==
(2 + 2) + (double 2) ==
(2 + 2) + (2 + 2) ==
~~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução

~~~~{.haskell}
double (double 2) ==
(double 2) + (double 2) ==
(2 + 2) + (double 2) ==
(2 + 2) + (2 + 2) ==
4 + 4 ==
8
~~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução


~~~~~{.haskell}
double (double 2) ==
~~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução

~~~~~{.haskell}
double (double 2) ==
double (2 + 2) ==
~~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução

~~~~~{.haskell}
double (double 2) ==
double (2 + 2) ==
(2 + 2) + (2 + 2) ==
~~~~~~~

Execução do código
==================

- Código Original

~~~~{.haskell}
double :: Int -> Int
double x = x + x
~~~~

- Execução

~~~~~{.haskell}
double (double 2) ==
double (2 + 2) ==
(2 + 2) + (2 + 2) ==
4 + 4 ==
8
~~~~~~~

Funções puras
=============

- Não realizam nenhum tipo de efeito
colateral: I/O, atualização de memória, etc.

- Sempre o mesmo resultado para as mesmas entradas.

- Ordem de avaliação não altera o resultado final.


Exemplo
========

- Somando os primeiros números inteiros.

- Java style, boring...

~~~~~{.java}
int sumUpToN ( int n) {
   int total = 0;
   for (int i = 1 ; i <= n ; i ++)
     total += i ;
   return total ;
}
~~~~~~~

Em Haskell...
===========

\begin{code}
sumUpToN :: Int -> Int
sumUpToN 0 = 0
sumUpToN n = n + sumUpToN (n - 1)
\end{code}

Executando sua função
=================

~~~~~{.haskell}
Prelude*> sumUpToN 4
10
~~~~~~

Executando sua função
=================

~~~~~{.haskell}
sumUpToN 4 ==
4 + sumUpToN 3 ==
4 + (3 + sumUpToN 2) ==
4 + (3 + (2 + sumUpToN 1)) ==
4 + (3 + (2 + (1 + sumUpToN 0))) ==
4 + (3 + (2 + (1 + 0))) ==
10
~~~~~~

Mais sobre a sintaxe de Haskell
=======================

- Palavras reservadas de Haskell.

~~~~~{.haskell}
case class data default deriving
do else foreign if import in
infix infixl infixr instance let
module newtype of then type where
~~~~~~

Sintaxe de Haskell
=============

- Regra de layout: blocos representados por identação de código.
Configure seu editor para usar espaços ao invés de TABs.

\begin{code}
a = b + c
    where
      b = 1
      c = 2
d = 3 * a
\end{code}

Sintaxe de Haskell
==================

- Uso de chaves: Praticamente nenhum programador Haskell usa esse estilo.

~~~~~~{.haskell}
a = b + c
    where {
      b = 1 ;
      c = 2
    }
d = 3 * a
~~~~~~~~~

Comentários
===========

\begin{code}
-- comentário de uma linha

triple x = double x + x

{-
múltiplas linhas...
-}
\end{code}


Tipos básicos de Haskell
========================

- Tipos numéricos: Int, Integer, Float, Double.
- Caracteres: Char - 'a', '0'.
- String: "abc".
- Booleanos: Bool - True, False.

Listas em Haskell
=================

- Sequências de valores de um mesmo tipo.
- Tipo de listas é representado por [a], em que a é um tipo.
- Exemplos

~~~~{.haskell}
[1,3] :: [Int]
[True, False, False] :: [Bool]
['a', 'b', 'c'] :: [Char] == String
~~~~~~

Tuplas em Haskell
================

- Sequências de valores de tipos possivelmente distintos.

~~~~~{.haskell}
(1, True, "ab") :: (Int, Bool, String)
(True, (1, 'a')) :: (Bool, (Int, Char))
~~~~~~

Tipos Funcionais em Haskell
=========================

- Tipos de funções possuem o formato `T1 -> T2`, em que
`T1` é o tipo de um parâmetro e `T2` do resultado.

- Exemplos

~~~~~{.haskell}
not :: Bool -> Bool
even :: Int -> Bool
~~~~~~

Verificando aplicações.
======================

- Se `f :: A -> B` e `x :: A` então `f x :: B`

- Formalmente:

$$
\frac{f :: A \to B\:\:\:\:\:\:x : A}{f\:x :: B}
$$


Exemplo
=======

- Verificando tipo de `not False`


$$
\frac{not :: Bool \to Bool\:\:\:\:\:\:False : Bool}{not\:False :: Bool}
$$


Exercícios
==========

- Apresente a derivação de tipo da expressão `not (not True)`

Exercícios
==========

1. Implemente uma função que, a partir de
3 números inteiros, retorne a soma dos quadrados
dos dois maiores números.


Exercícios
==========

1. A função de Fibonacci pode ser definida como:

$$
F(n) = \left\{
         \begin{array}{ll}
           0 & \textit{se } n = 0\\
           1 & \textit{se } n = 1 \\
           F(n - 1) + F(n - 2) & \textit{caso contrário.}
         \end{array}
       \right.
$$

Implemente uma função em Haskell para calcular `F(n)`.


Exercícios
==========

2. A função de Fibonacci, implementada de acordo com
a definição anterior, realiza um número exponencial de
chamadas recursivas. Implemente uma função que calcule
`F(n)` fazendo um número linear de chamadas recursivas.
