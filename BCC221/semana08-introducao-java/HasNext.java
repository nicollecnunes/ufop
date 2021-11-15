import java.util.*;

public class HasNext
{
    public static void main(String[] args)
    {
        String s = "Hello world\n23";

        Scanner scanner = new Scanner(s);

        // check if the scanner has a token: [TRUE]
        System.out.println("Check if is there a token: " + scanner.hasNext());
        // print the rest of string: [HELLO WORLD]
        System.out.println("Print the rest: " + scanner.nextLine());
        //check if has a token after printing line [TRUE]
        System.out.println("Check if is there after: " + scanner.hasNextInt());
        // print rest [23]
        System.out.println("Print the rest again: " + scanner.nextLine());

    }
}