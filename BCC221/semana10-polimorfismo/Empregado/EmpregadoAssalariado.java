public class EmpregadoAssalariado extends Empregado {
    private double salario;

    EmpregadoAssalariado(String n, String s, String d, double sal){
        super(n,s,d);
        setSalario(sal);
    }

    public void setSalario(double sal){
        salario = sal;
    }

    public double salario() {
        return salario;
    }

    public String toString(){
        return String.format("%s\n%s: %.2f", super.toString(), "Salario: ", salario);
    }
}
