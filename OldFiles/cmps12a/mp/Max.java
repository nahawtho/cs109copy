import java.util.Scanner;

class Max{

   public static void main( String[] args ){
      
      double item, max;
      int count=0;
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter a list of numbers terminated by a zero: ");
      max = item = sc.nextDouble();
      while(item!=0){
         if( item>max ){
            max = item;
         }
         count++;
         item = sc.nextDouble();
      }
      System.out.println(count + " non-zero nunmbers were entered.");
      System.out.println("Their maximum is: " + ((count>0)?(max):("undefined")) + ".");

   }

}


