package backend;

public class Apartamento extends Imovel {

    private int andar;
    private float taxa_condominio;
    private boolean elevador;
    private boolean sacada;
    
    //Construtor geral
    public Apartamento(double valor, String proprietario, String rua, String bairro, String cidade,
            int numero, int quartos, int banheiros, int andar, float taxa_condominio, boolean elevador,
            boolean sacada) {
        super(valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        this.andar = andar;
        this.taxa_condominio = taxa_condominio;
        this.elevador = elevador;
        this.sacada = sacada;
    }

    //Construtor utilizando imovel e demais atributos
    public Apartamento(Imovel imovel, int andar, float taxa_condominio, boolean elevador, boolean sacada) {
        super(imovel);
        this.andar = andar;
        this.taxa_condominio = taxa_condominio;
        this.elevador = elevador;
        this.sacada = sacada;
    }

    //Construtor inicializando padrões 
    public Apartamento() {
        super(0.0, "", "", "", "", 0, 0, 0);
        this.andar = 0;
        this.taxa_condominio = 0;
        this.elevador = false;
        this.sacada = false;
    }

    public int getAndar() {
        return andar;
    }

    public void setAndar(int andar) {
        if (andar > 0) {
            this.andar = andar;
        }
    }

    public float getTaxa_condominio() {
        return taxa_condominio;
    }

    public void setTaxa_condominio(float taxa_condominio) {
        if (taxa_condominio > 0) {
            this.taxa_condominio = taxa_condominio;
        }
    }

    public boolean isElevador() {
        return elevador;
    }

    public void setElevador(boolean elevador) {
        this.elevador = elevador;
    }

    public boolean isSacada() {
        return sacada;
    }

    public void setSacada(boolean sacada) {
        this.sacada = sacada;
    }

    //Sobreescrita do método toString
    @Override
    public String toString() {
        return super.toString() + "Elevador: " + (this.elevador ? "SIM" : "NAO");
    }

    //Sobreescrita do método que imprime atributos específicos da classe
    @Override
    public String imprimirClasse() {
        return super.toString() + "\n\tCaracterística Especifica\n"
                + "\t\tAndar: " + this.andar
                + "\n\t\tTaxa de condominio: " + this.taxa_condominio
                + "\n\t\tElevador: " + (this.elevador ? "SIM" : "NAO")
                + "\n\t\tSacada: " + (this.sacada ? "SIM" : "NAO");
    }
}
