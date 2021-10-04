-- Desenvolva uma função que a partir de uma lista de clientes,
-- retorne uma lista contendo todos os clientes que desejam
-- receber mensagens de ofertas

clientes = [(Customer "Nicolle" "Nunes" False), (Customer "Nicolle2" "Nunes2" True),
            (Customer "Nicolle3" "Nunes3" False), (Customer "Nicolle4" "Nunes4" True)]


type Name = String
type Surname = String
type SendOffer = Bool

data Client
    = Customer{
    name :: Name,
    surname :: Surname,
    offers :: SendOffer
}
    deriving Show


querOferta :: Client -> Bool 
querOferta (Customer _ _ o) = o

listaClientesOfertas :: [Client] -> [Client]
listaClientesOfertas [] = []
listaClientesOfertas clientes = [cliente | cliente <- clientes, querOferta cliente == True]
