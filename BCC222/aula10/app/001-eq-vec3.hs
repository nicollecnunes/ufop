{-# LANGUAGE InstanceSigs #-}
-- Implemente uma instância de Eq para o tipo Vec3.

data Vec3 = Vec3 Int Int Int

instance Eq Vec3 where
    (Vec3 x y z) == (Vec3 x' y' z') = x == x' && y == y' && z == z'
    v1 /= v2 = not (v1 == v2)
