import java.util.Comparator;

public class SortByName implements Comparator<Conta>{
    public int compare(Conta a, Conta b){
        return a.getNome().compareTo(b.getNome());
    }
    
}
