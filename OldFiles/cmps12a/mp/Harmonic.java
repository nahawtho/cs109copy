import java.util.Scanner;

class Harmonic{

   public static void main(String[] args){
      int i, n;
      double H = 0;
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter a positive integer: ");
      n = sc.nextInt();
      for(i=1; i<=n; i++){
         H += 1.0/i;
      }
      System.out.println("The "+n+"th harmonic number is "+H);
   }
   
}
