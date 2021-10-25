data App
      = App { name :: String  -- application name
            , width :: Int    -- window width
            , height :: Int   -- window height
            }
        deriving (Eq, Show)

data Layout = Vertical [Layout]
            | Horizontal [Layout]
            | Single App
            deriving (Eq, Show)

minimizeAll :: Layout -> Layout
minimizeAll (Single (App n _ _)) = Single (App n 1 1)
minimizeAll (Vertical [(Single (App n _ _)), Horizontal [(Single (App n2 _ _))]]) = Vertical [Single (App n 1 1), Horizontal [Single (App n2 1 1)]]
minimizeAll (Horizontal [(Single (App n _ _)), Vertical [(Single (App n2 _ _))]]) = Horizontal [Single (App n 1 1), Vertical [Single (App n2 1 1)]]

-- em todos os casos, o nome é retornado da mesma forma, e, independentemente dos valores de Width e Height, eles serão sempre substituídos por 1. por isso
-- não são variáveis nomeadas, e sim um _
-- nos casos de janela Vertical e Horizontal, elas trazem consigo listas de Layout. e seguem a mesma lógica: retornam a composição da lista, e, a parte 
-- mais interna, do Single, tambem retorna "nome 1 1"