public class GradeBook
{
    private String nomeCurso;
    public void setNomeCurso(String _nomeCurso)
    {
        nomeCurso = _nomeCurso;
    }

    public String getNomeCurso()
    {
        return nomeCurso;
    }

    public void displayMessage(String nomeCurso)
    {
        System.out.printf("Bem vindo ao curso %s :)", getNomeCurso());
    }
}