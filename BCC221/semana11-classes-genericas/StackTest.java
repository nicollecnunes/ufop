public class StackTest{
    public Double[] dElem = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    public Integer[] iElem = {1,2,3,4,5,6};

    public Pilha<Double> doubleStack;
    public Pilha<Integer> integerStack;

    public void testStacks(){
        doubleStack = new Pilha<Double>(5);
        integerStack =  new Pilha<Integer>(10);

        testPush("double:", doubleStack, dElem);
        testPop("double:", doubleStack);

        testPush("integer:", integerStack, iElem);
        testPop("integer:", integerStack);

    }

    public <T> void testPush(String nome, Pilha<T> stack, T[] elems){
        try{
            System.out.printf("Pushing no %s", nome);

            for (T elem : elems){
                System.out.printf(" %s ", elem);
                stack.push(elem);
            }
        }
        catch(PilhaCheiaException err){
            System.out.printf("erro cheias\n");
        }
    }

    public <T> void testPop(String nome, Pilha<T> stack){
        try{
            System.out.printf("Popping de %s\n",nome);
            T valorPop;
            while(true){
                valorPop = stack.pop();
                System.out.printf("Popped: %s\n",valorPop);
            }
        }
        catch(PilhaVaziaException err){
            System.out.println();
            System.out.printf("erro vazias\n");
        }
    } 
    public static void main(String args[]){
        StackTest app =  new StackTest();
        app.testStacks();
    }
}
