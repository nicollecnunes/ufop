type Name  = String
type Phone = String
type Email = String

data Client = Client Name Phone Email deriving (Eq, Show)

-- verifica se, ao manter somente os caracteres de 'A' a 'Z' ou 'a' a 'z' ou iguais a espaço, o nome alterado == nome
-- e se o tamanho da string é maior que 3. se satisfaz essas duas condições, significa que é um nome valido
testNome :: Name -> Bool
testNome n = if [c | c <- n, c `elem` ['A'..'Z'] || c `elem` ['a' .. 'z'] || c == ' '] == n 
    then if length n > 3 then True else False
    else False

-- verifica se, ao manter somente os caracteres de '0' a '9', a string p alterada permanece == string p original
-- se sim, nada foi removido, logo, o telefome é válido
testPhone :: Phone -> Bool
testPhone p = if [c | c <- p, c `elem` ['0'..'9']] == p then True else False

-- verifica se, ao manter somente o "@", a string alterada finaliza como "@" e se a string inicial tem tamanho > 3
-- se sim, significa que o email contem "@", e, então, é valido
testEmail :: Email -> Bool
testEmail e = if [c | c <- e, c == '@'] == ['@'] 
    then if length e > 3 then True else False
    else False

-- checa se todas as funcoes acima sao verdadeiras usando o operador "&&"
question03 :: Client -> Bool
question03 (Client n p e) = testNome n && testPhone p && testEmail e
