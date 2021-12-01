public class EmpregadoComissionado extends Empregado {
    private double vendas, comissao;

    EmpregadoComissionado(String n, String s, String d, double v, double c){
        super(n,s,d);
        setEmpregadoComissionado(v,c);
    }

    private void setEmpregadoComissionado(double v, double c) {
        vendas = v;
        comissao = c;
    }

    public double salario() {
        return vendas * comissao;
    }

    public String toString(){
        return String.format("%s\n%s: %.2f\n%s: %.2f\n%s: %.2f", super.toString(),
        "Vendas", vendas,
        "Comissao", comissao,
        "Salario", salario());
    }
    
}
