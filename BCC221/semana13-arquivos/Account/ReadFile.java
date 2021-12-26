import java.io.File;
import java.io.FileNotFoundException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class ReadFile {
    private Scanner input;

    public void openFile(){
        try {
            input = new Scanner(new File("clients.txt"));
        } catch (FileNotFoundException e) {
            System.err.println("error");
            System.exit(1);
        }
    }

    public void readRecords(){
        AccountRecord  rec = new AccountRecord();
        System.out.printf("%-10s%-12s%-12s%10s\n",
        "Account", "First Name", "Last Name", "Balance");

        try {
            while(input.hasNext()){
                rec.setAccount(input.nextInt());
                rec.setFName(input.next());
                rec.setLName(input.next());
                rec.setBalance(input.nextDouble());

                System.out.printf("%-10d%-12s%-12s%10.2f\n",
                rec.account, rec.fName, rec.lName, rec.balance);
            }
        } catch (NoSuchElementException e) {
            System.err.println("error");
            input.close();
            System.exit(1);
        } catch (IllegalStateException e) {
            System.err.println("error");
            System.exit(1);
        }
    }

    public void closeFile(){
        if(input != null)
            input.close();
    }

    public static void main(String [] a){
        ReadFile app = new ReadFile();

        app.openFile();
        app.readRecords();
        app.closeFile();
    }
    
}
