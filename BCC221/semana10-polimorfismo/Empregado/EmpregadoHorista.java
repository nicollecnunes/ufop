public class EmpregadoHorista extends Empregado{
    private double valor;
    private double horas;

    EmpregadoHorista(String n, String s, String d, double val, double h){
        super(n,s,d);
        setEmpregadoHorista(val, h);
    }

    private void setEmpregadoHorista(double val, double h) {
        valor = val;
        horas = h;
    }

    public double salario() {
        if (horas <= 40) return valor * horas;
        else return 40 * valor + (horas - 40) * valor * 1.5;
    }

    public String toString(){
        return String.format("%s\n%s: %.2f\n%s: %.2f\n%s: %.2f", super.toString(),
        "Horas", horas,
        "Valor/hora", valor,
        "Salario", salario());
    }
    
}
