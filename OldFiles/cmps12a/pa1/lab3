/* Lawn.java
 * Nicholas Hawthorne
 * 1536694
 * Programming Assignment 1
 * Calculates area and time to mow lawn with input numbers                    */

import java.util.*;
class Lawn{
   public static void main(String [] args){
      
      double length, width, hlength, hwidth, rate; //input

      Scanner scan = new Scanner(System.in);
      System.out.print("Enter the length and width of the lot, in feet: ");
      length = scan.nextDouble();
      width = scan.nextDouble();
      assert (length > 0 & width >0);
									
      System.out.print("Enter the length and width of the house, in feet: ");
      hlength = scan.nextDouble();
      hwidth = scan.nextDouble();
      assert (hlength > 0 & hwidth >0);
      
      double area; //calculated value
      area = length * width - hlength * hwidth;
      System.out.println("The lawn area is "+area+" square feet.");
      System.out.print("Enter the mowing rate, in square feet per second: ");
      rate = scan.nextDouble();
//calculating and presenting time
      int h, m, s; 
      s = (int) Math.round(area/rate);  //cast (narrowing)
      m = s/60;
      s = s%60;
      h = m/60;
      m = m%60;
      System.out.println("The mowing time is "+h+" hour"+(h==1?" ":"s ")
      +m+" minute"+(m==1?" ":"s ")+s+" second"+(s==1?".": "s."));
   }
}




