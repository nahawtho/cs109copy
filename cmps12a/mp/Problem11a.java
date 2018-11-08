//Problem11a.java
import java.lang.*;
class Problem11a{
// sort using the bubble sort algorithm
   static void sortStringArray(String[] X) {
      int i, n;
      for(n = X.length; n>1; n--) {
         for(i=0; i<n-1; i++){
            if( X[i].compareTo(X[i+1])>0 ){
               swap(X, i, i+1);
            }
         }
      }
   }
   
   // swap two entries in array
   static void swap(String[] Z, int i, int j){
      String temp = Z[i];
      Z[i] = Z[j];
      Z[j] = temp;
   }

	
	public static void main(String[] args){
		String A[] = {"one", "two", "three", "four"};
		sortStringArray(A);		
		for (int i = 0; i<A.length; i++){
			System.out.print(A[i]+ " ");
		}
	System.out.println();
	}
}
