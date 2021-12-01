
public class EmpregadoA extends Empregado {
    private double salario;

    public EmpregadoA(String n, String s, String d, double sal){
        super(n,s,d);
        salario = sal;
    }

    public double getValorAPagar() {
        return salario;
    }

    public String toString(){
        return String.format("\n%s %s\n%s: R$%.2f", "E.A.", super.toString(), "Salario", salario);
    }
    
}
