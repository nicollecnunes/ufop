#include "FordFulkerson.hpp"

#define DIRETO 1
#define REVERSO -1

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
    
    cout << "Vertice "<< this->id + 1<< " rotulado com "<< verticeAnterior + 1 << ", " << tipoDeArco << ", " << aumentoDeFluxo << endl;
    this->rotuloVerticeAnterior = verticeAnterior;
    this->rotuloTipoDeArco = tipoDeArco;
    this->rotuloCsi = aumentoDeFluxo;

    this->foiRotulado = true;
}

int Vertice:: calcularCsi(int csiPai, int folga)
{
    return min(csiPai, folga);
}

void Grafo:: iniciaListaVizinhanca()
{
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
    int anterior, index = (listaCaminho.size());

    for (int a = 0; a < listaCaminho.size() - 1; a ++)
    {
        index = listaCaminho[a];
        anterior = listaCaminho[a + 1];

        //cout << listaCaminho[a]+1 << endl;
        if (listaVertices[index].rotuloTipoDeArco == DIRETO)
        {
            listaVizinhanca[anterior][index].fluxo = listaVizinhanca[anterior][index].fluxo + csiT;
            cout << "somando csiT no arco direto" << anterior+1 <<  "-" << index+1 << endl;
        }
        else
        {
            listaVizinhanca[anterior][index].fluxo = listaVizinhanca[anterior][index].fluxo - csiT;
            cout << "subtraindo csiT no arco direto" << anterior+1 <<  "-" << index+1 << endl;
        }
    }
}

void Grafo:: preencheListas()
{
    int vOrigem, vDestino, limiteSuperior;
    iniciaListaVizinhanca();

    //cout << "Iniciando a leitura de " << qtdArcos << " arcos" << endl;
    for (int i = 0; i < qtdArcos; i++)
    {
        //cout << "Digite a origem, destino e limite superior da arco numero " << i << endl;
        cin >> vOrigem >> vDestino >> limiteSuperior;

        vOrigem = vOrigem - 1;
        vDestino = vDestino - 1;

        //cout << "Existe um arco entre " << vOrigem - 1 << " e " << vDestino - 1 << " de limite " << limiteSuperior << endl;
        listaVizinhanca[vOrigem][vDestino].existeArco = true;
        listaVizinhanca[vOrigem][vDestino].limiteSuperior = limiteSuperior;
    }

    //cout << "Inicializando lista de " << qtdVertices << " vertices." << endl;
    for (int i = 0; i < qtdVertices; i++)
    {
        Vertice verticeAux = Vertice(i, false);
        listaVertices.push_back(verticeAux);
    }
}

bool Grafo:: existeVerticeRotuladoComArcoUtilizavel()
{
    for (int i = 0; i < qtdVertices; i++)
    {
        if(listaVertices[i].foiRotulado)
        {
            for (int j = 0; j < qtdVertices; j++)
            {
                if (i != j && (!listaVertices[j].foiRotulado) && existeArco(i,j))
                {
                        vAtual = i;
                        vIncidente = j;
                        //cout << "arco utilizavel: V" << i+1 << " para V" << j+1 << endl;
                        return true;
                }
            }
        }
    }
    return false;
}

void Grafo:: constuirCaminhoECsi()
{
    listaCaminho.clear();

    csiT = INT_MAX;
    int index = listaVertices.size() - 1;
    listaCaminho.push_back(index);
    //cout << "aaaaaaaaa" << index + 1 << endl;

    while (listaVertices[index].rotuloVerticeAnterior != INT_MIN)
    {
        listaCaminho.push_back(listaVertices[index].rotuloVerticeAnterior);
        //cout << "aaaaaaaaa" << listaVertices[index].rotuloVerticeAnterior + 1 << endl;
        index = listaVertices[index].rotuloVerticeAnterior;

        csiT = min(csiT, listaVertices[index].rotuloCsi);
    }  
   // reverse(listaCaminho.begin(), listaCaminho.end());
}

void Grafo:: FordFulkerson()
{
    int csiPai, folga, csiVIncidente;
    listaVertices[0].rotular(INT_MIN, 0, INT_MAX);

    while(existeVerticeRotuladoComArcoUtilizavel()){
        if(listaVizinhanca[vAtual][vIncidente].existeArco
            && listaVizinhanca[vAtual][vIncidente].fluxo < listaVizinhanca[vAtual][vIncidente].limiteSuperior)
        {
            //cout << "existe um arco direto de" << vAtual+1 << " para " << vIncidente+1 << endl;
            csiPai = listaVertices[vAtual].rotuloCsi;
            folga = listaVizinhanca[vAtual][vIncidente].limiteSuperior - listaVizinhanca[vAtual][vIncidente].fluxo;

            csiVIncidente = listaVertices[vIncidente].calcularCsi(csiPai, folga);

            listaVertices[vIncidente].rotular(vAtual, DIRETO, csiVIncidente);
            listaCaminho.push_back(vIncidente);
        }
        else
        {
            if (listaVizinhanca[vIncidente][vAtual].existeArco
                && listaVizinhanca[vIncidente][vAtual].fluxo > 0)
            {
                //cout << "existe um arco de" << vIncidente << " para " << vAtual << " e fluxo maximo " << listaVizinhanca[vIncidente][vAtual].limiteSuperior<< endl;
                csiPai = listaVertices[vAtual].rotuloCsi;
                folga = listaVizinhanca[vAtual][vIncidente].fluxo;

                csiVIncidente = listaVertices[vIncidente].calcularCsi(csiPai, folga);

                listaVertices[vIncidente].rotular(vAtual, REVERSO, csiVIncidente);
                listaCaminho.push_back(vIncidente);
            }
        }
        if (listaVertices[listaVertices.size() - 1].foiRotulado)
        {
            constuirCaminhoECsi();
            aumentarFluxo();
            cancelarRotulos();
            cout << "continuar com se T rotulado" << endl;
            break;
        }
    }
}