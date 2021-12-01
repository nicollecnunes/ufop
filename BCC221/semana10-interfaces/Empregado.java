public abstract class Empregado implements Pagavel{
    public String nome, sobrenome, doc;

    public Empregado(String n, String s, String d){
        nome = n;
        sobrenome = s;
        doc = d;
    }

    public String toString(){
        return String.format("\n%s %s\n%s: %s", nome, sobrenome, "Doc", doc);
    }
    
}
