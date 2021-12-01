public class DriverEmpregado {
    public static void main(String [] args){
        Departamento dep = new Departamento(1, "Decom");
        Empregado emp = new Empregado(101, "Marcio", dep);
        Empregado novo;

        novo = emp; // as duas refernciam a mesma posicao de memoria

        if (novo == emp) 
            System.out.println("Iguais"); // sim, pois apontam p a mesma memoria
        else 
            System.out.println("Nao iguais");

        novo.setEmpregadoNome("Gisele");

        System.out.println(novo); // Gisele
        System.out.println(emp); // Gisele

        Empregado novo2 = (Empregado)emp.clone();
        novo2.setDepartamentoNome("DEMAT");
        novo2.setEmpregadoNome("Nicolle");

        System.out.println(novo2); // nicolle
        System.out.println(emp); // gisele

        Empregado novo3 = (Empregado)emp.clone();
        if (emp.equals(novo3))
            System.out.println("coonteudos Iguais");
        else
            System.out.println("coonteudos Nao iguais");
    }
    
}
