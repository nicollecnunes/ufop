package backend;

public class Casa extends Imovel {

    private int andares;
    private boolean sala_jantar;

     //Construtor geral
    public Casa(double valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros, int andares, boolean sala_jantar) {
        super(valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        this.andares = andares;
        this.sala_jantar = sala_jantar;
    }

    //Construtor utilizando imovel e demais atributos
    public Casa(Imovel imovel, int andares, boolean sala_jantar) {
        super(imovel);
        this.andares = andares;
        this.sala_jantar = sala_jantar;
    }

    //Construtor inicializando padrões 
    public Casa() {
        super(0.0, "", "", "", "", 0, 0, 0);
        this.andares = 0;
        this.sala_jantar = false;
    }

    public int getAndares() {
        return andares;
    }

    public void setAndares(int andares) {
        if (andares > 0) {
            this.andares = andares;
        }
    }

    public boolean isSala_jantar() {
        return sala_jantar;
    }

    public void setSala_jantar(boolean sala_jantar) {
        this.sala_jantar = sala_jantar;
    }

    //Sobreescrita do método toString
    @Override
    public String toString() {
        return super.toString() + "Andares: " + this.andares;
    }

    //Sobreescrita do método que imprime atributos específicos da classe
    @Override
    public String imprimirClasse() {
        return super.toString() + "\n\tCaracterística Especifica\n"
                + "\t\tAndares: " + this.andares
                + "\n\t\tTem sala de jantar: " + (this.sala_jantar ? "SIM" : "NAO");
    }
}
