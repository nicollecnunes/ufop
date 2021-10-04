-- Desenvolva funções para calcular o número de elementos e o
-- número de folhas de uma árvore de tipo IntTree.

tree = INode 75 (INode 50 (INode 24 (INode 15 ILeaf ILeaf) (INode 33 ILeaf ILeaf)) (INode 57 ILeaf ILeaf)) (INode 84 ILeaf ILeaf)

data IntTree = ILeaf | INode Int IntTree IntTree

iTreeCountLeaves :: IntTree -> Int
iTreeCountLeaves ILeaf = 1
iTreeCountLeaves (INode _ l r) = (iTreeCountLeaves l) + (iTreeCountLeaves r)

