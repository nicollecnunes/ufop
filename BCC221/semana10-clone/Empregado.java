public class Empregado implements Cloneable{
    private int empregadoId;
    private String empregadoNome;
    private Departamento departamento;

    public Empregado(){
        departamento = new Departamento();
    }

    public Empregado(int id, String nome, Departamento dep){
        setEmpregadoId(id);
        setEmpregadoNome(nome);
        setDepartamento(dep);
    }

    public int getEmpregadoId(){
        return empregadoId;
    }

    public void setEmpregadoId(int _id){
        empregadoId = _id;
    }

    public String getEmpregadoNome(){
        return empregadoNome;
    }

    public void setEmpregadoNome(String _nome){
        empregadoNome = _nome;
    }

    public Departamento getDepartamento(){
        return departamento;
    }

    public void setDepartamento(Departamento d){
        departamento = d;
    }

    public void setDepartamentoNome(String n){
        departamento.setNome(n);
    }

    public String toString(){
        return String.format("\n%s\n%s: %d\n%s: %s%s", "Dados Empregado", "Id",
        getEmpregadoId(), "Nome", getEmpregadoNome(), departamento); // vai usar o toString do departamento
    }

    public Object clone(){
        try{
            Empregado novo = (Empregado) super.clone();
            novo.setDepartamento((Departamento)novo.getDepartamento().clone());
            return novo;
        }catch(CloneNotSupportedException e){
            return null;
        }
    }

    public boolean equals(Object o){
        if (this == o) return true;
        if (o == null) return false;
        if(getClass() != o.getClass()) return false;

        final Empregado cp = (Empregado) o;

        return (empregadoId == cp.getEmpregadoId() &&
        empregadoNome == cp.getEmpregadoNome() &&
        departamento.equals(cp.getDepartamento()));
    }


}
