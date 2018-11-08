/* GCD.java
 * Nicholas Hawthorne
 * 1536694
 * PA3
 * Calculates the greatest common denominator from 2 int values              */

import java.util.Scanner;
class GCD{
	public static void main(String[] args){

		int x, y;
		System.out.print("Enter a positive integer: ");
		// retrieves 2 integers

 		Scanner sc = new Scanner(System.in);
		while (true) {
			
			if (!sc.hasNextInt()){
				System.out.print("Please enter a positive integer: ");				
				sc.next();
				continue;
			}else x = sc.nextInt();
				
			if (x <= 0) { 
				System.out.print("Please enter a positive integer: ");
                                continue;
			}else break;
		}
			

		System.out.print("Enter another positive integer: ");
 		
		while (true) {

                        if (!sc.hasNextInt()){
                                System.out.print("Please enter a positive integer: ");
                                sc.next();
				continue;
                        }else y = sc.nextInt();
                                
                        if (y <= 0) {
                                System.out.print("Please enter a positive integer: ");
                                continue;
                        }else break;
                }

			
		int a, b, q, r, gcd; // declares smallest, biggest, multiplier, remainder, gcd 
		a = Math.min(x, y);
		b = Math.max(x, y);
		q = b/a;
		r = b%a;

		while (r != 0){
			q = a/r;
			b = a;
			a = r;
			r = b - a*q;
		}

		System.out.println("The GCD of "+x+" and "+y+" is "+a);

	}
}



