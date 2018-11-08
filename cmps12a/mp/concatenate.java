// concatenate.java
// midterm 2 review problem 2
// makes 2 shorter arrays into 1 longer one

class concatenate{
	public static void main(String[] args ){
		int A[] = {0, 1, 2, 3};
		int B[] = {4, 5};
		
		

		int C[] = concatenate(A, B);
		printArray(C);	
	}	
	static int[] concatenate(int[] A, int[] B){
		int C[] = new int[A.length + B.length];
		int i;
		for (i = 0; i < A.length; i++){
			C[i] = A[i];
		}
		int n = 0;
		for (i = A.length; i < (A.length + B.length); i++){
			C[i] = B[n];
			n++ ;
		}
		return C;
	}
	// printArray()
	// prints the contents of an int array to stdout
	static void printArray(int[] X){
		System.out.print("( ");
		for(int i=0; i<X.length; i++)
			System.out.print(X[i]+" ");
		System.out.println(")");
	}
}
