import javax.swing.JOptionPane;

public class AdicaoGUI
{
    public static void main(String args[])
    {
        String n1S, n2S;
        int n1I, n2I, sum;

        // captura
        n1S = JOptionPane.showInputDialog("Enter first int");
        n2S = JOptionPane.showInputDialog("Enter second int");

        // conversao
        n1I = Integer.parseInt(n1S);
        n2I = Integer.parseInt(n2S);

        // soma
        sum =  n1I + n2I;

        // mostra
        JOptionPane.showMessageDialog(null, "The sum is " + sum, "Results", JOptionPane.PLAIN_MESSAGE);

        System.exit(0);
    }
}