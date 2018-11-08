//Problem2

import java.util.Scanner;
class Problem2{
   public static void main (String [] args){
      double x, y, z;
      Scanner sc = new Scanner(System.in);
      System.out.println("Give me two double values.");
      x = sc.nextDouble();
      y = sc.nextDouble();
      z = Math.sqrt(x)+Math.sqrt(y);
      System.out.println(z);
   }
}
