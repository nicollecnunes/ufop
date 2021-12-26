import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.FormatterClosedException;;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class TestFile {
    private Formatter output;

    public void openFile(){
        try {
            // se existir, vai sobrescrever
            output = new Formatter("clients.txt");
            // se nao quiser assim,tem que usar:
            // append...
            //output = new Formatter(FileWriter("clients.txt", true))
        } catch (SecurityException e) {
            System.err.println("You do not have access");
            System.exit(1);
        } catch (FileNotFoundException e) {
            System.err.println("Error creating file");
            System.exit(1);
        }
    }

    public void addRecord(){
        AccountRecord rec = new AccountRecord();
        Scanner input = new Scanner(System.in);

        System.out.printf("%s\n%s\n%s\n%s\n\n",
        "To terminate input, type EOF indicator",
        "when ur prompted to enter input",
        "on UNIX/LINUX/MAC OS x Type ctrl d then press enter",
        "On windows ctrl z then enter");

        System.out.printf("%s\n%s", "enter acc number, fname, lname and balance", "? ");
        while (input.hasNext()) {
            try {
                rec.setAccount(input.nextInt());
                rec.setFName(input.next());
                rec.setLName(input.next());
                rec.setBalance(input.nextDouble());

                if (rec.account > 0){
                    output.format("%d %s %s %.2f\n'", 
                    rec.account, rec.fName, rec.lName, rec.balance);
                } else {
                    System.out.println("acc number bust be > 0");
                }
            } catch (FormatterClosedException e) {
                System.out.println("error writing");
                return;
            } catch (NoSuchElementException e ){
                System.out.println("invalid input");
                input.nextLine(); // descarta a entrada
                // p o usuario tentar de novo
            }
            System.out.printf("%s\n%s", "enter acc number, fname, lname and balance", "? ");

        }
    }

    public void closeFile(){
        if (output!=null){
            output.close();
        }
    }

    /*public static void main(String [] a){
        TestFile app = new TestFile();

        app.openFile();
        app.addRecord();
        app.closeFile();
    }*/
}
