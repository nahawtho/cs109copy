// Queens.java
// Nicholas Hawthorne
// 1536694
// pa5
// Computes the solutions to the "n-Queens Problem"
import java.util.Scanner;
	class Queens{
		public static void main(String [] args){

// main

	}
	static void printArray(int[] A){
		System.out.print("( ");
		for(int i=1; i<A.length; i++) System.out.print(A[i]+" ");
		System.out.println(")");
		}

	static void nextPermutation(int[] A){
		int l=A.length;
		int k=l-2;
		int pivot=0, successor=0, x=0, y=0;
		boolean z = true;
		
		while(true){
			if(A[k]<A[k+1]){
				pivot = A[k]; //creates pivot
				break;
			}
			else if(k > 0) k = k-l;
			else break;
		}
		if (k == 0) reverse(A);
		else {
			for(x = (l-1); x>0; x--){ 
				if(z && A[x]>pivot){
					successor = A[x]; //creates successor
					y = x;
					z = false;
				}
			}
		}
		if(k > 0){
			swap(A, k, y);
		}
		if(k > 0){ //reverses numbers to right of value
			int[] H = new int[(l-k-1)];
			for(int i = 0; i<(l-k-1); i++){
				H[i] = A[k+i+1];
			}
			reverse(H);
			for(int i = 0; i<(l-k-1); i++){
				A[k+i+1] = H[i];
			}
		} 	
		//return A;		
		//printArray(A);
	}
	static void reverse(int[] C){ // reverses numbers one at a time in array
		for( int n = C.length; n > 1; n--){
			for(int i = 0; i<(n-1); i++){
				if( C[i]>C[i+1] ){
					swap(C, i, i+1);
				}
			}
		}
	}
	static void swap(int[] D, int i, int j){ //standard swap in array
		int temp = D[i];
		D[i] = D[j];
		D[j] = temp;
	}

}















