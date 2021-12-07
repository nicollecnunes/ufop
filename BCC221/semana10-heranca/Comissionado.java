public class Comissionado{
    private String fName;
    private String lName;
    private String ssn;

    private double vendaBruta;
    private double taxaComissao;

    public Comissionado(String fName, String lName, String ssn,
    double vendaBruta, double taxaComissao){
        this.setfName(fName);
        this.setlName(lName);
        this.setSsn(ssn);
        
        setVendaBruta(vendaBruta);
        setTaxaComissao(taxaComissao);
    }

    public double getVendaBruta() {
        return vendaBruta;
    }

    public void setVendaBruta(double vendaBruta) {
        this.vendaBruta = vendaBruta;
    }

    public double getTaxaComissao() {
        return taxaComissao;
    }

    public void setTaxaComissao(double taxaComissao) {
        this.taxaComissao = taxaComissao;
    }

    public String getSsn() {
        return ssn;
    }

    public void setSsn(String ssn) {
        this.ssn = ssn;
    }

    public String getlName() {
        return lName;
    }

    public void setlName(String lName) {
        this.lName = lName;
    }

    public String getfName() {
        return fName;
    }

    public void setfName(String fName) {
        this.fName = fName;
    }

    public double ganhos(){
        return getTaxaComissao() * getVendaBruta();
    }

    public String toString(){
        return String.format("%s: %s %s\n%s: %s\n%s: %.2f\n%s: %.2f",
        "Comissionado", getfName(), getlName(), "SSN", getSsn(), "Vendas",
        getVendaBruta(), "Taxa de Comissao", getTaxaComissao());
    }
}