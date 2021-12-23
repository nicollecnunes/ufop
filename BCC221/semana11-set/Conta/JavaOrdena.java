import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class JavaOrdena {
    public static void main(String [] args){
        List<Conta> contas = new ArrayList<>();

        Conta obj1 = new Conta(266, "Marco");
        Conta obj2 = new Conta(26, "Pedro");
        Conta obj3 = new Conta(106, "Andre");

        contas.add(obj1);
        contas.add(obj2);
        contas.add(obj3);

        // ordena por codigo
        System.out.println("ORDENANDO POR CODIGO: ");
        Collections.sort(contas);
        for (Conta elem : contas)
            System.out.println(elem);

        // ordena por nome
        System.out.println("ORDENANDO POR NOME: ");
        Collections.sort(contas, new Comparator<Object>() {
            public int compare(Object o1, Object o2){
                String nome1 = ((Conta)o1).getNome();
                String nome2 = ((Conta)o2).getNome();
                return nome1.compareTo(nome2);
            }
        });


        System.out.println("ORDENANDO POR NOME: ");
        Collections.sort(contas, new SortByName());
        for (Conta elem : contas)
            System.out.println(elem);   
      
    }

}
