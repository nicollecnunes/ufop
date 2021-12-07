public class BaseComissionado extends Comissionado{
    private double salarioBase;

    public BaseComissionado(double salarioBase, String fName, String lName, String ssn, double vendaBruta, double taxaComissao) {
        super(fName, lName, ssn, vendaBruta, taxaComissao);
        setSalarioBase(salarioBase);
    }

    public double getSalarioBase() {
        return salarioBase;
    }

    public void setSalarioBase(double salarioBase) {
        this.salarioBase = salarioBase;
    }

    public double ganhos(){
        return super.ganhos() + getSalarioBase();
    }

    public String toString(){
        return String.format("%s\n%s\n%s: %.2f", "Comissionado com salario base",
        super.toString(), "Salario base", getSalarioBase());
    }
    
}
