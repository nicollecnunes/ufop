import java.util.Arrays;

public class UsingArrays{
    private int intArray[] = {1,2,3,4};
    private double doubleArray[] = { 2.2, 1.1, 3.3, 4.4};
    private int filledIntArray[], intArrayCopy[];

    public UsingArrays(){
        filledIntArray = new int[10];
        intArrayCopy =  new int[intArray.length];

        Arrays.fill(filledIntArray, 7); //preenche com 7s
        Arrays.sort(doubleArray); // ordena crescentemente

        // preenche -> posicao 0 
        System.arraycopy(intArray, 0, intArrayCopy, 0, intArray.length);
    }

    public void printArrays(){
        System.out.print("DOUBLE: ");
        for (double dV : doubleArray)
            System.out.printf("%.1f ", dV);

        System.out.print("INT: ");
        for (int dV : intArray)
            System.out.printf("%d ", dV);

        System.out.print("FILLED INT: ");
        for (int dV : filledIntArray)
            System.out.printf("%d ", dV);

        System.out.print("COPY INT: ");
        for (int dV : intArrayCopy)
            System.out.printf("%d ", dV);

        System.out.println();        
    }

    public int searchForInt(int v){
        return Arrays.binarySearch(intArray, v);
    }

    public void printEquality(){
        boolean b =  Arrays.equals(intArray, intArrayCopy);
        System.out.printf("intArray %s intArrayCopy\n", (b ? "==" : "!="));

        b = Arrays.equals(intArray, filledIntArray);
        System.out.printf("intArray %s filledIntArray\n", (b ? "==" : "!="));
    }

    public static void main(String args[]){
        UsingArrays uA = new UsingArrays();
        uA.printArrays();
        uA.printEquality();

        int loc = uA.searchForInt(5);
        if (loc >= 0)
            System.out.printf("found 5 element at %d in intArray", loc);
        else
        System.out.print("notfound");

    }
}