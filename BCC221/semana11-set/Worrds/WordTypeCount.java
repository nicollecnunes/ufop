import java.util.StringTokenizer;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.TreeSet;
import java.util.Scanner;

public class WordTypeCount {
    private Map<String, Integer> map;

    public WordTypeCount(){
        // cria o hash map
        map = new HashMap<String, Integer>();

        createMap(); // cria baseado na entrada
        displayMap(); // exibe o conteudo
    }

    private void displayMap() {
        Set<String> keys =  map.keySet();

        // ordena as chaves
        TreeSet<String> sortedKeys = new TreeSet<String>(keys);

        System.out.println("Map contains: \nKey\t\tValue");

        // gera a saida para cada chave no mapa
        for (String key : sortedKeys)
            System.out.printf("%-10s%10s\n", key, map.get(key));

        System.out.printf("\nsize:%d\nisEmpty:%b\n", map.size(), map.isEmpty());
    }

    private void createMap() {
        System.out.println("Enter a string: ");
        
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        StringTokenizer tokenizer = new StringTokenizer(input);

        // processa a entrada enquanto tem entrada
        while (tokenizer.hasMoreTokens()) {
            String word = tokenizer.nextToken().toLowerCase(); // pega a palavra

            // se o mapa contem a palavra
            if (map.containsKey(word)){
                int count = map.get(word);
                map.put(word, count+1);
            }
            else{
                map.put(word, 1);
            }
        }
    }

    public static void main(String args []){
        new WordTypeCount();
    }
}
