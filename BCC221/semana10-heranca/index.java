public class index {
    public static void main(String[] args){
        Comissionado c = new Comissionado("Nic", "Nunes", "222-22-222", 
        100000, 0.06);

        System.out.println(c);

        BaseComissionado c2 = new BaseComissionado(2.0, "Nic", "Nunes", "222-22-222", 
        100000, 0.06);

        System.out.println(c2);
    }
}
