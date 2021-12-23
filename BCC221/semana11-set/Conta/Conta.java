public class Conta implements Comparable<Conta>{
    private int num;
    private String nome;

    public Conta(){
        this (0, "");
    }

    public Conta(int num, String nome){
        this.num = num;
        this.nome = nome;
    }

    public int compareTo(Conta obj){
        if (this.num < obj.num) return -1;
        if (this.num > obj.num) return 1;
        return 0;
    }

    public String toString(){
        return String.format("\n%d %s", num, nome);
    }

    public String getNome(){
        return nome;
    }
}
