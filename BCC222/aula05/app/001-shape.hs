-- Desenvolva uma função para calcular a área de formas
-- geométricas descritas pelo tipo Shape

data Shape
    = Rectangle Float Float
    | Circle Float
    | Triangle Float Float
    | Square Float
    | Parallelogram Float Float

areaShapes :: Shape -> Float
areaShapes (Rectangle b h) = b * h
areaShapes (Circle r) = r * r * pi
areaShapes (Triangle b h) = b * h / 2
areaShapes (Square l) = l * l
areaShapes (Parallelogram b h) = b * h