// Queens.java
// Nicholas Hawthorne
// 1536694`
// pa5
// solves famous "n-queens" problem with collection of methods and formulas.

import java.util.Scanner;
class Queens{
	public static void main(String [] args){
		int n = 0;
		boolean v = false;
		int[] C;
		if(args.length != 1 && args.length != 2){
			System.out.println("Usage: Queens [-v] number");
			System.out.println("Option: -v verbose output, print all solutions");
			System.exit(1);
		}
		if (args[0].equals("-v")) {
			v = true;
		}else{
			try{
				n = Integer.parseInt(args[0]);
			}catch (Exception r) {
				System.out.println("Usage: Queens [-v] number");
				System.out.println("Option: -v verbose output, print all solutions");
				System.exit(1);
			}
		}

		int i;
		int number = 0; //number is number of solutions
		if (v){
			try{
				n = Integer.parseInt(args[1]);
			}catch (Exception r){
				System.out.println("Usage: Queens [-v] number");
				System.out.println("Option: -v verbose output, print all solutions");
				System.exit(1);
			}
		}
		C = new int[n+1];
		for (i=1; i<n+1; i++){
			C[i] = i;
		}
		//test         
		//System.out.println(factorial(n));
		for (i=0; i<factorial(n); i++){
			nextPermutation(C);
			if(isSolution(C)){
				if(v) {
					printArray(C);
				}
				number++;
			}
		}
		System.out.println(n + " -Queens has " + number + " solutions");
	}

	static void nextPermutation(int[]X){
		int n = (X.length - 2);
		int s = 0; //successor
		int p = 0; //pivot
		for (int i=n; i>0; i--){
			if(X[i]<X[i+1]){
				p = i;
				break;
			}
		}
		if(p == 0){
			reverse(X, 1, n+1);
			return;
		}
		for(int i=n+1; i>0; i--){
			if(X[i]>X[p]){
				s = i;
				break;
			}
		}
		swap(X, p, s);
		reverse(X, p+1, n+1);
		return;
	}
	static boolean isSolution(int[] C) {
		for(int i=1; i<=C.length - 2; i++){
			for(int j= i+1; j<=C.length-1; j++){
				if(Math.abs(C[i]-C[j]) == Math.abs(i-j)){
					return false;
				}
			}
		} return true;
	}
	static int factorial(int n){
		int product = 1, i = 1;
		while(i<=n){
			product *= i;
			i++;
		}
		return product;
	}
	static void printArray(int[] C){
		System.out.print("(");
		for(int i = 1; i<C.length - 1; i++) System.out.print(C[i]+", ");
		System.out.println(C[C.length - 1] +")");
	}
	static void reverse(int[] M, int i, int j){
		int ls = i; int rs = j;
		while(ls<rs){
			swap(M, ls, rs);
			ls++;
			rs--;
		}
	}
	static void swap(int[] Q, int i, int j){
		int temp = Q[i];
		Q[i] = Q[j];
		Q[j] = temp;
	}
}
