#include "FordFulkerson.hpp"

#define LIMITE_INFERIOR 0

#define DIRETO 1
#define REVERSO -1

#define SOMA 1
#define SUBTRAI 2

Grafo:: Grafo(int qV, int qA):qtdVertices(qV), qtdArcos(qA){}
Grafo:: ~Grafo(){}

Vertice:: Vertice(int i, int fR):id(i), foiRotulado(fR){}
Vertice:: ~Vertice(){}

string handleRotuloTipoArco(int tipo)
{
    if (tipo == DIRETO)
    {
        return "+";
    }
    else if (tipo == REVERSO)
    {
        return "-";
    }
    else
    {
        return "indef.";
    }
}

void Vertice:: rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo, int verticeT)
{
    if (verticeAnterior != INT_MIN && this->id != verticeT)
    {
        cout <<"[" << verticeAnterior+1 << ", " << handleRotuloTipoArco(tipoDeArco) << ", " << aumentoDeFluxo << "] ";
    }
    if (this->id == verticeT)
    {
        cout <<"[" << verticeAnterior+1 << ", " << handleRotuloTipoArco(tipoDeArco) << ", " << aumentoDeFluxo << "] " << endl;
    }
    
    this->rVerticeAnterior = verticeAnterior;
    this->rTipoDeArco = tipoDeArco;
    this->rCsi = aumentoDeFluxo;
    this->foiRotulado = true;
}
struct node* criarNode(int vDestino, int limiteSuperior, int fluxoAtual, int tipoDeArco) {
    struct node* nodeAux = (struct node *) malloc(sizeof(struct node));

    nodeAux->vDestino = vDestino;
    nodeAux->limiteSuperior = limiteSuperior;
    nodeAux->fluxoAtual = fluxoAtual;
    nodeAux->foiVisitada = false;
    nodeAux->tipoDeArco = tipoDeArco;

    nodeAux->pProx = NULL;

    return nodeAux;
}

void Grafo:: criaGrafo()
{
    int vOrigem, vDestino, limiteSuperior;
    struct node* nodeAux = NULL;
    
    this->adjLists = (struct node **) malloc(qtdVertices * sizeof(struct node*));

    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, false);
        listaVertices.push_back(verticeAux);

        this->adjLists[i] = nodeAux;
    }

    for (int i = 0; i < qtdArcos; i++)
    {
        cin >> vOrigem >> vDestino >> limiteSuperior;

        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        nodeAux = criarNode(vDestino, limiteSuperior, 0, DIRETO);
        nodeAux->pProx = this->adjLists[vOrigem];
        this->adjLists[vOrigem] = nodeAux;
    }
}

bool Grafo:: existeAresta(int vOrigem, int vDestino)
{
    struct node* nodeAux = this->adjLists[vOrigem];
    while (nodeAux)
    {
        if (nodeAux->vDestino == vDestino)
        {
            return true;
        }
        nodeAux = nodeAux->pProx;
    }
    return false;
}

void Grafo:: limparVisitacoes()
{
    for (int v = 0; v < this->qtdVertices; v++)
    {
        listaVertices[v].foiVisitado = false;
        struct node* nodeAux = this->adjLists[v];
        while (nodeAux)
        {
            nodeAux->foiVisitada = false;
            nodeAux = nodeAux->pProx;
        }
    }
}

void Grafo:: handleFluxo(int vOrigem, int vDestino, int valor, int operacao)
{
    struct node* nodeAux = this->adjLists[vOrigem];
    while (nodeAux) {
        if (nodeAux->vDestino == vDestino)
        {
            if (operacao == SOMA)
            {
                nodeAux->fluxoAtual = nodeAux->fluxoAtual + valor;
            }
            else
            {
                nodeAux->fluxoAtual = nodeAux->fluxoAtual - valor;
            }
            break;
        }
        nodeAux = nodeAux->pProx;
    }
}

void Grafo:: handleArestaPorTipo(int vOrigem, int vDestino)
{
    if (qualTipoDeArco(vOrigem, vDestino) == DIRETO)
    {
        handleFluxo(vOrigem, vDestino, csiT, SOMA);


        if (qualTipoDeArco(vDestino, vOrigem) == REVERSO)
        {
            handleFluxo(vDestino, vOrigem, csiT, SOMA);
        }
        else if (!existeAresta(vDestino, vOrigem))
        {
            struct node* nodeAux = this->adjLists[vOrigem];
            struct node* nodeAux2 = NULL;
            while (nodeAux)
            {
                if (nodeAux->vDestino == vDestino)
                {
                    nodeAux2 = criarNode(vOrigem, nodeAux->limiteSuperior, nodeAux->fluxoAtual, REVERSO);
                    nodeAux2->pProx = this->adjLists[vDestino];
                    this->adjLists[vDestino] = nodeAux2;
                    break;
                }
                nodeAux = nodeAux->pProx;
            } 
        }         
    }
    else
    {
        handleFluxo(vOrigem, vDestino, csiT, SUBTRAI);
        if (qualTipoDeArco(vDestino, vOrigem) == DIRETO)
        {
            handleFluxo(vDestino, vOrigem, csiT, SUBTRAI);
        }
    }
}

int Grafo:: qualTipoDeArco(int vOrigem, int vDestino)
{
    struct node* nodeAux = this->adjLists[vOrigem];
    while (nodeAux)
    {
        if (nodeAux->vDestino == vDestino)
        {
            return nodeAux->tipoDeArco;
        }
        nodeAux = nodeAux->pProx;
    }
    return 9999;
}

int Grafo:: calcularCsi(int verticeAnterior, int verticeAtual, int tipoDeArco, int csiPai)
{
    int limSupIJ, fluxoIJ;
    struct node* nodeAux = this->adjLists[verticeAnterior];
    while (nodeAux) {
        if (nodeAux->vDestino == verticeAtual)
        {
            limSupIJ = nodeAux->limiteSuperior;
            fluxoIJ = nodeAux->fluxoAtual;
            break;
        }
        nodeAux = nodeAux->pProx;
    }

    if (qualTipoDeArco(verticeAnterior, verticeAtual) == DIRETO) //DIRETO
    {
        return min(csiPai , (limSupIJ - fluxoIJ));
    }
    return min(csiPai , fluxoIJ);
}

bool Grafo:: fluxoMenorQueLimSup(Vertice vOrigem, Vertice vDestino)
{
    struct node* nodeAux = this->adjLists[vOrigem.id];
    while (nodeAux) {
        if (nodeAux->vDestino == vDestino.id)
        {
            return(nodeAux->fluxoAtual < nodeAux->limiteSuperior);
        }
        nodeAux = nodeAux->pProx;
    }
    return false;
}

bool Grafo:: fluxoMaiorQueLimInf(Vertice vOrigem, Vertice vDestino)
{
    struct node* nodeAux = this->adjLists[vOrigem.id];
    while (nodeAux) {
        if (nodeAux->vDestino == vDestino.id)
        {
            return(nodeAux->fluxoAtual > LIMITE_INFERIOR);
        }
        nodeAux = nodeAux->pProx;
    }
    return false;
}

void Grafo:: rotularEAumentar(Vertice *vOrigem, Vertice *vDestino)
{
    int verticeT = listaVertices[qtdVertices - 1].id;
    int csiRotulo = 0;
    
    if (qualTipoDeArco(vOrigem->id, vDestino->id) == DIRETO) //DIRETO
    {
        csiRotulo = calcularCsi(vOrigem->id, vDestino->id, DIRETO, vOrigem->rCsi);
        vDestino->rotular(vOrigem->id, DIRETO, csiRotulo, verticeT);
    }
    else //REVERSO
    {
        csiRotulo = calcularCsi(vOrigem->id, vDestino->id, REVERSO, vOrigem->rCsi);
        vDestino->rotular(vOrigem->id, REVERSO, csiRotulo, verticeT);
    }
    csiT = csiRotulo;
}

bool Grafo:: arestaDiretaUtilizavel(int verticeInicial, int w)
{
    return fluxoMenorQueLimSup(listaVertices[verticeInicial], listaVertices[w]) && qualTipoDeArco(verticeInicial, w) == DIRETO;
}

bool Grafo:: arestaReversaUtilizavel(int verticeInicial, int w)
{
    return fluxoMaiorQueLimInf(listaVertices[verticeInicial], listaVertices[w]) && qualTipoDeArco(verticeInicial, w) == REVERSO;
}

void Grafo:: buscaEmProfundidadeAdaptada(int verticeInicial, vector<int> *ordemFinal, bool *done)
{  
    listaVertices[verticeInicial].foiVisitado = true;
    ordemFinal->push_back(verticeInicial);

    int verticesTestados = 0;

    for (int w = 0; w < qtdVertices; w++)
    {
        if (verticeInicial == listaVertices[qtdVertices - 1].id)
        {
            verticesTestados = 0;
            tamanhoCaminho = ordemFinal->size() - 1;
            *done = true;
        }

        if (*done)
        {
            return;
        }

        if (existeAresta(verticeInicial, w))
        {
            if (!listaVertices[w].foiVisitado)
            {
                if (arestaDiretaUtilizavel(verticeInicial, w) || arestaReversaUtilizavel(verticeInicial, w))
                {
                    buscaEmProfundidadeAdaptada(w, ordemFinal, done);
                }
            }
        }

        verticesTestados = verticesTestados + 1;
        int ultimoDoCaminho = ordemFinal->back();

        if (verticesTestados == qtdVertices &&
            verticeInicial != listaVertices[qtdVertices - 1].id &&
            ultimoDoCaminho != listaVertices[qtdVertices - 1].id)
        {
            ordemFinal->pop_back();
        }
    }
}

void Grafo:: aumentarFluxo(vector<int> caminhoAteT)
{
    int vOrigem, vDestino, endCaminho = caminhoAteT.size();
    for (int i = 0 ; i < endCaminho - 1; i++)
    {
        vOrigem = caminhoAteT[i];
        vDestino = caminhoAteT[i+1];
        rotularEAumentar(&listaVertices[vOrigem], &listaVertices[vDestino]);
    }

    for (int i = 0 ; i < endCaminho - 1; i++)
    {
        vOrigem = caminhoAteT[i];
        vDestino = caminhoAteT[i+1];
        handleArestaPorTipo(vOrigem, vDestino);
    }
}

void Grafo:: FordFulkerson()
{
    vector<int> caminhoAteT;
    int verticeT = listaVertices[qtdVertices - 1].id;

    bool done = false;
    listaVertices[0].rotular(INT_MIN, 0, INT_MAX, verticeT);

    do
    {
        tamanhoCaminho = 0;
        done = false;
        buscaEmProfundidadeAdaptada(0, &caminhoAteT, &done);
        aumentarFluxo(caminhoAteT);
        limparVisitacoes();
        caminhoAteT.clear();
    }
    while(caminhoAteT[tamanhoCaminho] == verticeT);

}