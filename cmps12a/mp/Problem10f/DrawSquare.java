// DrawSquare.java
import java.util.Scanner;
class DrawSquare{
	public static void main (String [] args){
		int n, i, j;

		Scanner sc = new Scanner (args[0]);
		if (args.length!=1 || !sc.hasNextInt()){
			Usage();
		}
		n = sc.nextInt();
		if (n<2) Usage();

		for (i=0; i<n; i++) System.out.print("*");
		for (j=0; j<n-2; j++){
			System.out.print("\n*");
			for(i=0; i<n-2; i++){
				System.out.print(" ");
			}
			System.out.print("*");
		}

		System.out.println(); 
		for (i=0; i<n; i++) System.out.print("*");


	}
	static void Usage(){
		System.err.println("Usage: java DrawSquare <positive integer at least 2>");
		System.exit(1);
	}
}
