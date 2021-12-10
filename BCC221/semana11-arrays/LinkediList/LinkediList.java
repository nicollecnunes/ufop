import java.util.List;
import java.util.LinkedList;
import java.util.ListIterator;

public class LinkediList {
    private static final String colors[] = {"black", "yellow", "green", "blue", "violet"};
    private static final String colors2[] = {"gold", "white", "brown", "blue", "silver"};

    public LinkediList(){
        List<String> l1 = new LinkedList<String>();
        List<String> l2 = new LinkedList<String>();

        for (String co : colors)
            l1.add(co);
            
        for (String co : colors2)
            l2.add(co);

        l1.addAll(l2); // concatena
        l2 = null; // livbera

        printList(l1);
        convertToUppecaseStrings(l1);
        printList(l1);

        System.out.println("Deleting 2 to 5");
        removeItems(l1, 2, 5);
        printList(l1);

        printReversedList(l1);
    }

    // passada por referencia
    private void convertToUppecaseStrings(List<String> l1) {
        ListIterator<String> it = l1.listIterator();

        while(it.hasNext()){
            String co = it.next();
            it.set(co.toUpperCase());
        }
    }

    private void removeItems(List<String> l1, int i, int j) {
        l1.subList(i, j).clear();
    }

    private void printReversedList(List<String> l1) {
        ListIterator<String> it = l1.listIterator();

        while(it.hasPrevious()){
            System.out.printf("%s " , it.previous());
        }
    }

    private void printList(List<String> l1) {
        System.out.println("List");

        for (String co : l1)
            System.out.printf("%s ", co);

        System.out.println();
    }

    public static void main(String args[]){
        new LinkediList();
    }
}
