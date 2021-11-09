#include <iostream>
#include "Apartamento.h"
#include "Casa.h"
#include "Chacara.h"
#include "ConglomeradoImovel.h"
#include <vector>

using namespace std;

bool compararCrescente(const Imovel *i, const Imovel *j){
    return i->getValor() < j->getValor();
}

int main() {
    ConglomeradoImovel aux;
    vector<Imovel*> vetor = ConglomeradoImovel::lerArquivo();
    Imovel *imovel;
    vector<Imovel *> vetor3, vetor4, vetor6, vetor8;
    vector<vector<Imovel*>::iterator> vetor7;

    float valor = 0.0;
    int quartos;
    bool retorno;
    string tipo, cidade, nome;
    int opcaoFuncao8 = 0;

    int opcao;
    do{
        
        cout << "--------------------------MENU-----------------------------" << endl;
        cout << "    0- Sair do menu" << endl;
        cout << "    1- Verificar se o proprietario possui imovel" << endl;
        cout << "    2- Imoveis abaixo do valor especificado" << endl;
        cout << "    3- Imoveis com numero de quartos acima do especificado" << endl;
        cout << "    4- Imoveis por tipo" << endl;
        cout << "    5- Imoveis por cidade" << endl;
        cout << "    6- Imoveis por nome do proprietario" << endl;
        cout << "    7- Salvar imoveis em .txt" << endl;

        cout << "Informe o digito da funcao correspondente:" << endl;
        cin >> opcao;

        fflush(stdin);

        switch(opcao){
            case 0:
                system("cls || clear");
                printf("Saindo do menu...\n");
                break;
            case 1:
                system("cls || clear");
                cout << "Informe o nome do proprietario para pesquisa:" << endl;
                //cin.ignore();
                getline( cin, nome );

                retorno = ConglomeradoImovel::funcaoDois(&vetor, nome);

                if(retorno)
                    cout << "Ha imovel!\n" << endl;
                else
                    cout << "Nao ha imovel!\n" << endl;

                break;
            case 2:
                system("cls || clear");

                do{
                    cout << "Informe o valor para pesquisa" << endl;
                    cin >> valor;
                } while(valor < 0);

                fflush(stdin);

                vetor3 = ConglomeradoImovel::funcaoTres(valor, &vetor);

                for(auto & iterador : vetor3){
                    imovel = iterador;
                    cout << *imovel << endl;
                }

                vetor3.clear();

                break;
            case 3:
                system("cls || clear");
                do{
                    cout << "Informe o numero de quartos para pesquisa" << endl;
                    cin >> quartos;
                } while(quartos < 0);

                fflush(stdin);

                vetor4 = ConglomeradoImovel::funcaoQuatro(&vetor, quartos);

                for (auto & iterador : vetor4){
                    imovel = iterador;
                    cout << *imovel << endl;
                }

                vetor4.clear();

                break;
            case 4:
                system("cls || clear");
                try{
                    do{
                        cout << "Informe o tipo de imovel para pesquisa" << endl;
                        cout << "    apartamento | chacara | casa" << endl;
                        cin >> tipo;
                    } while(tipo != "apartamento" && tipo != "chacara" && tipo != "casa");

                    fflush(stdin);

                    vector<Imovel*> vetor5 = ConglomeradoImovel::funcaoCinco(tipo, &vetor);
                    sort(vetor5.begin(), vetor5.end(), compararCrescente);
                    
                    for(auto & iterador : vetor5){
                        imovel = iterador;
                        cout << *imovel << endl;
                        imovel->imprimirTudo();
                    }

                    vetor5.clear();
                } catch(const char* e){
                    cerr << "Erro: " << e << endl;
                }

                break;
            case 5:
                system("cls || clear");
                cout << "Informe a cidade para pesquisa de imoveis" << endl;
                cin >> cidade;

                fflush(stdin);

                vetor6 = ConglomeradoImovel::funcaoSeis(&vetor, cidade);
                sort(vetor6.begin(), vetor6.end(), compararCrescente);

                for(auto iterador = vetor6.rbegin(); iterador != vetor6.rend(); ++iterador){
                    imovel = *iterador;
                    cout << *imovel << endl;
                }

                vetor6.clear();

                break;
            case 6:
                system("cls || clear");
                cout << "Informe o nome do proprietario para pesquisa" << endl;
                getline( cin, nome );

                vetor7 = ConglomeradoImovel::funcaoSete(&vetor, nome);

                if(!vetor7.empty()){
                    cout << "Os imoveis do proprietario " << nome << " sao:" << endl;
                    for(auto & iterador : vetor7){
                        imovel = *iterador;
                        cout << *imovel << endl;
                    }
                }else
                    cout << "Nao Foi enontrado nenhum imovel para o proprietario: " << nome << endl;

                vetor7.clear();
                break;
            case 7:
                system("cls || clear");
                cout << "Digite 0: para a saida ser em arquivo (saida.txt)\nDigite 1: para os valores serem exibitos no terminal" << endl;
                cin >> opcaoFuncao8;

                fflush(stdin);

                ConglomeradoImovel::funcaoOito(&vetor, opcaoFuncao8);
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n" << endl;
        }

        fflush(stdin);
    } while(opcao);

    vetor.clear();
    return 0;
}
