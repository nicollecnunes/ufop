public class PilhaVaziaException extends RuntimeException{

    public PilhaVaziaException(){
        this("Pilha esta vazia");
    }

    public PilhaVaziaException(String msg){
        super(msg);
    }
}