-- Implemente um programa executável que produza estatísticas
-- sobre um arquivo fornecido como entrada. As estatísticas
-- produzidas devem ser o número de linhas e de palavras
-- presentes no arquivo

estatisticas :: FilePath -> IO()
estatisticas arq = do
    putStr("Quantidade de Linhas: ")
    x <- qtdLinhas (arq)
    print x

    putStr("Quantidade de Palavras: ")
    x <- qtdPalavras (arq)
    print x

qtdLinhas :: FilePath -> IO Int
qtdLinhas = fmap (length . lines) . readFile

qtdPalavras :: FilePath -> IO Int
qtdPalavras = fmap (length . words) . readFile