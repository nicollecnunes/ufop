import java.util.Scanner;

public class DriverGradeBook {
    public static void main (String args[])
    {
        GradeBook meuDiario =  new GradeBook();
        Scanner in = new Scanner(System.in);

        System.out.print("Digite o nome do curso: ");
        String nome = in.nextLine();
        
        meuDiario.displayMessage(nome);
    }
}
