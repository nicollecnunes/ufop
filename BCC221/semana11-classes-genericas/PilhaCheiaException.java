public class PilhaCheiaException extends RuntimeException{
    
    public PilhaCheiaException(){
        this("Pilha esta cheia");
    }

    public PilhaCheiaException(String msg){
        super(msg);
    }
}