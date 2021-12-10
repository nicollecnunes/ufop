public class Pilha<E> {
    public final int size;
    public int top;
    public E[] elements;

    public Pilha(){
        this(10);
    }

    public Pilha(int s){
        size = s > 0 ? s : 10;
        top = - 1; // pilha vazia
        
        elements =  (E [])new Object[size]; // cria o vetor com cast pro tipo E
    }

    public void push (E pushValue){
        if (top == size - 1){
            throw new PilhaCheiaException(String.format("Pilha cheia, cannot push %s", pushValue));
        }else{
            elements[++top] = pushValue;
        }
    }

    public E pop(){
        if (top == -1){
            throw new PilhaVaziaException("Stack is empty, cannot pop");
        }
        return elements[top --];
    }
}