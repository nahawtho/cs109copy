//-----------------------------------------------------------------------------
// MatrixProduct.java
// Implements matrix multiplication using 2-dimensional arrays of doubles
//-----------------------------------------------------------------------------

class MatrixProduct{
   
   public static void main(String[] args){
      
      double[][] A = {{1,  0, -1},          // 2X3 array
                      {2,  1, -3}};                         
      double[][] B = {{ 1,  3,  0, -2},     // 3X4 array
                      {-1,  5,  0, -5},
                      { 1, -1, -1,  0}}; 
      double[][] C =  matrixMult(A, B);     // 2X4 array
      
      print2dArray(A);
      System.out.println("times");
      print2dArray(B);
      System.out.println("equals");
      print2dArray(C);      
   }

   // matrixMult()
   // returns the matrix product of X by Y
   // preconditions:  (1) X and Y are both rectangular arrays
   //                 (2) X[0].length == Y.length
   static double[][] matrixMult(double[][] X, double[][] Y){
      double[][] P = new double[X.length][Y[0].length];
      int i, j, k;

      // initialize P to all zeros
      for(i=0; i<P.length; i++)
         for(j=0; j<P[i].length; j++)
            P[i][j] = 0.0;      

      // determine matrix product
      for(i=0; i<P.length; i++)
         for(j=0; j<P[i].length; j++)
            for(k=0; k<X[0].length; k++)
               P[i][j] += X[i][k]*Y[k][j];

      return P;
   }
   
   // print2dArray()
   // prints out a 2 diminsional array of doubles
   static void print2dArray(double[][] X){
      int i, j;
      
      for(i=0; i<X.length; i++){
         for(j=0; j<X[i].length; j++){
            System.out.print( X[i][j] + " " );
         }
         System.out.println();
      }
   }
   
}
