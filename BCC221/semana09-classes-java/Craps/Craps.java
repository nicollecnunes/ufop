import java.util.Random;

public class Craps{
    private static final Random randomNumber = new Random();

    private enum Status{CONTINUE, WON, LOST}; // 0 1 2 

    private static final int SNAKE_EYES = 2;
    private static final int TREY = 3;
    private static final int SEVEN = 7;
    private static final int YO_LEVEN = 11;
    private static final int BOX_CARDS = 12;

    public void play(){
        int myPoint = 0;
        Status gameStatus;

        int sumOfDice = rollDice();

        switch(sumOfDice){
            case SEVEN:
            case YO_LEVEN:
                gameStatus = Status.WON;
                break;
            case SNAKE_EYES:
            case TREY:
            case BOX_CARDS:
                gameStatus = Status.LOST;
                break;
            default:
                gameStatus = Status.CONTINUE;
                myPoint = sumOfDice;
                System.out.println("Pontuacao: " + myPoint);
        }

        while (gameStatus == Status.CONTINUE){
            sumOfDice = rollDice();

            if (sumOfDice == myPoint)
                gameStatus = Status.WON;
            else   
                if (sumOfDice == SEVEN)
                gameStatus = Status.LOST;
        }

        if (gameStatus == Status.WON){
            System.out.println("O jogador vence");
        }
        else{
            System.out.println("O jogador perde");
        }
    }

    public int rollDice(){
        int die1 = 1 + randomNumber.nextInt(6);
        int die2 = 1 + randomNumber.nextInt(6);

        int sum = die1 + die2;

        System.out.println("Jogador lanca: " + sum);
        return sum;
    }

    public static void main(String[] args){
        Craps jogo = new Craps();
        jogo.play();
    }
}