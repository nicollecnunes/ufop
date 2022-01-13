package backend;

import static backend.FuncoesTopicos.imoveis;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.FormatterClosedException;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class GerenciarArquivo {

    //Objeto utilizado para gerar saída de texto no arquivo
    private Formatter output;
    private Scanner input;

    public void abrirArquivo(int modo) throws Exception {
        try {
            //Verifica o modo de abertura do arquivo
            //Caso modo == 1 será saída, caso contrário entrada
            if(modo == 1){
                output = new Formatter("saida.txt");
            } else if(modo == 0){
                input = new Scanner(new File("database_imoveis.txt"));
            }
            //Verifica se há alguma excessão na criação do arquivo
        } catch (SecurityException e) {
            throw new Exception("Não há permissão de escrita!");
            //Retorna uma excessao caso não seja encontrado o arquivo
        } catch (FileNotFoundException e) {
            throw new Exception("Erro na criação do arquivo!");
        }
    }

    //Cria um arquivo de saida com os dados dos imóveis 
    public void adicionarImoveis(List<Imovel> imoveis) throws Exception {
        for (Imovel imovel : imoveis) {
            //Faz a escrita no arquivo de forma diferente para cada instância da classe Imovel
            try {
                if (imovel instanceof Casa) {
                    //Utiliza a escrita em um formato diferente para cada tipo de imóvel
                    //Realizamos o cast do tipo para não gerar algum tipo de problema 
                    output.format("%s\n%.2f\n%s\n%s\n%s\n%d\n%d\n%b\n\n", ((Casa) imovel).getProprietario(),
                            ((Casa) imovel).getValor(), ((Casa) imovel).getRua(), ((Casa) imovel).getBairro(),
                            ((Casa) imovel).getCidade(), ((Casa) imovel).getNumero(), ((Casa) imovel).getAndares(), ((Casa) imovel).isSala_jantar());
                } else if (imovel instanceof Apartamento) {
                    //Realiza as mesmas operações descritas acima
                    output.format("%s\n%.2f\n%s\n%s\n%s\n%d\n%d\n%.2f\n%b\n%b\n\n", ((Apartamento) imovel).getProprietario(),
                            ((Apartamento) imovel).getValor(), ((Apartamento) imovel).getRua(), ((Apartamento) imovel).getBairro(),
                            ((Apartamento) imovel).getCidade(), ((Apartamento) imovel).getNumero(), ((Apartamento) imovel).getAndar(), ((Apartamento) imovel).getTaxa_condominio(),
                            ((Apartamento) imovel).isElevador(), ((Apartamento) imovel).isSacada());
                } else if (imovel instanceof Chacara) {
                    output.format("%s\n%.2f\n%s\n%s\n%s\n%d\n%b\n%b\n%b\n%b\n%b\n\n", ((Chacara) imovel).getProprietario(),
                            ((Chacara) imovel).getValor(), ((Chacara) imovel).getRua(), ((Chacara) imovel).getBairro(),
                            ((Chacara) imovel).getCidade(), ((Chacara) imovel).getNumero(), ((Chacara) imovel).isSalao_festas(), ((Chacara) imovel).isSalao_jogos(),
                            ((Chacara) imovel).isCampo_futebol(), ((Chacara) imovel).isChurrasqueira(), ((Chacara) imovel).isPiscina());
                } else {
                    //Retorna uma excessão caso o tipo de imóvel seja inválido
                    throw new Exception("Tipo de imóvel " + imovel.getClass() + " não é válido!\n");
                }
              //Retorna uma excessão caso aconteça algum erro na escrita
            } catch (FormatterClosedException e) {
                 throw new Exception("Erro na escrita do arquivo!");
              //Retorna uma excessão caso o dados esperado não seja correspondente 
            } catch (NoSuchElementException e) {
                throw new Exception("Entrada inválida!");
            }
        }
    }
    
    //Função para ler os imóveis do arquivo base
    public List<Imovel> leituraImoveis() throws Exception{
         List<Imovel> imoveis = new ArrayList<>();
         
         //Declaração de variáveis que serão utilizadas no processo de leitura
         String linha, dados[];
         
         try{
             //Enquanto houver dados irá manipulá-los
             while(input.hasNext()){
                 //Pega a linha completa do arquivo
                 linha = input.nextLine();
                 //Inserimos os dados separados pelo operador ';' em um array
                 dados = linha.split(";");
                 
                 //Verifica o tipo de cada imóvel para tomar as decisões de acordo com o tipo
                 //Como o array é do tipo String, precisamos realizar a conversao dos dados
                 if(dados[0].equals("casa")){
                    Casa casa = new Casa();
                    //Converte o dado para float
                    casa.setValor(Float.parseFloat(dados[1]));
                    casa.setProprietario(dados[2]);
                    casa.setRua(dados[3]);
                    casa.setBairro(dados[4]);
                    casa.setCidade(dados[5]);
                    //Converte o dado para int
                    casa.setNumero(Integer.parseInt(dados[6]));
                    casa.setQuartos(Integer.parseInt(dados[7]));
                    casa.setBanheiros(Integer.parseInt(dados[8]));
                    casa.setAndares(Integer.parseInt(dados[9]));
                    //O arquivo contém o tipo int para designar true ou false, por isso fazemos essa validação
                    if(Integer.parseInt(dados[10]) == 1){
                        casa.setSala_jantar(true);
                    } else {
                        casa.setSala_jantar(false);
                    }
                    //Insere o imóvel na lista de imóveis 
                    imoveis.add(casa);
                   //O processo descrito acima é realizado para os demais tipos de imóveis
                 } else if(dados[0].equals("apartamento")){
                    Apartamento apt = new Apartamento();
                    apt.setValor(Float.parseFloat(dados[1]));
                    apt.setProprietario(dados[2]);
                    apt.setRua(dados[3]);
                    apt.setBairro(dados[4]);
                    apt.setCidade(dados[5]);
                    apt.setNumero(Integer.parseInt(dados[6]));
                    apt.setQuartos(Integer.parseInt(dados[7]));
                    apt.setBanheiros(Integer.parseInt(dados[8]));
                    apt.setAndar(Integer.parseInt(dados[9]));
                    apt.setTaxa_condominio(Float.parseFloat(dados[10]));
                    if(Integer.parseInt(dados[11]) == 1){
                        apt.setElevador(true);
                    } else {
                        apt.setElevador(false);
                    }
                    if(Integer.parseInt(dados[12]) == 1){
                        apt.setSacada(true);
                    } else {
                        apt.setSacada(false);
                    }
                    imoveis.add(apt);
                 } else if(dados[0].equals("chacara")){
                    Chacara chacara = new Chacara();
                    chacara.setValor(Float.parseFloat(dados[1]));
                    chacara.setProprietario(dados[2]);
                    chacara.setRua(dados[3]);
                    chacara.setBairro(dados[4]);
                    chacara.setCidade(dados[5]);
                    chacara.setNumero(Integer.parseInt(dados[6]));
                    chacara.setQuartos(Integer.parseInt(dados[7]));
                    chacara.setBanheiros(Integer.parseInt(dados[8]));
                    if(Integer.parseInt(dados[9]) == 1){
                        chacara.setSalao_festas(true);
                    } else {
                        chacara.setSalao_festas(false);
                    }
                    if(Integer.parseInt(dados[10]) == 1){
                        chacara.setSalao_jogos(true);
                    } else {
                        chacara.setSalao_jogos(false);
                    }
                    if(Integer.parseInt(dados[11]) == 1){
                        chacara.setCampo_futebol(true);
                    } else {
                        chacara.setCampo_futebol(false);
                    }
                    if(Integer.parseInt(dados[12]) == 1){
                        chacara.setChurrasqueira(true);
                    } else {
                        chacara.setChurrasqueira(false);
                    }
                    if(Integer.parseInt(dados[13]) == 1){
                        chacara.setPiscina(true);
                    } else {
                        chacara.setPiscina(false);
                    }                     
                    imoveis.add(chacara);
                }
            }
         //Erro se as informações no arquivo não estierem adequadamente formatadas
         } catch(NoSuchElementException e){
            throw new Exception("Informações do arquivo mal formatadas!");
         }
         //Erro se o Scanner foi fechado antes de dos dados serem inseridos
         catch(IllegalStateException e){
            throw new Exception("Erro de leitura no arquivo");
        }         
         
        return imoveis;
    }

    //Função para fechar o arquivo aberto
    public void fecharArquivo(int modo) {
        if(modo == 1){
            if (output != null)
                output.close();
        } else{
            if(input != null)
                input.close();
        }        
    }
}
