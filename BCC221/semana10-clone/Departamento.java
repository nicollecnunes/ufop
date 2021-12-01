public class Departamento implements Cloneable{
    private int id;
    private String nome;

    public Departamento(){}

    public Departamento(int id, String nome){
        this.id = id;
        this.nome = nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return nome;
    }

    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public String toString(){
        return String.format("\n%s\n%s: %d\n%s: %s", "Dados departamento",
        "Id", getId(), "Nome", getNome());
    }

    public Object clone(){
        try{
            return super.clone();
        }
        catch(CloneNotSupportedException e){
            return null;
        }
    }

    public boolean equals(Object o){
        if (this == o) return true; // se é ele mesmo
        if (o == null) return false; // se nao existe
        if (getClass()!= o.getClass()) return false; // se for de classe diferente
        final Departamento cp = (Departamento) o; // transforma em departamento - cast explicito
        return (id == cp.getId() && nome.equals(cp.getNome())); // compara cada atributo
    }
}