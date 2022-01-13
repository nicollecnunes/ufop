package backend;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class FuncoesTopicos {
    static GerenciarArquivo gerenciarArquivo = new GerenciarArquivo();
    static List<Imovel> imoveis = new ArrayList<>();
    private static List<String> cidades = new ArrayList<>();
    
    //Função para iniciar dados 
    //Carrega os imoveis vindos do arquivo database
    //Carrega as cidades excluindo as repetidas
    public static void iniciaDados() throws Exception{
        gerenciarArquivo.abrirArquivo(0);
        imoveis = gerenciarArquivo.leituraImoveis();
        gerenciarArquivo.fecharArquivo(0);
        listaCidades();
       /* for (Imovel imovel : imoveis) 
            System.out.println(imovel.imprimirClasse());*/
    }
    
    //Pega a lista de cidades
    public static List<String> getCidades() {
        return cidades;
    }
     
   //Retorna uma lista de cidades
    //Adiciona a cidade apenas se ela não estiver na lista
    private static void listaCidades(){
        for (Imovel imovel : imoveis){
            if(!estaNaLista(imovel.getCidade()))
                cidades.add(imovel.getCidade());
        } 
    }
    
    //Verifica se a cidade já se encontra na lista
    private static boolean estaNaLista(String cidade){
        for (String cid : cidades){
            if(cid.equals(cidade))
                return true;
        } 
        return false;
    }

    //Recebe uma string de proprietário e retorna se possui ou não imoveis
    public static boolean q2ProcuraProprietario(String proprietario) {
        //System.out.println("Proprietário: " + proprietario);
        //Utiliza o iterador imovel para percorrer a lista
        for (Imovel imovel : imoveis) {
            //Compara se o proprietario do imovel atual é o mesmo que o desejado
            if (imovel.getProprietario().equals(proprietario)) {
                return true;
            }
        }
        return false;
    }

    //Função que filtra imoveis abaixo do valor passado
    public static List<Imovel> q3FiltraPeloValor(int valor) {
        List<Imovel> resultado = new ArrayList<>();
        //Utiliza o iterador imovel para percorrer a lista
        for (Imovel imovel : imoveis) {
            //Se o valor do imóvel atual for menor ou igual adicona esse imovel na lista de retorno
            if (imovel.getValor() <= valor) {
                resultado.add(imovel);
            }
        }
        return resultado;
    }

    //Retorna os imoveis que possuem a quantidade de quartos maior ou igual a passada
    public static List<Imovel> q4FiltraPorQuartos(int numeroDeQuartos) {
        List<Imovel> resultado = new ArrayList<>();
        //Utiliza o iterador imovel para percorrer a lista
        for (Imovel imovel : imoveis) {
            //Verifica se o imovel atual possui a quantidade de quartos maior ou igual
            if (imovel.getQuartos() >= numeroDeQuartos) {
                resultado.add(imovel);
            }
        }
        return resultado;
    }

    //Retorn uma lista de imoveis ordenados em ordem crescente de valor
    public static List<Imovel> q5FiltraPorTipo(String tipo) {
        String tipoCompleto = "backend." + tipo;
        List<Imovel> resultado = new ArrayList<>();

        //Utiliza o iterador imovel para percorrer a lista
        for (Imovel imovel : imoveis) {
            //Compara se o tipo do imovel atual é o mesmo que o desejado
            if (imovel.getClass().getName().equals(tipoCompleto)) {
                resultado.add(imovel);
            }
        }

        //Realiza a ordenação da lista
        Collections.sort(resultado);

        return resultado;
    }

    //Retorna uma lista de imoveis ordenados em ordem decrescente de valor em uma cidade específica
    public static List<Imovel> q6FiltraPorCidade(String cidade) {
        List<Imovel> resultado = new ArrayList<>();

         //Utiliza o iterador imovel para percorrer a lista
        for (Imovel imovel : imoveis) {
             //Compara se a cidade do imovel atual é o mesmo que o desejado
            if (imovel.getCidade().equals(cidade)) {
                resultado.add(imovel);
            }
        }

        //Ordena a lista de imoveis de forma reversa
        Collections.sort(resultado, Collections.reverseOrder());

        return resultado;
    }

    //Retorna uma lista de iteradores do tipo imovel
    //Os iteradores são especificos para o proprietario desejado
     public static ListIterator<Imovel> q7RetornarIteradores(String nome){
        List<Imovel> lista = new LinkedList<>();
        
         //Utiliza o iterador imovel para percorrer a lista
        for(Imovel imovel : imoveis){
             //Compara se o proprietario do imovel atual é o mesmo que o desejado
            if(imovel.getProprietario().equals(nome)){
                lista.add(imovel);
            }
        }
        
        //Pega uma lista de iteradores do imovel
        ListIterator<Imovel> iteradores = lista.listIterator();
        
        return iteradores;
    }
     
    //Imprime na tela os imoveis ou salvam em um arquivo de saida
    public static List<Imovel> q8EscreverArquivo(boolean opcao) {
        if (!opcao) {
            return imoveis;
        } else {
            try {
                //Se a opção for do arquivo, faz os processos para salva-lo
                gerenciarArquivo.abrirArquivo(1);
                gerenciarArquivo.adicionarImoveis(imoveis);
                gerenciarArquivo.fecharArquivo(1);
            } catch (Exception e) {
                System.out.println(e);
            }
            return null;
        }
    }
}