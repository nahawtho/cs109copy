/* Guess.java
 * Nicholas Hawthorne
 * 1536694
 * Programming Assignment 2
 * Simple guessing game with integers 1 through 10                           */
import java.util.Scanner;

class Guess{
   public static void main( String [] args){
      
      double num, num2;
      int answer, g1, g2, g3; 
      num = Math.random();
      num2 = 1 + (num * 10);
      answer = (int) num2;
      System.out.println("I'm thinking of an integer in the range 1 to 10." +
         "  You have three guesses.\n");
             
      System.out.print("Enter your first guess: ");
      Scanner sc = new Scanner(System.in);
      g1 = sc.nextInt();      
      if ( g1 > answer) {
         System.out.println("Your guess is too high.\n");
         System.out.print("Enter your second guess: ");
      }   
      else  if ( g1 < answer) {
         System.out.println("Your guess is too low.\n");
         System.out.print("Enter your second guess: ");      
      }
      else {
         System.out.println("You win!\n");
         System.exit(1);
      }
//g2
      g2 = sc.nextInt();
      if ( g2 > answer) {
         System.out.println("Your guess is too high.\n");
         System.out.print("Enter your third guess: ");
      }
      else if ( g2 < answer) {
         System.out.println("Your guess is too low.\n");
         System.out.print("Enter your third guess: ");
      }
      else {
         System.out.println("You win!\n"); 
         System.exit(1);
      }
//g3
      g3 = sc.nextInt();
      if ( g3 > answer) {
         System.out.println("Your guess is too high.\n");
         System.out.print("You lose.  The number was "+answer+".");
      }
      else  if ( g3 < answer) {
         System.out.println("Your guess is too low.\n");
         System.out.println("You lose.  The number was "+answer+".\n");
      }
      else
         System.out.println("You win!\n");
     
   }  
}
