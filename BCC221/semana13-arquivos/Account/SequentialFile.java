import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class SequentialFile {
    private ObjectOutputStream outp;

    public void openFile(){
        try {
            outp = new ObjectOutputStream(new FileOutputStream("clients.ser"));
        } catch (IOException e) {
            //TODO: handle exception
            System.err.println("Erros");
        }
    }

    public void addRecords(){
        AccountRecordSerializable rec;
        int account = 0;
        String fName;
        String lName;
        double balance;

        Scanner input = new Scanner(System.in);
        System.out.printf("%s\n%s", "enter acc num, fname, lname and balance", "? ");

        while(input.hasNext()){
            try {
                account = input.nextInt();
                fName = input.next();
                lName = input.next();
                balance = input.nextDouble();

                if (account > 0){
                    rec = new AccountRecordSerializable(account, fName, lName, balance);
                    outp.writeObject(rec);
                }
                else{
                    System.err.println("Erros");
                }
            } catch (IOException e) {
                System.err.println("Erros");
                return;
            } catch (NoClassDefFoundError e){
                System.err.println("Erros");
                input.nextLine();
            }
            System.out.printf("%s\n%s", "enter acc num, fname, lname and balance", "? ");
        }
    }

    public void closeFile(){
        try {
            if (outp != null)
                outp.close();
        } catch (IOException e){
            System.err.println("Erros");
            System.exit(1);
        }
    }
}
