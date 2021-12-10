import java.util.List;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class CollectionTest {
    private static final String[] colors =  {"Magenta", "RED", "WHITE"};
    private static final String[] removeColors = {"RED"};

    public CollectionTest(){
        List<String> list = new ArrayList<String>();
        List<String> removeList =  new ArrayList<String>();

        for (String c : colors)
            list.add(c);

        for (String c : removeColors)
            removeList.add(c);

        System.out.println("ArrayList: ");

        for(int count = 0;  count < list.size(); count ++)
            System.out.printf("%s ", list.get(count)); 

        removeColors(list, removeList);

        System.out.println("\nArrayList AFTER: ");

        for (String c : list)
            System.out.printf("%s ", c);
    }

    private void removeColors(Collection<String> c1, Collection<String> c2){
        Iterator<String> it = c1.iterator();

        while(it.hasNext())
            if(c2.contains(it.next()))
                it.remove();
    }

    public static void main(String[] args){
        new CollectionTest();
    }
}
