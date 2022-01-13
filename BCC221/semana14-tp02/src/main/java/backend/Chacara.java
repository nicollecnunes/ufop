package backend;

public class Chacara extends Imovel {

    private boolean salao_festas;
    private boolean salao_jogos;
    private boolean campo_futebol;
    private boolean churrasqueira;
    private boolean piscina;

    //Construtor geral
    public Chacara(double valor, String proprietario, String rua, String bairro, String cidade, int numero, int quartos, int banheiros,
            boolean salao_festas, boolean salao_jogos, boolean campo_futebol, boolean churrasqueira, boolean piscina) {
        super(valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros);
        this.salao_festas = salao_festas;
        this.salao_jogos = salao_jogos;
        this.campo_futebol = campo_futebol;
        this.churrasqueira = churrasqueira;
        this.piscina = piscina;
    }

    //Construtor utilizando imovel e demais atributos
    public Chacara(Imovel imovel, boolean salao_festas, boolean salao_jogos, boolean campo_futebol, boolean churrasqueira, boolean piscina) {
        super(imovel);
        this.salao_festas = salao_festas;
        this.salao_jogos = salao_jogos;
        this.campo_futebol = campo_futebol;
        this.churrasqueira = churrasqueira;
        this.piscina = piscina;
    }

    //Construtor inicializando padrões
    public Chacara() {
        super(0.0, "", "", "", "", 0, 0, 0);
        this.salao_festas = false;
        this.salao_jogos = false;
        this.campo_futebol = false;
        this.churrasqueira = false;
        this.piscina = false;
    }

    public boolean isSalao_festas() {
        return salao_festas;
    }

    public void setSalao_festas(boolean salao_festas) {
        this.salao_festas = salao_festas;
    }

    public boolean isSalao_jogos() {
        return salao_jogos;
    }

    public void setSalao_jogos(boolean salao_jogos) {
        this.salao_jogos = salao_jogos;
    }

    public boolean isCampo_futebol() {
        return campo_futebol;
    }

    public void setCampo_futebol(boolean campo_futebol) {
        this.campo_futebol = campo_futebol;
    }

    public boolean isChurrasqueira() {
        return churrasqueira;
    }

    public void setChurrasqueira(boolean churrasqueira) {
        this.churrasqueira = churrasqueira;
    }

    public boolean isPiscina() {
        return piscina;
    }

    public void setPiscina(boolean piscina) {
        this.piscina = piscina;
    }

    //Sobreescrita do método toString
    @Override
    public String toString() {
        return super.toString() + "Piscina: " + (this.piscina ? "SIM" : "NAO");
    }

    //Sobreescrita do método que imprime atributos específicos da classe
    @Override
    public String imprimirClasse() {
        return super.toString() + "\n\tCaracterística Especifica\n"
                + "\t\tSalão de festas: " + (this.salao_festas ? "SIM" : "NAO")
                + "\n\t\tSalão de jogos: " + (this.salao_jogos ? "SIM" : "NAO")
                + "\n\t\tCampo de futebol: " + (this.campo_futebol ? "SIM" : "NAO")
                + "\n\t\tChurrasqueira: " + (this.churrasqueira ? "SIM" : "NAO");
    }
}
