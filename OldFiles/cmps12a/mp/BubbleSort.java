//-----------------------------------------------------------------------------
// BubbleSort.java - sort an array of integers
//-----------------------------------------------------------------------------

class BubbleSort {

   public static void main(String[] args) {
      double[] A = {7.0, 3.1, 6.6, 3.01, -5.2, 22.3, -17.0, 2.0};

      // sort the array
      sort(A);

      // print out the array
      for (int i=0; i<A.length; i++){
         System.out.print(A[i]+"  ");
      }
      System.out.println();
   }
   
   // sort using the bubble sort algorithm
   static void sort(double[] X) {
      int i, n;
      for(n = X.length; n>1; n--) {
         for(i=0; i<n-1; i++){
            if( X[i]>X[i+1] ){
               swap(X, i, i+1);
            }
         }
      }
   }
   
   // swap two entries in array
   static void swap(double[] Z, int i, int j){
      double temp = Z[i];
      Z[i] = Z[j];
      Z[j] = temp;
   }
   
}
