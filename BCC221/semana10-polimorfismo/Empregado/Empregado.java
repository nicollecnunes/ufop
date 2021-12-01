import javax.swing.text.Document;

public abstract class Empregado{
    private String nome;
    private String sobrenome;
    private String doc;

    public Empregado(String n, String s, String d){
        setEmpregado(n,s,d);
    }

    public void setEmpregado(String n, String s, String d){
        nome = n;
        sobrenome = s;
        doc = d;
    }

    public String toString(){
        return String.format("\n%s: %s\n%s: %s\n%s: %s", "Nome", nome,
        "Sobrenome", sobrenome, "Documento", doc);
    }

    public abstract double salario();
}