from BlocoMemoria import BlocoMemoria
import random, pickle, sys

def serialize(endBloco, list_palavras: list):
    separator = ","
    end_line = "\n"
    string = endBloco + separator + separator.join(list_palavras) + end_line
    binary = string.encode()
    return binary

def main():
    tamanhoHD = 1000
    n_digitos_max_endereco = 3
    n_digitos_max_palavra = 6
    qdePalavrasBloco = 4
    
    with open('MemoriaExterna.bin', mode='wb') as f:
        for i in range(tamanhoHD):
            palavras = []
            for _ in range(qdePalavrasBloco):
                palavras.append(str(random.randint(0, 999999)).zfill(n_digitos_max_palavra))
            line = serialize(str(i).zfill(n_digitos_max_endereco), palavras)

            f.write(line)

if __name__ == "__main__":
    main()