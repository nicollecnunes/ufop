public class VarArgs {
    public static double media(double ... numeros)
    {
        double total = 0;
        for (double d : numeros)
        {
            total = total + d;
        }
        return total/numeros.length;
    }
    


    public static void main(String args[])
    {
        double d1 = 10.0;
        double d2 = 1.0;
        double d3 = 15.0;
        double d4 = 99.0;

        System.out.printf("Media: %f", media(d1,d2,d3,d4));
    }


}