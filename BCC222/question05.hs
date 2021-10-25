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

minimizeApp :: App -> Layout
minimizeApp (App name v h) = (Single (App name 1 1))

minimizeAll :: Layout -> Layout
minimizeAll (Single x) = minimizeApp x
--minimizeAll (Vertical (x : xs)) = Vertical (minimizeAll (minimizeApp x : minimizeAll xs))
--minimizeAll (Horizontal (x : xs)) = Horizontal minimizeApp x : minimizeAll xs