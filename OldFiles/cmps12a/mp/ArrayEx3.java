class ArrayEx3{

   public static void main( String[] args ){
      
      int[] a = {3, 2, 1};
      int[] b = {4, 5, 6, 7, 8};
      int[] list = {9,8,7,6,5,4};
      
      
      printArray(a); // prints ( 3 2 1 )
      printArray(b); // prints ( 4 5 6 7 8 )
      swap(list, 1, 5);  // list now contains ( 9 4 7 6 5 8 )
      swap(list, 2, 3);  // list now contains ( 9 4 6 7 5 8 )
      printArray(list);  // prints ( 9 4 6 7 5 8 )
      swap(list, 1, 6);  // does nothing since 6 is out of range
      System.out.println(list[getMinIndex(list)]); // prints 4
   }

     static void printArray(int[] A){
      System.out.print("( ");
      for(int i=0; i<A.length; i++)
         System.out.print(A[i]+" ");
      System.out.println(")");
       }

   static void swap(int[] A, int i, int j){
      int temp, n = A.length;

      if( i>=0 && j>=0 && i<n && j<n){ // check that i and j are in range
         temp = A[i]; // do the swap if they both are
         A[i] = A[j];
         A[j] = temp;
      } 
   }

       static int getMinIndex(int[] A){
      int i, min_index=0, n=A.length;
      for(i=1; i<n; i++){
         if(A[i]<A[min_index]) min_index = i;
      }
      return min_index;
   }

}


