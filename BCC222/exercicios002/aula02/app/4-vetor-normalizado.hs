-- Dado um vetor −→v = (x, y), calcule sua versão normalizada

-- calcula a formula da forma normalizada do vetor 
normal :: Float -> Float -> [Float]
normal x y = [(x / denominador x y), (y / denominador x y)]

-- calcula sqrt(pow(x,2) + pow(y,2))
-- para ser o denominador da formula principal
denominador :: Float -> Float -> Float
denominador x y = sqrt((x^2) + (y^2))


