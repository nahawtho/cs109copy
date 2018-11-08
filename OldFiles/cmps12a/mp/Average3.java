import java.util.Scanner;

class Average3{
   
   public static void main( String[] args ){
      
      double item, sum=0, average;
      int count=0;
      Scanner sc = new Scanner(System.in);

      System.out.print("Enter a list of numbers terminated by a zero: ");
      item = sc.nextDouble();
      do {
         sum += item;
         count++;
         item = sc.nextDouble();
      }while (item!=0);
      average = (count>0)?(sum/count):0;
      System.out.println("The average is: " + average);
   
   }

}
