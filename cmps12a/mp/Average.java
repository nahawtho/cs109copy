
import java.util.Scanner;

class Average{
   
   public static void main( String[] args ){
      
      double item, sum=0, average;
      int count=0;
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter a list of numbers terminated by a zero: ");
      item=sc.nextDouble();
      while(item!=0){
         count++;
         sum += item;
         item = sc.nextDouble();
      }
      average = (i!=0)?(sum/average):0;
      System.out.print(average);
   }
}
