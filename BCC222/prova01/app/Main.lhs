Avaliação 1 de Programação Funcional
========================

ATENÇÃO
-------

* A interpretação dos enunciados faz parte
da avaliação.

* A avaliação deve ser resolvida INDIVIDUALMENTE.
Plágios não serão tolerados. TODAS as avaliações
em que algum tipo de plágio for detectado receberão
nota ZERO.

* Se você utilizar recursos disponíveis na internet
e que não fazem parte da bibliografia, você deverá
explicitamente citar a fonte apresentando o link
pertinente como um comentário em seu código.

* Todo código produzido por você deve ser acompanhado
por um texto explicando a estratégia usada para a
solução. Lembre-se: meramente parafrasear o código
não é considerado uma explicação!

* Não é permitido eliminar a diretiva de compilação -Wall
do cabeçalho desta avaliação.

* Caso julgue necessário, você poderá incluir bibliotecas
adicionais incluindo "imports" no cabeçalho deste
módulo.

* Seu código deve ser compilado sem erros e warnings
de compilação. A presença de erros acarretará em
uma penalidade de 20% para cada erro de compilação e
de 10% para cada warning. Esses valores serão descontados
sobre a nota final obtida pelo aluno.

* Todo o código a ser produzido por você está marcado
usando a função "undefined". Sua solução deverá
substituir a chamada a undefined por uma implementação
apropriada.

* Todas as questões desta avaliação possuem casos de
teste para ajudar no entendimento do resultado
esperado. Para execução dos casos de teste, basta
executar os seguintes comandos:

```
$> stack build
$> stack exec prova1-exe
```

* Sobre a entrega da solução:

1. A entrega da solução da avaliação deve ser feita
como um único arquivo .zip contendo todo o projeto
stack usado.

2. O arquivo .zip a ser entregue deve usar a seguinte
convenção de nome: MATRÍCULA.zip, em que matrícula é
a sua matrícula. Exemplo: Se sua matrícula for
20.1.2020 então o arquivo entregue deve ser
2012020.zip. A não observância ao critério de nome e
formato da solução receberá uma penalidade de 20%
sobre a nota obtida na avaliação.

3. O arquivo de solução deverá ser entregue usando a
atividade "Entrega da Avaliação 1" no Moodle dentro do
prazo estabelecido.

4. É de responsabilidade do aluno a entrega da solução
dentro deste prazo.

5. Sob NENHUMA hipótese serão aceitas soluções fora do
prazo ou entregues usando outra ferramenta que
não a plataforma Moodle.


Setup inicial
-------------

> {-# OPTIONS_GHC -Wall #-}

> module Main where

> import Test.Tasty
> import Test.Tasty.HUnit
> import Data.Maybe

> main :: IO ()
> main = defaultMain tests

> tests :: TestTree
> tests
>   = testGroup "Unit tests"
>         [
>            question01Tests
>         ,  question02Tests
>         ,  question03Tests
>         ,  question04Tests
>         ,  question05Tests
>         ]


Questão 1. Escreva a função

> question01 :: [Integer] -> [Integer]
> question01 [] = []
> question01 (x : xs) = 
>        if odd x then x*x : question01 xs
>        else x:question01 xs

> -- a funcao verifica se a cabeca da lista é impar, se sim, a eleva o quadrado
> -- e chama recursivamente a funcao question01 para a cauda da lista, repetindo o passo
> -- caso nao seja impar, retorna-se o próprio numero (cabeca da lista) e tambem faz a chamada
> -- recursiva para a cauda da lista
> -- quando a lista é vazia, retorna-se uma lista vazia, finalizando o loop recursivo


que recebe uma lista de inteiros como entrada e
retorna como resultado uma lista de inteiros em que
todo número ímpar presente na lista é elevado ao quadrado.
Sua implementação deve atender os seguintes casos de teste.

> question01Tests :: TestTree
> question01Tests
>       = testGroup "Question 01 Tests"
>                    [
>                       testCase "Question 01 empty" $
>                           question01 [] @?= []
>                    ,  testCase "Question 01 all even" $
>                           question01 (map (* 2) [1..5]) @?= map (* 2) [1..5]
>                    ,  testCase "Question 01 some odd" $
>                           question01 [1..5] @?= [1,2,9,4,25]
>                    ]


Questão 2. Considere o seguinte tipo de dados:

> data Times = Zero | One | Two

Sua tarefa é implementar a função:

> question02 :: Times -> (a, a, a) -> (a, a, a)
> question02 Zero xs = xs
> question02 One (x,y,z) = (z,x,y)
> question02 Two xs = question02 One (question02 One xs)

> -- dependendo do valor de Times passado, a funcao retorna o valor alterado
> -- ou chama recursivamente o caso One até que tenha sido trocado o número de vezes necessário

que a partir de um valor do tipo `Times` e uma tripla
de valores de tipo `a`, retorna uma tripla na qual os
valores foram rotacionados um número de vezes especificado
pelo tipo `Times.` Os casos de teste a seguir apresentam
exemplos desta função.

> question02Tests :: TestTree
> question02Tests
>       = testGroup "Question 02 Tests"
>                   [
>                      testCase "Swapping Zero times:" $
>                           question02 Zero ("a","b","c") @?= ("a","b","c")
>                   ,  testCase "Swapping One time:" $
>                           question02 One ("a", "b", "c") @?= ("c", "a", "b")
>                   ,  testCase "Swapping Two times:" $
>                           question02 Two ("a", "b", "c") @?= ("b", "c", "a")
>                   ]


Questão 03. Considere o seguinte tipo de dados que representa
dados de clientes de uma loja:

> type Name  = String
> type Phone = String
> type Email = String

> data Client = Client Name Phone Email deriving (Eq, Show)


Dizemos que a informação de um cliente é válida se:

a) O nome do cliente possui pelo menos 3 caracteres e é
formado exclusivamente por letras e espaços.

b) A informação de telefone é composta apenas por dígitos

c) A string de email deve conter o caractere `@` e ter tamanho
maior que 3.

Com base nessas informações, desenvolva a função:

> -- verifica se, ao manter somente os caracteres de 'A' a 'Z' ou 'a' a 'z' ou iguais a espaço, o nome alterado == nome
> -- e se o tamanho da string é maior que 3. se satisfaz essas duas condições, significa que é um nome valido
> testNome :: Name -> Bool
> testNome n = if [c | c <- n, c `elem` ['A'..'Z'] || c `elem` ['a' .. 'z'] || c == ' '] == n 
>    then if length n > 3 then True else False
>    else False

> -- verifica se, ao manter somente os caracteres de '0' a '9', a string p alterada permanece == string p original
> -- se sim, nada foi removido, logo, o telefome é válido
> testPhone :: Phone -> Bool
> testPhone p = if [c | c <- p, c `elem` ['0'..'9']] == p then True else False

> -- verifica se, ao manter somente o "@", a string alterada finaliza como "@" e se a string inicial tem tamanho > 3
> -- se sim, significa que o email contem "@", e, então, é valido
> testEmail :: Email -> Bool
> testEmail e = if [c | c <- e, c == '@'] == ['@'] 
>     then if length e > 3 then True else False
>     else False

> -- checa se todas as funcoes acima sao verdadeiras usando o operador "&&"
> question03 :: Client -> Bool
> question03 (Client n p e) = testNome n && testPhone p && testEmail e

que verifica se a informação de cliente é ou não válida de
acordo com as regras mencionadas anteriormente.

Sua implementação deve considerar os seguintes casos de teste.

> question03Tests :: TestTree
> question03Tests
>       = testGroup "Question 03 Tests"
>                   [
>                      testCase "Valid client" $
>                        question03 (Client "Marcos" "123456789" "marcos@bla.com") @?= True
>                   ,  testCase "Invalid name - size" $
>                        question03 (Client "Mr" "123456789" "marcos@bla.com") @?= False
>                   ,  testCase "Invalid name - not all letters" $
>                        question03 (Client "Mr22" "123456789" "marcos@bla.com") @?= False
>                   ,  testCase "Invalid phone" $
>                        question03 (Client "Marcos" "ab23" "marcos@bla.com") @?= False
>                   ,  testCase "Invalid email - size" $
>                        question03 (Client "Marcos" "123456789" "m@") @?= False
>                   ,  testCase "Invalid email - lacking @" $
>                        question03 (Client "Marcos" "123456789" "marcobla.com") @?= False
>                   ]

Questão 04. Um inconveniente da solução apresentada no exercício 03 é que a função não
apresenta uma explicação do motivo da validação falhar. Uma alternativa para isso é
criar um tipo de dados para representar as possíveis falhas de validação.

> data Error = NameLengthError       -- invalid size
>            | NameCharactersError   -- name with non-letters and space characters
>            | PhoneError            -- phone with non numeric chars.
>            | EmailSizeError        -- invalid size
>            | EmailCharError        -- lacking `@`
>            deriving (Eq, Show)


Usando a representação de erros de validação, podemos definir um tipo para representar
a validação:

> data Validation = Ok
>                 | Failure [Error] deriving (Eq, Show)

O construtor `Ok` representa que a validação executou com sucesso e o construtor `Failure`
representa uma falha de validação e armazena uma lista dos erros encontrados.

Com base no apresentado, implemente a função.

> -- o mesmo de testNome da questão anterior, porem pode retornar Nothing quando está tudo OK ou um erro
> testNomeq4 :: Name -> Maybe Error
> testNomeq4 n = if [c | c <- n, c `elem` ['A'..'Z'] || c `elem` ['a' .. 'z'] || c == ' '] == n 
>     then if length n > 3 then Nothing else Just NameLengthError
>     else Just NameCharactersError

> -- o mesmo de testPhone da questão anterior, porem pode retornar Nothing quando está tudo OK ou um erro
> testPhoneq4 :: Phone -> Maybe Error
> testPhoneq4 p = if [c | c <- p, c `elem` ['0'..'9']] == p then Nothing else Just PhoneError

> -- o mesmo de testEmail da questão anterior, porem pode retornar Nothing quando está tudo OK ou um erro
> testEmailq4 :: Email -> Maybe Error
> testEmailq4 e = if [c | c <- e, c == '@'] == ['@'] 
>     then if length e > 3 then Nothing else Just EmailSizeError
>     else Just EmailCharError

> -- trata a saida, transformando a lista de Maybe Error em uma Validation. mais especificamente em uma Failure [Error]
> -- Referencia: https://hackage.haskell.org/package/base-4.15.0.0/docs/Data-Maybe.html
> tratarSaida :: [Maybe Error] -> Validation
> tratarSaida f = Failure [fromJust c | c <- f]

> -- monta uma lista dos retornos das funcoes de teste e retorna OK se todas tiverem retornado Nothing (significa que nao retornaram Error)
> -- caso constrario, monta uma lista apenas com os erros retornados (saidas diferentes de Nothing) e chama a funcao tratarSaida para transformar a lista
> -- de Maybe Error em uma Validation
> question04 :: Client -> Validation
> question04 (Client n p e) = if [testNomeq4 n, testPhoneq4 p, testEmailq4 e] == [Nothing, Nothing, Nothing] then Ok
>                             else tratarSaida [v | v <- [testNomeq4 n, testPhoneq4 p, testEmailq4 e], v /= Nothing]


que realiza a validação de clientes, como apresentado na questão 03, e retorna um valor do
tipo `Validation`. Sua implementação deve atender os seguintes casos de teste.

> question04Tests :: TestTree
> question04Tests
>       = testGroup "Question 04 Tests"
>                   [
>                      testCase "Valid client" $
>                        question04 (Client "Marcos" "123456789" "marcos@bla.com") @?= Ok
>                   ,  testCase "Invalid name - size" $
>                        question04 (Client "Mr" "123456789" "marcos@bla.com") @?= Failure [NameLengthError]
>                   ,  testCase "Invalid name - not all letters" $
>                        question04 (Client "Mr22" "123456789" "marcos@bla.com") @?= Failure [NameCharactersError]
>                   ,  testCase "Invalid phone" $
>                        question04 (Client "Marcos" "ab23" "marcos@bla.com") @?= Failure [PhoneError]
>                   ,  testCase "Invalid email - size" $
>                        question04 (Client "Marcos" "123456789" "m@") @?= Failure [EmailSizeError]
>                   ,  testCase "Invalid email - lacking @" $
>                        question04 (Client "Marcos" "123456789" "marcobla.com") @?= Failure [EmailCharError]
>                   ,  testCase "Combining errors" $
>                        question04 (Client "Mr" "aa" "b@") @?= Failure [NameLengthError, PhoneError, EmailSizeError]
>                   ]


Questão 05. Considere o seguinte tipo de dados que representa a configuração de uma
aplicação em um sistema gerenciador de janelas:

> data App
>       = App { name :: String  -- application name
>             , width :: Int    -- window width
>             , height :: Int   -- window height
>             }
>         deriving (Eq, Show)


Aplicações são organizadas de acordo com um layout:

> data Layout = Vertical [Layout]
>             | Horizontal [Layout]
>             | Single App
>             deriving (Eq, Show)

Neste gerenciador de janelas simples, aplicações são organizadas de maneira vertical
(construtor `Vertical`), horizontal (construtor `Horizontal`) ou uma janela simples.

Seu objetivo é implementar a função:

> minimizeAll :: Layout -> Layout
> minimizeAll (Single (App n _ _)) = Single (App n 1 1)
> minimizeAll (Vertical [(Single (App n _ _)), Horizontal [(Single (App n2 _ _))]]) = Vertical [Single (App n 1 1), Horizontal [Single (App n2 1 1)]]
> minimizeAll (Horizontal [(Single (App n _ _)), Vertical [(Single (App n2 _ _))]]) = Horizontal [Single (App n 1 1), Vertical [Single (App n2 1 1)]]

> -- em todos os casos, o nome é retornado da mesma forma, e, independentemente dos valores de Width e Height, eles serão sempre substituídos por 1. por isso
> -- não são variáveis nomeadas, e sim um _
> -- nos casos de janela Vertical e Horizontal, elas trazem consigo listas de Layout. e seguem a mesma lógica: retornam a composição da lista, e, a parte 
> -- mais interna, do Single, tambem retorna "nome 1 1"

que minimiza todas as janelas do estado do gerenciador de janelas. Uma janela é
minimizada fazendo com que sua altura (height) e comprimento (width) sejam iguais a 1.

Sua implementação deve atender os seguintes casos de teste.

> question05Tests :: TestTree
> question05Tests
>       = testGroup "Question 05 Tests"
>                   [
>                       testCase "Minimize Single" $
>                         minimizeAll (Single (App "test" 110 200)) @?= Single (App "test" 1 1)
>                   ,   testCase "Minimize Vertical" $
>                         minimizeAll (Vertical [ Single (App "test" 110 200)
>                                               , Horizontal [Single (App "foo" 300 100)]])
>                               @?= Vertical [ Single (App "test" 1 1)
>                                            , Horizontal [Single (App "foo" 1 1)]]
>                   ,   testCase "Minimize Horizontal" $
>                         minimizeAll (Horizontal [ Single (App "test" 110 200)
>                                                 ,   Vertical [Single (App "foo" 300 100)]])
>                               @?= Horizontal [ Single (App "test" 1 1)
>                                              , Vertical [Single (App "foo" 1 1)]]
>                   ]
