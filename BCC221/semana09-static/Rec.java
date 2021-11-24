public class Rec{
    private static int n = 0;

    public Rec(){
        // para cada objeto de Rec criado, o contador incrementa em 1
        // como o contador é static, todas as classes compartilham ele
        n++;
    }
    
    protected void finalize(){
        n--;
        System.out.println("Finalizou um obj");
    }

    public static int getRec(){
        return n;
    }
}