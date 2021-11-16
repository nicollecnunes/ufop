public class VetorBi {
    public static void main(String args[])
    {
        // matriz estatica
        int [][] tabuleiro =  new int[8][8];
        int [][] dinamico;

        // aloca a primeira dimensao
        dinamico =  new int[10][];

        // aloca a segunda dimensao
        for (int i = 0; i< dinamico.length; i++){
            dinamico[i] = new int [i +1];
        }
    }
    
}
