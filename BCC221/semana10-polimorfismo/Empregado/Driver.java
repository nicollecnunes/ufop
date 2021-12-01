public class Driver {
    public static void main(String [] args){
        EmpregadoAssalariado ea = new EmpregadoAssalariado("John", "Assalariado", "111-11", 8000.0);
        EmpregadoHorista eh = new EmpregadoHorista("John", "Horista", "111-11", 8000.0, 40);
        EmpregadoComissionado ec = new EmpregadoComissionado("John", "Comissionado", "111-11", 8000.0, 0.06);
        EmpregadoComissionadoAssalariado eca = new EmpregadoComissionadoAssalariado("John", "ComissionadoAssalariado", "111-11", 8000.0, 0.06, 300);

        System.out.println("Individualmente");
        System.out.println(ea.salario());
        System.out.println(eh.salario());
        System.out.println(ec.salario());
        System.out.println(eca.salario());

        Empregado vetor[] = new Empregado[4];
        vetor[0] = ea;
        vetor[1] = eh;
        vetor[2] = ec;
        vetor[3] = eca;

        System.out.println("Polimorficamente");
        for (Empregado elem : vetor){
            System.out.println(elem);
            System.out.println();

            if (elem instanceof EmpregadoComissionadoAssalariado){
                EmpregadoComissionadoAssalariado tmp = (EmpregadoComissionadoAssalariado) elem;
                tmp.setSalarioMensal(tmp.getSalarioMensal() * 1.1);
                System.out.println(tmp);
            }
            System.out.println("Salario: " + elem.salario());
            System.out.println();
        }

    }
}
