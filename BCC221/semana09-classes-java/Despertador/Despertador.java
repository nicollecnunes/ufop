public class Despertador {
    boolean ligado;
    Hora alarme, horaAtual;

    public Despertador(){
        alarme =  new Hora();
        horaAtual = new Hora();
    }

    public void setAlarme(int h, int m, int s){
        alarme.setH(h);
        alarme.setM(m);
        alarme.setS(s);
    }

    public void setHoraAtual(int h, int m, int s){
        horaAtual.setH(h);
        horaAtual.setM(m);
        horaAtual.setS(s);
    }

    public String getAlarme(){
        return alarme.toString();
    }

    public String getHoraAtual(){
        return horaAtual.toUniversalString();
    }

    public static void main(String [] args){
        Despertador d = new Despertador();
        d.setHoraAtual(14, 56, 20);
        d.setAlarme(18, 15, 0);

        System.out.println("Hora atual: " + d.getHoraAtual());
        System.out.println("Alarme: " + d.getAlarme());
    }
}
