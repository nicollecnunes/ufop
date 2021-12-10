import java.util.LinkedList;
import java.util.Arrays;
import java.util.Iterator;

public class UsingToArray {
    public UsingToArray(){
        String colors[] = {"black", "blue", "yellow"};

        LinkedList<String> lk = new LinkedList<String>(Arrays.asList(colors));

        lk.addLast("red");
        lk.add("pink");
        lk.add(3, "green"); //indice 3
        lk.addFirst("cyan");

        colors = lk.toArray(new String[lk.size()]);

        System.out.println("Colors: ");
        for (String c : colors)
            System.out.printf("%s ", c); 


        System.out.println("\n\nLinks: ");
        Iterator<String> it = lk.iterator();
        while(it.hasNext())
            System.out.printf("%s ", it.next()); 
    }

    public static void main(String args[]){
        new UsingToArray();
    }
    
}
