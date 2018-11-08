import java.util.Scanner;

class Average2{
   
   public static void main( String[] args ){
      
      double item, sum=0, average;
      int count=0;
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter a list of numbers terminated by a zero: ");
      for(item = sc.nextDouble(); item!=0; count++){
         sum += item;
         item = sc.nextDouble();
      }
      average = (count>0)?(sum/count):0;
      System.out.println("The average is: " + average);
   
   }

}
