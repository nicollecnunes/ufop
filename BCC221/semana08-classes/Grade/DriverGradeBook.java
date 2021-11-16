import java.util.Scanner;

import javax.sound.sampled.SourceDataLine;
import javax.swing.plaf.synth.SynthOptionPaneUI;

public class DriverGradeBook {
    public static void main (String args[])
    {
        GradeBook meuDiario =  new GradeBook();
        System.out.printf("O nome do  curso inicialmente e: %s\n\n", meuDiario.getNomeCurso());

        Scanner in = new Scanner(System.in);
        System.out.print("Digite o nome do curso: ");
        String nome = in.nextLine();

        meuDiario.setNomeCurso(nome);
        meuDiario.displayMessage(meuDiario.getNomeCurso());
    }
}
