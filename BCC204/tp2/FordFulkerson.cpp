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
        this->adjLists[i] = nodeAux;

        Vertice verticeAux = Vertice(i, false);
        listaVertices.push_back(verticeAux);
    }

    for (int i = 0; i < qtdArcos; i++)
    {
        cin >> vOrigem >> vDestino >> limiteSuperior;
        //cout << "  -> existe uma aresta entre " << vOrigem << " e " << vDestino << " de lim " << limiteSuperior << endl;

        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        nodeAux = criarNode(vDestino, limiteSuperior, 0, DIRETO);
        nodeAux->pProx = this->adjLists[vOrigem];
        this->adjLists[vOrigem] = nodeAux;
    }
}

bool Grafo:: DFSExisteAresta(int vOrigem, int vDestino)
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

void Grafo:: DFSVisitacaoAresta(int vOrigem, int vDestino, bool resultVisitacao)
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

void Grafo:: DFSLimparVisitacoes()
{
    for (int v = 0; v < this->qtdVertices; v++)
    {
        listaVertices[v].foiVisitado = false;
        struct node* temp = this->adjLists[v];
        while (temp)
        {
            temp->foiVisitada = false;
            temp = temp->pProx;
        }
    }
}

bool Grafo:: DFSArestaFoiVisitada(int vOrigem, int vDestino)
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


void Grafo:: FFOperacaoNoFluxo(int vOrigem, int vDestino, int valor, int operacao)
{
    //cout << vOrigem + 1 << "-" << vDestino+1;
    //operacao == SOMA ? cout << ": somando " : cout << ": subtraindo: ";
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

void Grafo:: FFHandleFluxoAresta(int vOrigem, int vDestino)
{
    if (FFQualTipoDeArco(vOrigem, vDestino) == DIRETO)
    {
        FFOperacaoNoFluxo(vOrigem, vDestino, csiT, SOMA);

        if (FFQualTipoDeArco(vDestino, vOrigem) == REVERSO)
        {
            FFOperacaoNoFluxo(vDestino, vOrigem, csiT, SOMA);
        }
        else if (!DFSExisteAresta(vDestino, vOrigem))
        {
            struct node* nodeAux = this->adjLists[vOrigem];
            struct node* nodeAux2 = NULL;

            while (nodeAux) {
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
        FFOperacaoNoFluxo(vOrigem, vDestino, csiT, SUBTRAI);
    }
}

int Grafo:: FFQualTipoDeArco(int vOrigem, int vDestino)
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

int Grafo:: FFCalcularCsi(int verticeAnterior, int verticeAtual, int tipoDeArco, int csiPai)
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
    //cout << "--O fluxo entre " << verticeAnterior+1 << "-" << verticeAtual+1 << "eh " << fluxoIJ << endl;
    //cout << "--O limsup entre " << verticeAnterior+1 << "-" << verticeAtual+1 << "eh " << limSupIJ << endl;
    //cout << "--CSI de " << verticeAnterior+1 << " eh " << csiPai << endl;
    if (FFQualTipoDeArco(verticeAnterior, verticeAtual) == DIRETO) //DIRETO
    {
        return min(csiPai , (limSupIJ - fluxoIJ));
    }
    return min(csiPai , fluxoIJ);
}

bool Grafo:: FFFluxoMenorQueLimSup(Vertice vOrigem, Vertice vDestino)
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

bool Grafo:: FFFluxoMaiorQueLimInf(Vertice vOrigem, Vertice vDestino)
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

void Grafo:: FFRotularVerticesEAtualizarAumento(Vertice *vOrigem, Vertice *vDestino)
{
    int verticeT = listaVertices[qtdVertices - 1].id;
    int csiRotulo = 0;
    if (FFQualTipoDeArco(vOrigem->id, vDestino->id) == DIRETO) //DIRETO
    {
        csiRotulo = FFCalcularCsi(vOrigem->id, vDestino->id, DIRETO, vOrigem->rCsi);
        vDestino->rotular(vOrigem->id, DIRETO, csiRotulo, verticeT);
    }
    else //REVERSO
    {
        csiRotulo = FFCalcularCsi(vOrigem->id, vDestino->id, REVERSO, vOrigem->rCsi);
        vDestino->rotular(vOrigem->id, REVERSO, csiRotulo, verticeT);
    }
    csiT = csiRotulo;
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
            //cout << "chegou em T !!!! "<< endl;
            verticesTestados = 0;
            tamanhoCaminho = ordemFinal->size() - 1;
            *done = true;
        }

        if (*done)
        {
            return;
        }

        if (DFSExisteAresta(verticeInicial, w)) // TODO: melhorar esse if
        {
            //cout << "------"<< w+1 << " foi viistado:" << boolalpha << listaVertices[w].foiVisitado << endl;
            //cout << "------fluxo" <<verticeInicial+1 <<"-" << w+1<< " < limsup: " << boolalpha << FFFluxoMenorQueLimSup(listaVertices[verticeInicial], listaVertices[w]) << endl;
            if (!listaVertices[w].foiVisitado && FFFluxoMenorQueLimSup(listaVertices[verticeInicial], listaVertices[w]) && FFQualTipoDeArco(verticeInicial, w) == DIRETO)
            {
                //cout << "O vertice " << w+1 << " nao foi visitado ainda. visitando a aresta " << verticeInicial+1 << "-" << w+1 << endl;
                DFSVisitacaoAresta(verticeInicial, w, true);
                buscaEmProfundidadeAdaptada(w, ordemFinal, done);
            }
            else if (!listaVertices[w].foiVisitado && FFFluxoMaiorQueLimInf(listaVertices[verticeInicial], listaVertices[w]) && FFQualTipoDeArco(verticeInicial, w) == REVERSO)
            {
                //cout << "O vertice " << w+1 << " nao foi visitado ainda. visitando a aresta " << verticeInicial+1 << "-" << w+1 << endl;
                DFSVisitacaoAresta(verticeInicial, w, true);
                buscaEmProfundidadeAdaptada(w, ordemFinal, done);
            }
            else
            {
                if (!DFSArestaFoiVisitada(verticeInicial, w)) //TODO: ver se precisa disso
                {
                    DFSVisitacaoAresta(verticeInicial, w, true);
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

void Grafo:: TEMPimprimirCaminho(vector<int> caminhoAteT)
{
    cout << "---- CAMINHO"<< endl;
    for (int i = 0 ; i<tamanhoCaminho; i++)
    {
        cout << caminhoAteT[i]+1 << "-- ";
        //csiT = listaVertices[i].rCsi;
    }
    cout << endl;
}

void Grafo:: FFCaminharEAumentarFluxo(vector<int> caminhoAteT)
{
    int vOrigem, vDestino, endCaminho = caminhoAteT.size();
    for (int i = 0 ; i < endCaminho - 1; i++)
    {
        vOrigem = caminhoAteT[i];
        vDestino = caminhoAteT[i+1];
        FFRotularVerticesEAtualizarAumento(&listaVertices[vOrigem], &listaVertices[vDestino]);
    }

    for (int i = 0 ; i < endCaminho - 1; i++)
    {
        vOrigem = caminhoAteT[i];
        vDestino = caminhoAteT[i+1];
        FFHandleFluxoAresta(vOrigem, vDestino);
    }
}

void Grafo:: FordFulkerson()
{
    vector<int> caminhoAteT;
    int verticeT = listaVertices[qtdVertices - 1].id;

    bool done = false;

    listaVertices[0].rotular(INT_MIN, 0, INT_MAX, verticeT); // rotulando S com [-inf, 0, +inf]
    do
    {
        tamanhoCaminho = 0;
        done = false;
        buscaEmProfundidadeAdaptada(0, &caminhoAteT, &done);
        FFCaminharEAumentarFluxo(caminhoAteT);
        DFSLimparVisitacoes();
        caminhoAteT.clear();
    }
    while(caminhoAteT[tamanhoCaminho] == verticeT);

}