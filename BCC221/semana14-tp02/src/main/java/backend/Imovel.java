package backend;

public abstract class Imovel implements Comparable<Imovel> {

    protected double valor;
    protected String proprietario;
    protected String rua;
    protected String bairro;
    protected String cidade;
    protected int numero;
    protected int quartos;
    protected int banheiros;

    //Construtor geral
    public Imovel(double valor, String proprietario, String rua, String bairro, String cidade,
            int numero, int quartos, int banheiros) {
        this.valor = valor;
        this.proprietario = proprietario;
        this.rua = rua;
        this.bairro = bairro;
        this.cidade = cidade;
        this.numero = numero;
        this.quartos = quartos;
        this.banheiros = banheiros;
    }

    //Construtor utilizando imovel
    public Imovel(Imovel imovel) {
        this.valor = imovel.valor;
        this.proprietario = imovel.proprietario;
        this.rua = imovel.rua;
        this.bairro = imovel.bairro;
        this.cidade = imovel.cidade;
        this.numero = imovel.numero;
        this.quartos = imovel.quartos;
        this.banheiros = imovel.banheiros;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        if (valor >= 0) {
            this.valor = valor;
        }
    }

    public String getProprietario() {
        return proprietario;
    }

    public void setProprietario(String proprietario) {
        if (proprietario.length() > 5) {
            this.proprietario = proprietario;
        }
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        if (rua.length() > 5) {
            this.rua = rua;
        }
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        if (bairro.length() > 5) {
            this.bairro = bairro;
        }
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        if (cidade.length() > 5) {
            this.cidade = cidade;
        }
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        if (numero > 0) {
            this.numero = numero;
        }
    }

    public int getQuartos() {
        return quartos;
    }

    public void setQuartos(int quartos) {
        if (quartos > 0) {
            this.quartos = quartos;
        }
    }

    public int getBanheiros() {
        return banheiros;
    }

    public void setBanheiros(int banheiros) {
        if (banheiros > 0) {
            this.banheiros = banheiros;
        }
    }

    //Sobreescrita do método toString
    @Override
    public String toString() {
        return "---------------------------------------<br>"
                + "Proprietario: " + this.proprietario + "<br>"
                + "Preco: " + this.valor + "<br>"
                + "Quartos: " + this.quartos + "<br>"
                + "Rua: " + this.rua + "<br>"
                + "Bairro: " + this.bairro + "<br>"
                + "Cidade: " + this.cidade + "<br>";
    }

    //Sobreescrita do operador < 
    //Define uma nova maneira de comparar se imóvel é maior que o outro por meio do valor
    @Override
    public int compareTo(Imovel o) {
        if (this.getValor() < o.getValor()) {
            return -1;
        } else if (o.getValor() < this.getValor()) {
            return 1;
        } else {
            return 0;
        }
    }

    //Declaração do método abstrato para imprimir atributos específicos da classe
    public abstract String imprimirClasse();
}
