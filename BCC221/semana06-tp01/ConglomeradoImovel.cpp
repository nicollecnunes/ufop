#include "ConglomeradoImovel.h"

vector<Imovel *> ConglomeradoImovel::lerArquivo(){
    vector<Imovel*> vetor_imoveis;
    FILE *arquivo_leitura;
    FILE *arquivo_escrita_definitiva;
    char auxiliar;
    string line;

    arquivo_leitura = fopen("database_imoveis.txt", "r");
    arquivo_escrita_definitiva = fopen("database_imoveis1.txt", "w");

    if(arquivo_leitura == nullptr || arquivo_escrita_definitiva == nullptr){
        cout << "ERRO AO ABRIR O AQUIRVO DE LEITURA OU DE ESCRITA - FUNCAO: lerArquivo()\n";
        abort();
    }

    ifstream arquivo_leitura_definitiva;

    while(true){
        auxiliar = (char) fgetc(arquivo_leitura);
        if(feof(arquivo_leitura))
            break;
        if(auxiliar == ';')
            fputc('\n', arquivo_escrita_definitiva);
        else
            fputc(auxiliar, arquivo_escrita_definitiva);
    }

    fclose(arquivo_leitura);
    fclose(arquivo_escrita_definitiva);

    arquivo_leitura_definitiva.open("database_imoveis1.txt", ifstream::in);

    if(arquivo_leitura_definitiva.fail()){
        cout << "ERRO AO ABRIR ARQUIVO DE LEITURA DEFINITIVA - FUNCAO: lerArquivo()\n";
        abort();
    }

    int i = 0;
    while(getline(arquivo_leitura_definitiva, line)){
        if(line == "apartamento") {
            vetor_imoveis.push_back(new (Apartamento));
            auto *ptr = dynamic_cast<Apartamento*>(vetor_imoveis[i]);
            vetor_imoveis[i] = ptr;
            formatacaoVetor(arquivo_leitura_definitiva, vetor_imoveis, i);
            getline(arquivo_leitura_definitiva, line);
            ptr->setAndar(stoi(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setTaxaCondominio(stof(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setElevador(stoi(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setSacada(stoi(line));
            vetor_imoveis[i] = ptr;
            i++;
        }
        else if(line == "casa") {
            vetor_imoveis.push_back(new (Casa));
            auto *ptr = dynamic_cast<Casa*>(vetor_imoveis[i]);
            vetor_imoveis[i] = ptr;
            formatacaoVetor(arquivo_leitura_definitiva, vetor_imoveis, i);
            getline(arquivo_leitura_definitiva, line);
            ptr->setAndares(stoi(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setSalaJantar(stoi(line));
            vetor_imoveis[i] = ptr;
            i++;
        }
        else if(line == "chacara") {
            vetor_imoveis.push_back(new (Chacara));
            auto *ptr = dynamic_cast<Chacara*>(vetor_imoveis[i]);
            vetor_imoveis[i] = ptr;
            formatacaoVetor(arquivo_leitura_definitiva, vetor_imoveis, i);
            getline(arquivo_leitura_definitiva, line);
            ptr->setSalaoFesta(stoi(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setSalaoJogos(stoi(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setCampoFutebol(stoi(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setChurrasqueira(stoi(line));
            getline(arquivo_leitura_definitiva, line);
            ptr->setPiscina(stoi(line));
            vetor_imoveis[i] = ptr;
            i++;
        }
    }

    return vetor_imoveis;
}

void ConglomeradoImovel::formatacaoVetor(ifstream &arquivo, vector<Imovel*> &vetor, int posicao) {
    string line;
    vetor.at(posicao)->setId(posicao);

    getline(arquivo, line);
    vetor.at(posicao)->setValor(stof(line));

    getline(arquivo, line);
    vetor.at(posicao)->setProprietario(line);

    getline(arquivo, line);
    vetor.at(posicao)->setRua(line);

    getline(arquivo, line);
    vetor.at(posicao)->setBairro(line);

    getline(arquivo, line);
    vetor.at(posicao)->setCidade(line);

    getline(arquivo, line);
    vetor.at(posicao)->setNumero(stoi(line));

    getline(arquivo, line);
    vetor.at(posicao)->setQuartos(stoi(line));

    getline(arquivo, line);
    vetor.at(posicao)->setBanheiros(stoi(line));
}

void ConglomeradoImovel::funcaoOito(vector<Imovel *> *vetor, const int opcao){
    string line;
    FILE *arquivo = fopen("saida.txt", "w");

    if(arquivo == nullptr){
        cout << "ERRO AO ABIR ARQUIVO OU ARQUIVO LEITURA DEFINITIVA - FUNCAO: funcaoOito\n";
        abort();
    }

    for(auto a : *vetor) {
        if(typeid(*a) == typeid(class Apartamento)){
            auto *ptr = dynamic_cast<Apartamento*>(a);
            if(opcao)
                cout << *ptr;
            else
                fprintf(arquivo, "%s\n%.2f\n%d\n%s\n%s\n%s\n%d\n\n", ptr->getProprietario().c_str(), ptr->getValor(), ptr->getQuartos(), ptr->getRua().c_str(), ptr->getBairro().c_str(), ptr->getCidade().c_str(), ptr->getElevador());
        }else if(typeid(*a) == typeid(class Casa)){
            auto *ptr = dynamic_cast<Casa*>(a);
            if(opcao)
                cout << *ptr;
            else
                fprintf(arquivo, "%s\n%.2f\n%d\n%s\n%s\n%s\n%d\n\n", ptr->getProprietario().c_str(), ptr->getValor(), ptr->getQuartos(), ptr->getRua().c_str(), ptr->getBairro().c_str(), ptr->getCidade().c_str(), ptr->getAndares());
        }else if(typeid(*a) == typeid(class Chacara)){
            auto *ptr = dynamic_cast<Chacara*>(a);
            if(opcao)
                cout << *ptr;
            else
                fprintf(arquivo, "%s\n%.2f\n%d\n%s\n%s\n%s\n%d\n\n", ptr->getProprietario().c_str(), ptr->getValor(), ptr->getQuartos(), ptr->getRua().c_str(), ptr->getBairro().c_str(), ptr->getCidade().c_str(), ptr->getPiscina());
        }
    }

    if(opcao == 0)
        cout << "Salvo no arquivo saida.txt" << endl;

    fclose(arquivo);
}

bool ConglomeradoImovel::funcaoDois(vector<Imovel *> *vetor, const string &proprietario) {
    bool achou = false;

    for(auto a : *vetor) {
        if(a->getProprietario() == proprietario)
            achou = true;
    }

    return achou;
}

vector<Imovel*> ConglomeradoImovel::funcaoQuatro(vector<Imovel*> *vetor, const int numeroQuartos)
{
    Imovel* imovel;
    vector<Imovel*> auxiliar;

    for (auto & iterador : *vetor)
    {
        imovel = iterador;

        if (numeroQuartos <= imovel->getQuartos())
            auxiliar.push_back(imovel);
    }

    return auxiliar;
}

vector<Imovel*> ConglomeradoImovel::funcaoSeis(vector<Imovel*> *vetor, const string& cidade)
{
    Imovel* imovel;
    vector<Imovel*> auxiliar;

    for (auto & iterador : *vetor)
    {
        imovel = iterador;

        if (cidade == imovel->getCidade())
            auxiliar.push_back(imovel);
    }

    return auxiliar;
}

vector<Imovel *> ConglomeradoImovel::funcaoTres(float valor, vector<Imovel *> *vetor){
    vector<Imovel*> imoveis_retorno;
    Imovel *imovel;
    
    for(auto iterador_reverso = vetor->rbegin(); iterador_reverso != vetor->rend(); ++iterador_reverso) {
        imovel = *iterador_reverso;

        if(imovel->getValor() <= valor){
            imoveis_retorno.push_back(imovel);
        }
    }

    return imoveis_retorno;
}

vector<Imovel*> ConglomeradoImovel::funcaoCinco(const string& tipo, vector<Imovel *> *vetor){
    vector<Imovel*> imoveis_retorno;
    Imovel *imovel;
    Imovel *imovel_tipo;

    cout << tipo << endl;

    if(tipo == "apartamento"){
        imovel_tipo = new (Apartamento);
    } else if(tipo == "chacara"){
        imovel_tipo = new (Chacara);
    } else if(tipo == "casa"){
        imovel_tipo = new (Casa);
    }

    for(auto iterador_reverso = vetor->rbegin(); iterador_reverso != vetor->rend(); ++iterador_reverso) {
        imovel = *iterador_reverso;

        if(typeid(*imovel) == typeid(*imovel_tipo)){
            imoveis_retorno.push_back(imovel);
        } 
    }   

    return imoveis_retorno;
}

vector<vector<Imovel*>::iterator> ConglomeradoImovel::funcaoSete(vector<Imovel *> *vetor, const string &nome) {
    vector<vector<Imovel*>::iterator> interadores;
    Imovel *imovel;

    for(auto iterador = vetor->begin(); iterador != vetor->end(); ++iterador) {
        imovel = *iterador;

        if(imovel->getProprietario() == nome){
            interadores.push_back(iterador);
        }
    }

    return interadores;
}

ConglomeradoImovel::~ConglomeradoImovel() = default;

