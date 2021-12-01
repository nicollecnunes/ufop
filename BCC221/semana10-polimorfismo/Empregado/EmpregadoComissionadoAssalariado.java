public class EmpregadoComissionadoAssalariado extends EmpregadoComissionado{
    private double salarioMensal;

    EmpregadoComissionadoAssalariado(String n, String s, String d,
    double v, double c, double sM){
        super(n,s,d,v,c);
        setSalarioMensal(sM);
    }

    public void setSalarioMensal(double salarioMensal) {
        this.salarioMensal = salarioMensal;
    }

    public double getSalarioMensal() {
        return salarioMensal;
    }
    
    public double salario(){
        return getSalarioMensal() + super.salario();
    }

    public String toString(){
        return String.format("%s\n%s: %.2f", super.toString(),
        "Salario Mensal", salario());
    }
}
