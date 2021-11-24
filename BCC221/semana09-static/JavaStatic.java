public class JavaStatic {
    public static void main(String [] args){
        // pode ser chamado pela propria classe "Rec"
        System.out.println("Variavel estatica: " + Rec.getRec()); //0

        Rec r1 = new Rec();
        Rec r2 = new Rec();
        Rec r3 = new Rec();

        System.out.println("Variavel estatica: " + Rec.getRec()); //3

        r1 = null;
        r2 = null;
        r3 = null;
        System.gc(); // garbage collector

        System.out.println("Variavel estatica: " + Rec.getRec()); // 3
        // ele executa o gc depois, pois nao temos controle sob ele
        
    }
}
