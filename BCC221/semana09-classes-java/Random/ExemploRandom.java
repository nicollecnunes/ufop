import java.util.*;

public class ExemploRandom {

    public static void myRandomMath(int m_ini, int m_final){
        int tot = (m_final - m_ini) + 1; // total de elementos
        int n;
        int hist[] = new int[tot]; // contabiliza a frequencia

        for (int i = 0; i < 10000; i++){
            n = (int)(Math.random() * (m_final-m_ini+1) + m_ini);
            hist[n-m_ini]++;
        }
        print(hist);
    }

    public static void myRandomClass(int m_ini, int m_final){
        int tot = (m_final - m_ini) + 1; // total de elementos
        int n;
        int hist[] = new int[tot]; // contabiliza a frequencia

        Random numRandom =  new Random();

        for (int i = 0; i < 10000; i++){
            n = numRandom.nextInt(tot);
            hist[n-m_ini]++;
        }
        print(hist);
    }

    public static void print(int[] v){
        for (int elem : v)
            System.out.println(elem + " ");
    }

    public static void main(String [] args){
        System.out.println("Frequencia com Math: ");
        myRandomMath(5, 10);

        System.out.println("Frequencia com Class: ");
        myRandomClass(5, 10);
    }
}
