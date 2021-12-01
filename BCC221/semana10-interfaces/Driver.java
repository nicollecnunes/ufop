public class Driver {
    public static void main (String [] args){
        Pagavel pag[] = new Pagavel[4];

        pag[0] = new NotaFiscal("1234", "banco", 2, 375.0);
        pag[1] = new NotaFiscal("1234", "pneu", 2, 375.0);
        pag[2] = new EmpregadoA("joao", "joao", "111111111", 375.0);
        pag[3] = new EmpregadoA("jaaaaoao", "aaa", "111111111", 375.0);

        for (Pagavel elem : pag) {
            System.out.printf("\n%s \n%s: R$.2f\n", elem.toString(), "Pag", elem.getValorAPagar());
        }
    }
}
