import java.util.Vector;
import java.util.NoSuchElementException;

public class VectorTest{
    private static final String colors[] = {"red", "white", "blue"};

    public VectorTest(){
        Vector<String> vector = new Vector<String>();
        printVector(vector);

        for (String c : colors)
            vector.add(c);

        printVector(vector);

        try{
            System.out.printf("First: %s\n", vector.firstElement());
            System.out.printf("Last: %s\n", vector.lastElement());
        }
        catch(NoSuchElementException err){
            err.printStackTrace();
        }

        if(vector.contains("red"))
            System.out.printf("\nred found aat %d\n", vector.indexOf("red"));

        vector.remove("red");
        System.out.printf("\nSIZE: %d\n", vector.size());
        System.out.printf("\n capacity: %d\n", vector.capacity());
    }

    private void printVector(Vector<String> vector) {
        if(vector.isEmpty())
            System.out.print("\nempty");
        else{
            for (String c : vector)
            System.out.printf("%s ",c);
        }
        System.out.println();
    }

    public static void main (String args[]){
        new VectorTest();
    }
}