/* Guess.java
 * Nicholas Hawthorne
 * 1536694
 * Programming Assignment 2
 * Simple guessing game with integers 1 through 10                           */
import java.util.Scanner;
class Guess2{
   public static void main( String [] args){
      
      double a = Math.random(), b;
      int answer, guess; 
      a = Math.random();
      b = 1 + (a * 10);
      answer = (int) b;
      System.out.println("I'm thinking of an integer in the range 1 to 10.  You have three guesses.");
      		
      System.out.print("Enter your first guess: ");
      Scanner sc = new Scanner(System.in);
      guess = sc.nextInt();      
      if ( guess > answer) {
         System.out.println("Your guess is too high.\n");
         System.out.print("Enter your second guess: ");
      }   
      else  if ( guess < answer) {
         System.out.println("Your guess is too low.\n");
         System.out.print("Enter your second guess: ");      
      }
      else {
         System.out.println("You win!\n");
         System.exit(1);
      }
//g2
      guess = sc.nextInt();
      if ( guess > answer) {
         System.out.println("Your guess is too high.\n");
         System.out.print("Enter your third guess: ");
      }
      else if ( guess < answer) {
         System.out.println("Your guess is too low.\n");
         System.out.print("Enter your third guess: ");
      }
      else {
         System.out.println("You win!\n"); 
         System.exit(1);
      }
//g3
      guess = sc.nextInt();
      if ( guess > answer) {
         System.out.println("Your guess is too high.\n");
         System.out.print("You lose.  The number was "+answer+".");
      }
      else  if ( guess < answer) {
         System.out.println("Your guess is too low.\n");
         System.out.println("You lose.  The number was "+answer+".\n");
      }
      else
         System.out.println("You win!\n");
     
   }  
}
