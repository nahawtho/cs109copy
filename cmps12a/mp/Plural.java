import java.util.Scanner;

class Plural{

   public static void main(String[] args){

      int n;
      String str;
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter an integer: ");
      n = sc.nextInt();
      str = ( n==1 ? "singular" : "plural" );
      System.out.println(str);

      System.out.println("I have "+n+" apple"+(n==1?".":"s."));
   }
}
