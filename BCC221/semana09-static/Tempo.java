public class Tempo {
    private int h,m,s;

    public Tempo(){
        h = m = s = 0;
    }

    public Tempo(int hora){
        h = hora;
        m = s = 0;
    }

    public Tempo(int hora,int minuto){
        h = hora;
        m = minuto;
        s = 0;
    }

    public Tempo(int hora,int minuto, int segundo){
        h = hora;
        m = minuto;
        s = segundo;
    }

    public int Tempo(){
        // construtor falso. memso nome mas possui retorno
        // mesmo que seja void
        return 1;
    }

    public static void main(String args[]){
        Tempo t = new Tempo();
        Tempo t2 = new Tempo(12);
        Tempo t3 = new Tempo(12, 30);
        Tempo t4 = new Tempo(12, 30, 00);

    }
}
