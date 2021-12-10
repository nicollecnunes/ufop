import java.util.PriorityQueue;

public class PQTest {
    public static void main(String argrs[]){
        PriorityQueue<Integer> q = new PriorityQueue<Integer>();

        q.offer(3);
        q.offer(9);
        q.offer(4);

        while(q.size() > 0){
            System.out.printf("%d ", q.peek()); /// retorna o topo
            q.poll(); // remove o topo
        }
    }
}
