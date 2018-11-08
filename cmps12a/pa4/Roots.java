// Roots.java
// Nicholas Hawthorne
// 1536694
// PA4
// Computes roots of a polynomial expression using the bisection method
import java.util.Scanner;
class Roots{
	public static void main (String[] args){
		int n, i; 
		System.out.println("Enter the degree: ");
		Scanner sc = new Scanner (System.in);
		n = sc.nextInt();
		double[] A = new double[n+1], B = new double[n+1], D = new double[n];
		double L, R, width;

		// A is [] for degrees, B is [] for coefficients, D is [] coefficients for derivative

		for (i=0; i<n; i++){
			A[i] = i;
		}

		System.out.println("Enter "+(n+1)+" coefficients: ");
		for (i=0; i<B.length; i++){
			B[i] = sc.nextDouble();
		//	System.out.print(B[i]);
		}  
 
		D = diff(B);

		System.out.print("Enter the left and right endpoints: ");
		L = sc.nextDouble();
		R = sc.nextDouble();

		double resolution=.01, tolerance=0.0000001, threshold=.001;
		double a = L, b = (L + threshold), mid;

		for (i=0; i<(R-L); i+=resolution){ 
			if (poly(B, a)*poly(B, b)<=0) {
				mid = findRoot(B, a, b, tolerance);
				if (Math.abs(poly(B, mid)) < threshold) {
					System.out.print("Root found at ");
                			System.out.printf("%.5f%n", mid);	 
				}
			}
			else if (((poly(D, a))*(poly(D, b)))<=0) {
				mid = findRoot (B, a, b, tolerance);
				if (Math.abs(poly(B, mid)) < threshold) {
					System.out.print("root = ");
                                	System.out.printf("%.5f%n", mid);
				}
				else System.out.print("No roots were found in the specified range.");
			}
			a += resolution;
			b += resolution;
		}
		
	}
	static double poly(double[] C, double x){  // the y value at the supposed zero 
		int i;
		double sum = 0;
		for (i=0; i<C.length; i++){
			sum +=(C[i]*Math.pow(x, i));
		}
		return sum;
	}
	static double[] diff(double[] C){  //coefficients of derivative
		int i;
		double D[] = new double[C.length - 1];
		for (i=1; i<C.length; i++){
			D[i - 1] = C[i]*i;
		}
		return D;
	}
	static double findRoot(double[] C, double a, double b, double tolerance){
		double mid = 0, width;

		width = b-a;
		while ( width>tolerance ){
			mid = (a+b)/2;
			if( poly(C, a)*poly(C, mid)<=0 ){  // if root is in [a, mid]
				b = mid;            //    move b left
			} else {               // else root is in (mid, b] 
				a = mid;            //    move a right
			}
			width = b-a;
		}
		return mid;
		
	}

}
 
