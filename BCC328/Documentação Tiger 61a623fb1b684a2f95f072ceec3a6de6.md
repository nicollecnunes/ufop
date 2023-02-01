# Documentação Tiger

Author: NICOLLE CANUTO NUNES
Created: January 31, 2023 7:58 PM

## Lidando com comentários

Para iniciar a leitura de um comentário, foi definida a constante `let openComment = "/*"`, para identificar a abertura de um comentário pelo `/*`. Através da rule `token`, a condicional de abertura de comentário será acionada, chamando então a função `comment`, passando uma lista com a posição `lexeme_start_p` do buffer léxico (do módulo Lexing).

Na função `comment`, haverão 5 possibilidades de casamento:

- `| "/*" { comment (L.lexeme_start_p lexbuf :: list) lexbuf }`
    
    Esse caso indica a abertura de um novo comentário, o que significa que estaremos lidando com comentários aninhados, e, portanto, será necessário verificar o fechamento de cada um deles. Ao identificar um novo `/*`, realiza-se a chamada recursiva da função `comment`, alterando a lista atual de forma que sua primeira posição receba o valor `lexeme_start_p`, que indica onde esse novo comentado foi iniciado. O restante da lista se mantém da forma que está, na cauda da lista que será passada para a chamada recursiva.
    
- `| "*/" { match list with …`
    
    Esse caso identifica o fechamento de algum comentário. Para continuar lidando com a possível existência de comentários aninhados, tentamos fazer um match da lista atual com as seguintes possibilidades:
    
    - `| [_] -> token lexbuf`
        
        Nesse caso, a lista de posição de comentários abertos está vazia. Isso significa que a leitura de comentários foi concluída com êxito, e todos os comentários abertos foram devidamente fechados. Esse é o caso base.
        
    - `| _ :: tail -> comment tail lexbuf`
        
        Esse é o caso que lida com os comentários aninhados. Como, a cada comentário mais interno, adiciona-se a posição de sua abertura ao início da lista, ao encontrarmos um fechamento, este será o fechamento do último comentário aberto, e, portanto, deve-se remover a primeira posição da lista.
        
- `| '\n' { L.new_line lexbuf; comment list lexbuf }`
    
    Ao identificar uma quebra de linha, a função `new_line` atualiza a posição armazenada no buffer léxico na contagem de linhas. Após essa atualização, continua-se a execução de `comment` normalmente, utilizando a mesma `list` atual.
    
- `| _ { comment list lexbuf }`
    
    Na leitura de qualquer outro item que não seja um dos apresentados acima, continua-se a execução de `comment` normalmente, utilizando a mesma `list` atual, pois nada diferente precisa ser feito.
    
- `| eof { unterminated_comment (List.hd list, L.lexeme_end_p lexbuf) }`
    
    No caso da leitura ter sido identificada pelo `eof`, significa que um ou mais comentários foram abertos e não foram fechados. Por isso, chamamos a função de erro `unterminated_comment`, passando a primeira posição da lista `List.hd`, pois define-se que o comentário não fechado, inicialmente, é o último que foi aberto, ou seja, o último valor de posição que foi adicionado ao início da lista. Passa-se também a posição `lexeme_end_p`, para que, ao exibir o erro, seja mostrado também a posição final de onde ele foi identificado.
    

## Lidando com strings

Para iniciar a leitura de uma string, foi definida a constante `let openString = '"’`. Através da rule `token`, a condicional de abertura de string será acionada, chamando então a função `string`, passando como parâmetros a posição `lexeme_start_p` do buffer léxico (do módulo Lexing) e uma string vazia.

Na função `string`, haverão as seguintes tratativas para os casamentos:

- `| '"' {lexbuf.L.lex_start_p <- init; STR sequence}`
    
    Nesse caso, a string foi fechada, e, por isso `lex_start_p` receberá `init`, que armazena a posição inicial da primeira `“` lida quando a função foi chamada pela primeira vez. Em seguida, retorna-se o token `STR` do `parser`, recebendo `sequence`, que é a string lida ao final.
    
- `| "\\n" { string init (sequence ^ "\n") lexbuf }`
    
    Ao identificar um `\n` na string lida, é feita a chamada recursiva da função `string`, passando-se o mesmo valor de `init`, mas concatenando um `\n` ao final da `sequence` lida até o momento.
    
- `| "\\t" { string init (sequence ^ "\t") lexbuf }`
    
    Ao identificar um `\t` na string lida, é feita a chamada recursiva da função `string`, passando-se o mesmo valor de `init`, mas concatenando um `\t` ao final da `sequence` lida até o momento.
    
- `| "\\\"" { string init (sequence ^ "\"") lexbuf`
    
    Essa regra assegura que `\` seguida de `“` é uma sequência válida. Por isso, assim como nos casos acima, é feita a chamada recursiva da função `string`, passando-se o mesmo valor de `init`, mas concatenando um `\"` ao final da `sequence` lida até o momento.
    
- `| "\\"((spaces | "\n" | "\t")+ as inner)"\\" { str_incr_linenum inner lexbuf; string init (sequence) lexbuf }`
    
    Essa regra lida com espaços internos que existem entre duas `\`. Os “espaços” podem ser considerados qualquer sequência de: espaços em branco ( ``), quebras de linha (`\n`) ou tabulação horizontal (`\t`). Esses espaços são descartados, por isso, na chamada recursiva de `string`, passa-se `sequence` sem concatenar com nenhum elemento. Porém, é preciso atualizar a contagem de linhas caso exista um `\n` dentre os espaços lidos. Para isso, a função `str_incr_linenum` é chamada, passando a sequência de espaços para que ela identifique possíveis quebras de linha e atualize o valor de `new_line` do módulo `Lexing`.
    
    ……………………………………….
    
- `| "\\" ((digit digit digit) as ascii) { string init (sequence ^ String.make 1 (Char.chr (int_of_string ascii))) lexbuf }`
    
    Essa regra lida com a leitura de `\ddd`, que é uma barra seguida de três dígitos. Em Tiger, isso é usado para realizar a leitura do código ASCII de algum caractere. Para converter, armazena-se `digit digit digit` em uma variável `ascii` e realiza-se a conversão dos três dígitos para seu caractere correspondente através da função `int_of_string`. Novamente, é feita a chamada recursiva de `string`, concatenando a sequence construída ao resultado dessa conversão.
    
- `| "\\"(('\\')+ as seq) { string init (sequence ^ seq) lexbuf }`
    
    Esse caso valida a leitura de várias `\` seguidas umas das outras. Para isso, concatena-se as barras através da variável `seq` que foi usada para armazenar a sequência de barras lidas. 
    
- `| "\\^"(alpha as alp) { string init (sequence ^ String.make 1 (Char.chr (Char.code alp - Char.code '@'))) lexbuf }`
    
    Esse caso valida sequências de escape para caracteres de controle. Como em Tiger inicia-se no valor ASCII do caractere `@`, é preciso transformar o valor lido `alp` em seu valor numérico da tabela ASCII usando `Char.code`, subtrair o valor ASCII do caractere `@`, e em seguida, converter para um caractere novamente, através de `Char.chr`. Por fim, chama-se recursivamente `string`, concatenando a `sequence` ao caractere resultado, que será convertido em string usando `String.make`.
    
- `| "\\"_ { illegal_escape (L.lexeme_start_p lexbuf, L.lexeme_end_p lexbuf) (L.lexeme lexbuf) }`
    
    Esse caso captura quaisquer sequências de escape que não foram listadas acima e lança a exceção `illegal_escape`, passando a localização `lexeme_start_p`, do início da leitura desse padrão e a localização final, onde encontrou-se o caractere impróprio.
    
- `| eof {unterminated_string (init, L.lexeme_end_p lexbuf)}`
    
    Caso seja identificado EOF nessa leitura, significa que o processamento não foi encerrado no casamento com `“`, que seria o fechamento devido da `string`. Portanto, ao encontrar um `EOF`, lança-se o erro `unterminated_string`, passando a localização `init` das primeiras aspas e a final, onde encontrou-se o `EOF`.
    

## Lidando com EOF

EOFs podem ser identificados a qualquer momento, sendo lidos como qualquer outro token dentro de `rule token = parse…`. Porém, caso um EOF seja identificado dentro das funções `string` ou `comment`, isso indicará a ocorrência de algum erro.

### **EOF durante a leitura de uma string**

Caso um `EOF` seja identificado dentro de uma string, ou seja, antes que seja lida a `“` de fechamento, isso indica que estamos diante de uma string que não foi devidamente fechada. Nesse caso, é lançado o erro `unterminated_string`, que recebe como parâmetro `loc` um par ordenado que contém a posição inicial (onde a string foi aberta) e a posição final (onde foi identificado o `EOF` indevido).

### **EOF durante a leitura de um comentário**

Caso um `EOF` seja identificado dentro de um comentário, ou seja, antes que seja lida a `*/` de fechamento, isso indica que estamos diante de um comentário que não foi devidamente fechado. Nesse caso, é lançado o erro `unterminated_comment`, que recebe como parâmetro `loc` um par ordenado que contém a posição inicial, onde o comentário foi iniciado, (em caso de comentários aninhados, a posição inicial é a posição onde o último comentário foi aberto, ou seja, o mais interno) e a posição final (onde foi identificado o `EOF` indevido).

## Lidando com erros

Os erros têm uma forma definida de como serão impressos no terminal. No arquivo `error.ml` há a implementação de uma impressão customizada para alguns erros. Essa função recebe `loc` e `msg`, que são, respectivamente, um par ordenado que indica as posições de início e fim de um erro e a mensagem que será exibida em seguida. 

Sendo assim, em `lexer.mll`, são definidas algumas funções que capturam os parâmetros necessários para que esses sejam passados para seus respectivos erros ao chamar cada uma das funções.

Por exemplo, a função `let illegal_character loc char = Error.error loc "illegal character '%c'" char` envia para a definição de `error` o par ordenado da localização `loc` e a mensagem que será exibida, que, nesse caso, é a string formatada `"illegal character '%c'" char`. Erros são mostrados da seguinte forma:

```jsx
:1.0-1.1 error: illegal character '5'
```