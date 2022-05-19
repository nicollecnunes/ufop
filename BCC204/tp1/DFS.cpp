#include "DFS.hpp"

#define SIM 1
#define NAO 0

using namespace std;

Vertice:: Vertice(int i, int fV):id(i), foiVisitado(fV){}
Vertice:: ~Vertice(){}

Grafo:: Grafo(int qV, int qA, int eD, int iV):qtdVertices(qV), qtdArestas(qA), ehDirecionado(eD), verticeInicial(iV - 1){}
Grafo:: ~Grafo(){}

struct node* criarNode(int vDestino, int pesoAresta) {
    struct node* nodeAux = (struct node *) malloc(sizeof(struct node));
    //struct node* nodeAux = NULL;

    nodeAux->vDestino = vDestino;
    nodeAux->peso = pesoAresta;
    nodeAux->foiVisitada = false;
    nodeAux->pProx = NULL;

    return nodeAux;
}

void Grafo:: criaGrafo()
{
    int vOrigem, vDestino;
    double pesoAresta;
    struct node* nodeAux = NULL;

    //cout << "Iniciando lista de Adjacencia" << endl;
    this->adjLists = (struct node **) malloc(qtdVertices * sizeof(struct node*));

    for (int i = 0; i < qtdVertices; i++)
    {
        //cout << "lista do vertice " << i + 1 << endl;
        this->adjLists[i] = nodeAux;
    }

    //cout << "Iniciando a leitura de " << qtdArestas << " arestas" << endl;
    for (int i = 0; i < qtdArestas; i++)
    {
        //cout << "Digite a origem, destino e peso da aresta numero " << i << endl;
        cin >> vOrigem >> vDestino >> pesoAresta;

        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        if (ehDirecionado)
        {
            //cout << "GD: existe uma aresta entre " << vOrigem << " e " << vDestino << " de peso " << pesoAresta << endl;
            nodeAux = criarNode(vDestino, pesoAresta);
            nodeAux->pProx = this->adjLists[vOrigem];
            this->adjLists[vOrigem] = nodeAux;
        }
        else
        {
            //cout << "GND: existe uma aresta entre " << vOrigem << " e " << vDestino << " de peso " << pesoAresta << endl;
            nodeAux = criarNode(vDestino, pesoAresta);
            nodeAux->pProx = this->adjLists[vOrigem];
            this->adjLists[vOrigem] = nodeAux;

            //cout << "e vice- versa" << endl;
            nodeAux = criarNode(vOrigem, pesoAresta);
            nodeAux->pProx = this->adjLists[vDestino];
            this->adjLists[vDestino] = nodeAux;
        }
    }

     //cout << "Inicializando lista de " << qtdVertices << " vertices." << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, NAO);
        listaVertices.push_back(verticeAux);
    }

//     for (int v = 0; v < this->qtdVertices; v++) {
//         struct node* temp = this->adjLists[v];
//         printf("\n vertice %d\n: ", v);
//         while (temp) {
//             printf("%d -> ", temp->vDestino);
//             temp = temp->pProx;
//         }
//         printf("\n");
//   }
}

bool Grafo:: existeAresta(int vOrigem, int vDestino)
{
    struct node* nodeAux = this->adjLists[vOrigem];
    while (nodeAux) {
        if (nodeAux->vDestino == vDestino)
        {
            //cout << "existe aresta entre " << vOrigem + 1 << " e " << vDestino+1 << endl;
            return true;
        }
        nodeAux = nodeAux->pProx;
    }
    return false;
}

void Grafo:: visitacaoAresta(int vOrigem, int vDestino, bool resultVisitacao)
{
    struct node* nodeAux = this->adjLists[vOrigem];
    while (nodeAux) {
        if (nodeAux->vDestino == vDestino)
        {
            nodeAux->foiVisitada = resultVisitacao;
            break;
        }
        nodeAux = nodeAux->pProx;
    }
}

bool Grafo:: arestaFoiVisitada(int vOrigem, int vDestino)
{
    struct node* nodeAux = this->adjLists[vOrigem];
    while (nodeAux) {
        if (nodeAux->vDestino == vDestino)
        {
            return nodeAux->foiVisitada;
        }
        nodeAux = nodeAux->pProx;
    }
    return false;
}

void Grafo:: buscaEmProfundidade(int verticeInicial, vector<int> *ordemFinal)
{  
    //cout << "Visitando o vertice de id " << verticeInicial + 1 << endl;
    listaVertices[verticeInicial].foiVisitado = SIM;
    ordemFinal->push_back(listaVertices[verticeInicial].id);

    //cout << "linha 128" << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        if (existeAresta(verticeInicial, i))
        {
            if (!listaVertices[i].foiVisitado)
            {
                //cout << "O vertice " << i << " nao foi visitado ainda. visitando a aresta " << verticeInicial << "-" << i << endl;
                visitacaoAresta(verticeInicial, i, true);
                //cout << "Chamada recusriva" << endl;
                buscaEmProfundidade(i, ordemFinal);
            }
            else
            {
                if (!arestaFoiVisitada(verticeInicial, i))
                {
                    visitacaoAresta(verticeInicial, i, true);
                }
            }
        }
    }
}
