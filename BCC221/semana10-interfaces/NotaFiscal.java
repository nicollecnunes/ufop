public class NotaFiscal implements Pagavel{
    private String numeroPeca;
    private String descricaoPeca;
    private int qtd;
    private double precoPorItem;

    public NotaFiscal(String pe, String d, int n, double p){
        numeroPeca = pe;
        descricaoPeca = d;
        setQtd(n);
        setPrecoPorItem(p);    
    }

    public int getQtd() {
        return qtd;
    }

    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    public double getPrecoPorItem() {
        return precoPorItem;
    }

    public void setPrecoPorItem(double precoPorItem) {
        this.precoPorItem = precoPorItem;
    }

    public double getValorAPagar() {
        return getQtd() * getPrecoPorItem();
    }

    public String toString(){
        return String.format("\n%s\n%s: %s (%s)\n%s: %d\n%s: R$%.2f", "Nota",
        "Peça no", numeroPeca, descricaoPeca, "Qtd", getQtd(), "Ppitem", getPrecoPorItem());
    }
    
}
