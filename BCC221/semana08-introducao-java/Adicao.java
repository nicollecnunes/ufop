import java.util.Scanner;

public class Adicao
{
    public static void main(String args[])
    {
        Scanner entrada = new Scanner(System.in);

        int n1, n2, soma;

        System.out.print("Informe o primeiro numero: ");
        n1 = entrada.nextInt();

        System.out.print("Informe o segundo numero: ");
        n2 = entrada.nextInt();

        soma = n1 + n2;
        System.out.printf("A soma e %d\n", soma);
    }
}