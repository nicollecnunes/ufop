package backend;

import GUI.Menu;
import java.util.ListIterator;

public class Main {

    public static void main(String[] args) {
        System.out.print("Iniciando sistema...");
        
        //Utiliza o try-catch para imprimir os erros provenientes da manipulação de arquivos
        try{
            FuncoesTopicos.iniciaDados();
        } catch(Exception e){
            e.printStackTrace();
        }
        
        //Chamada do menu
        new Menu().setVisible(true);
    }
}
