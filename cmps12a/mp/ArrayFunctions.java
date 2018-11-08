class ArrayFunctions{

   public static void main( String[] args ){
      double[] A, B, C, D, E;
      int i, n=10;

      A = new double[n];
      for(i=0; i<n; i++) A[i] = i+1;

      B = copyArray1(A);
      C = new double[n];
      copyArray2(A, 0, C, 0, n);

      printArray(A);
      printArray(B);
      printArray(C);

      D = arrayReciprocal(A);
      E = scalarProduct(A, Math.PI);

      printArray(D);
      printArray(E);
      System.out.println(sumArray(D));
      System.out.println(dotProduct(A, A));

   }
static void printArray(double[] X){
      System.out.print("( ");
      for(int i=0; i<X.length; i++)
         System.out.print(X[i]+" ");
      System.out.println(")");
   }
 static double[] copyArray1(double[] X){
      double[] Y = new double[X.length];    // allocate space for new array
      for(int i=0; i<X.length; i++){        // copy elements one by one
         Y[i] = X[i];
      }
      return Y;   // return a reference to the new array object
   }
static void copyArray2(double[] X, int a, double[] Y, int b, int n){
      int i = a, j = b;
      while( i<=a+n-1 ){
         Y[j] = X[i];
         i++;
         j++;
      }
   }
static double sumArray(double[] X){
      double sum = 0.0;
      for(int i=0; i<X.length; i++){
         sum += X[i];
      }
      return sum;
   }
 static double[] arrayReciprocal(double[] X){
      double[] Y = new double[X.length];
      for(int i=0; i<X.length; i++){
         Y[i] = 1/X[i];
      }
      return Y;
   }
static double dotProduct(double[] X, double[] Y){
      double dp = 0.0;
      for(int i=0; i<X.length; i++){
         dp += X[i]*Y[i];
      }
      return dp;
   }
static double[] scalarProduct(double[] X, double c){
      double[] Y = new double[X.length];
      for(int i=0; i<X.length; i++){
         Y[i] = c*X[i];
      }
      return Y;
   }

}
