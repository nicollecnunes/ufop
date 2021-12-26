import java.io.Serializable;

public class AccountRecordSerializable implements Serializable {
    public int account;
    public String fName;
    public String lName;
    public double balance;

    public AccountRecordSerializable(){
        this(0,"","",0.0);
    }

    public AccountRecordSerializable(int i, String string, String string2, double d) {
        setAccount(i);
        setFName(string);
        setLName(string2);
        setBalance(d);
    }

    public void setBalance(double d) {
        balance = d;
    }

    public void setLName(String string2) {
        lName = string2;
    }

    public void setFName(String string) {
        fName = string;
    }

    public void setAccount(int i) {
        account = i;
    }


}
