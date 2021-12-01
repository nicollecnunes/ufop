import java.util.Random;

public class Oficina {
    private int R = 0;

    public Veiculo proximo(){
        Veiculo v;
        Random r = new Random();
        R = r.nextInt(2);

        if (R == 0) v = new Automovel();
        else v = new Bicicleta();

        return v;
    }

    public void manter(Veiculo v){ // sempre passa por ref quando não é primitivo
        System.out.println("\n------------------");
        v.verificaLista();
        v.reparar();
        v.limpa();
        System.out.println("------------------");
    }

    public int getR(){
        return R;
    }

    public static void main (String [] args){
        Oficina ofc = new Oficina();
        Veiculo vec;

        for (int i = 0; i < 4; i ++){
            vec = ofc.proximo();
            ofc.manter(vec);
        }
    }
}
