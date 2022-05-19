#include "FordFulkerson.hpp"

#define DIRETO 1
#define REVERSO -1

#define LIMITE_INFERIOR 0

Vertice:: Vertice(int i, bool fR):id(i), foiRotulado(fR){}
Vertice:: ~Vertice(){}

InfoArcos::InfoArcos(){}
InfoArcos:: ~InfoArcos(){}

Grafo:: Grafo(int qV, int qA):qtdVertices(qV), qtdArcos(qA){}
Grafo:: ~Grafo(){}

int InfoArcos::folgaSuperior()
{
    return limiteSuperior - fluxo;
}

int InfoArcos::folgaInferior()
{
    return fluxo;
}

bool Grafo:: existeArco(int v1, int v2)
{
    return (listaVizinhanca[v1][v2].existeArco || listaVizinhanca[v2][v1].existeArco);
}


void Vertice:: rotular(int verticeAnterior, int tipoDeArco, int aumentoDeFluxo)
{
    
    cout << "Vertice "<< this->id + 1<< " rotulado com "<< verticeAnterior + 1 << ", " << tipoDeArco << ", csi = " << aumentoDeFluxo << endl;
    this->rotuloVerticeAnterior = verticeAnterior;
    this->rotuloTipoDeArco = tipoDeArco;
    this->rotuloCsi = aumentoDeFluxo;

    this->foiRotulado = true;
    cout << endl;
}

int Vertice:: calcularCsi(int csiPai, int folga)
{
    return min(csiPai, folga);
}

void Grafo:: iniciaListaVizinhanca()
{
    cout << "Lista Vizinhanca" << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        vector<InfoArcos> listaAux;
        listaVizinhanca.push_back(listaAux);

        for (int j = 0; j < qtdVertices; j++)
        {
            listaVizinhanca[i].push_back(InfoArcos());
        }
    }
}

void Grafo:: cancelarRotulos()
{
    for (int i = 1; i < qtdVertices; i++)
    {
        listaVertices[i].foiRotulado = false;
    }
}

void Grafo:: aumentarFluxo()
{
    int anterior, index = (listaCaminho.size()), indexFinalIteracao = listaCaminho.size() - 1;

    for (int a = 0; a < indexFinalIteracao; a ++)
    {
        index = listaCaminho[a];
        anterior = listaCaminho[a + 1];

        cout << listaCaminho[a]+1 << endl;
        if (listaVertices[index].rotuloTipoDeArco == DIRETO)
        {
            listaVizinhanca[anterior][index].fluxo = listaVizinhanca[anterior][index].fluxo + csiT;
            //cout << "somando csiT no arco direto" << anterior+1 <<  "-" << index+1 << endl;
            cout << "fluxo em v" << anterior+1 << "-v" << index+1 << " == " <<listaVizinhanca[anterior][index].fluxo << endl;
            if (listaVizinhanca[anterior][index].fluxo == listaVizinhanca[anterior][index].limiteSuperior)
            {
                listaVizinhanca[anterior][index].existeArco = false;
               // cout << "arco direto" << anterior+1 <<  "-" << index+1 << " esgotado" << endl;
            } 
            
            if (listaVizinhanca[anterior][index].fluxo > LIMITE_INFERIOR)
            {
                //cout << "criando arco reverso " << index+1 << "-" << anterior+1 << " porque o fluxo eh " << listaVizinhanca[anterior][index].fluxo << "e o limite eh " << listaVizinhanca[anterior][index].limiteSuperior << endl;
                listaVizinhanca[index][anterior].existeArco = true;
                listaVizinhanca[index][anterior].tipoArco = REVERSO;
                listaVizinhanca[index][anterior].limiteSuperior = listaVizinhanca[anterior][index].limiteSuperior;
                listaVizinhanca[index][anterior].fluxo = listaVizinhanca[anterior][index].fluxo;
            }
        }
        else
        {
            listaVizinhanca[anterior][index].fluxo = listaVizinhanca[anterior][index].fluxo - csiT;
            //cout << "subtraindo csiT no arco reverso" << anterior+1 <<  "-" << index+1 << endl;
        }
    }
}

void Grafo:: preencheListas()
{
    int vOrigem, vDestino, limiteSuperior;
    iniciaListaVizinhanca();

    for (int i = 0; i < qtdArcos; i++)
    {
        cin >> vOrigem >> vDestino >> limiteSuperior;

        cout << "Existe um arco entre " << vOrigem << " e " << vDestino << " de limite " << limiteSuperior << endl;
        
        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        listaVizinhanca[vOrigem][vDestino].existeArco = true;
        listaVizinhanca[vOrigem][vDestino].limiteSuperior = limiteSuperior;
    }

    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, false);
        listaVertices.push_back(verticeAux);
    }
}

bool Grafo:: existeVerticeRotuladoComArcoUtilizavel()
{
    if (vAtual >= qtdVertices)
    {
        return false;
    }

    for (int j = 0; j < qtdVertices; j++)
    {
        cout << endl;
        cout << "            com o vAtual == " << vAtual+1 << endl;
        cout << "            testando o vertice " <<  j+1 << endl; 
        cout << "            diferente: ";
        cout << boolalpha << (vAtual != j) << endl;
        cout << "            nao foi rotuylado: ";
        cout << boolalpha << (!listaVertices[j].foiRotulado) << endl;
        cout << "            tem arco: ";
        cout << boolalpha << listaVizinhanca[vAtual][j].existeArco << endl;

        if (vAtual != j && (!listaVertices[j].foiRotulado) && listaVizinhanca[vAtual][j].existeArco)
        {
            cout << "            utilizavel " << endl;
            vDestino = j;
            return true;
        }
    }
    return false;
}

void Grafo:: constuirCaminho()
{
    // listaCaminho.clear();

    // int index = qtdVertices - 1;
    // listaCaminho.push_back(index);

    // while (listaVertices[index].rotuloVerticeAnterior != INT_MIN)
    // {
    //     listaCaminho.push_back(listaVertices[index].rotuloVerticeAnterior);
    //     index = listaVertices[index].rotuloVerticeAnterior;
    // }

    cout << "caminho: " <<endl;
    for (int i = 0; i< listaCaminho.size(); i++)
        cout << listaCaminho[i]+1 << " - ";
    
   cout << endl;
}

string handleRotuloTipoArco(int tipo)
{
    if (tipo == 1)
    {
        return "+";
    }
    return "-";
}

void Grafo:: imprimirResultado()
{
    cout << "resuktado" << endl;
    int index, indexFinalIteracao = listaCaminho.size();
    reverse(listaCaminho.begin(), listaCaminho.end());
    for (int a = 1; a < indexFinalIteracao; a ++)
    {
        index = listaCaminho[a];
        cout << "[" << listaVertices[index].rotuloVerticeAnterior+1 << ", " << handleRotuloTipoArco(listaVertices[index].rotuloTipoDeArco) << ", " << listaVertices[index].rotuloCsi << "]";
    }
    cout << endl;
}

void Grafo:: FordFulkerson()
{
    cout << "FordFulkerson" << endl;
    int csiPai, folga, csiVDestino;

    vAtual = 0;
    listaVertices[vAtual].rotular(INT_MIN, 0, INT_MAX);
    listaCaminho.push_front(vAtual);

    while(existeVerticeRotuladoComArcoUtilizavel()){
        if(listaVizinhanca[vAtual][vDestino].fluxo < listaVizinhanca[vAtual][vDestino].limiteSuperior)
        {
            //cout << "fluxo < lim. sup." << endl;
            csiPai = listaVertices[vAtual].rotuloCsi;
            folga = listaVizinhanca[vAtual][vDestino].limiteSuperior - listaVizinhanca[vAtual][vDestino].fluxo;
            csiVDestino = listaVertices[vDestino].calcularCsi(csiPai, folga);

            if(listaVizinhanca[vAtual][vDestino].tipoArco == DIRETO)
            {
                cout << "arco direto de" << vAtual+1 << " para " << vDestino+1 << endl;
                listaVertices[vDestino].rotular(vAtual, DIRETO, csiVDestino);
                listaCaminho.push_front(vDestino);

                vAtual = vDestino;
            }
            else 
            { 
                cout << "arco reverso de" << vAtual+1 << " para " << vDestino+1 << endl;
                listaVertices[vDestino].rotular(vAtual, REVERSO, csiVDestino);
                listaCaminho.push_front(vDestino);

                vAtual = vDestino;
            }
        }
        if (listaVertices[qtdVertices - 1].foiRotulado)
        {
            cout << "t foi alcancado" << endl;
            csiT = listaVertices[qtdVertices - 1].rotuloCsi;
            constuirCaminho();
            aumentarFluxo();
            cancelarRotulos();
            imprimirResultado();

            
            listaCaminho.clear();
            vAtual = 0;
            listaVertices[vAtual].rotular(INT_MIN, 0, INT_MAX);
            listaCaminho.push_front(vAtual);
        }
    }
    cout << "FordFulkerson ok" << endl;
}