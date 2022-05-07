import java.util.Scanner;
import java.lang.Math;

public class Main {
    Scanner scan = new Scanner(System.in);
    int maxGuesses = 6;
    int guessCount = 0;



    String words[] = {"danger", "uniform", "elephant", "uniform", "table"};

    public static void main(String args[]){
        Main app = new Main();
        System.out.println("Welcome to Hangman!");
        app.menu();

    }

    public void menu(){

        String userChoice;
        while(true){
            System.out.println("(1)Play\n(2)Rules\n(3)Exit");
            userChoice = scan.next();
            if (userChoice.equals("1")){
                this.start();
            }
            else if (userChoice.equals("2")){
                System.out.println(this.rules());
            }
            else{
                System.out.println("Goodbye!");
                break;
            }
        }

    }

    public String rules(){
        return "You must guess the hidden word within 6 guesses. You can choose " +
                "to guess the word at anytime, however, you have once chance.";
    }

    public int generateSeed(){
        int min = 1, max = 5, range = max - min + 1;
        int ranInt = (int) (Math.random() * range) + min;
        return ranInt;
    }
    public void start(){
        while (true){
           // System.out.println("Please choose a letter");


        }
    }

    public void guessLetter(){

    }
}
