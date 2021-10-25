import Data.Maybe
data Error = NameLengthError       -- invalid size
             | NameCharactersError   -- name with non-letters and space characters
             | PhoneError            -- phone with non numeric chars.
             | EmailSizeError        -- invalid size
             | EmailCharError        -- lacking `@`
             deriving (Eq, Show)

data Validation = Ok
                 | Failure [Error] deriving (Eq, Show)

type Name  = String
type Phone = String
type Email = String

data Client = Client Name Phone Email deriving (Eq, Show)

-- o mesmo de testNome da questão anterior, porem pode retornar Nothing quando está tudo OK ou um erro
testNomeq4 :: Name -> Maybe Error
testNomeq4 n = if [c | c <- n, c `elem` ['A'..'Z'] || c `elem` ['a' .. 'z'] || c == ' '] == n 
    then if length n > 3 then Nothing else Just NameLengthError
    else Just NameCharactersError

-- o mesmo de testPhone da questão anterior, porem pode retornar Nothing quando está tudo OK ou um erro
testPhoneq4 :: Phone -> Maybe Error
testPhoneq4 p = if [c | c <- p, c `elem` ['0'..'9']] == p then Nothing else Just PhoneError

-- o mesmo de testEmail da questão anterior, porem pode retornar Nothing quando está tudo OK ou um erro
testEmailq4 :: Email -> Maybe Error
testEmailq4 e = if [c | c <- e, c == '@'] == ['@'] 
    then if length e > 3 then Nothing else Just EmailSizeError
    else Just EmailCharError

-- trata a saida, transformando a lista de Maybe Error em uma Validation. mais especificamente em uma Failure [Error]
-- Referencia: https://hackage.haskell.org/package/base-4.15.0.0/docs/Data-Maybe.html
tratarSaida :: [Maybe Error] -> Validation
tratarSaida f = Failure [fromJust c | c <- f]

-- monta uma lista dos retornos das funcoes de teste e retorna OK se todas tiverem retornado Nothing (significa que nao retornaram Error)
-- caso constrario, monta uma lista apenas com os erros retornados (saidas diferentes de Nothing) e chama a funcao tratarSaida para transformar a lista
-- de Maybe Error em uma Validation
question04 :: Client -> Validation
question04 (Client n p e) = if [testNomeq4 n, testPhoneq4 p, testEmailq4 e] == [Nothing, Nothing, Nothing] then Ok
                            else tratarSaida [v | v <- [testNomeq4 n, testPhoneq4 p, testEmailq4 e], v /= Nothing]
