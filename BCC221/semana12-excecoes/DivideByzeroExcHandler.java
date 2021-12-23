import java.util.Scanner;

public class DivideByzeroExcHandler {
    public static int quotient(int n, int d) throws ArithmeticException{
        return n/d;
    }

    public static void main (String [] args){
        Scanner scanner = new Scanner(System.in);
        boolean continueLoop = true;

        do{
            try{
                System.out.print("Enter an int: ");
                int num = scanner.nextInt();

                System.out.print("Enter an int: ");
                int den = scanner.nextInt();

                int result = quotient(num, den);
                System.out.printf("\nResult: %d/%d = %d\n", num, den, result);
                continueLoop = false;
            }
            catch (ArithmeticException err){
                System.err.printf("\nExcp: %s\n", err);
                System.out.print("Divisao por 0, tente novamente\n: ");
            }
        }while(continueLoop);

        
    }
}
