class Squares3{

   public static void main(String[] args){
   
      int i, n=20;
      
      i=1;
      do{
         System.out.println( (int)Math.pow(i,2) );
         i++;
      }while( i<=n );
      System.out.println("i = "+i);
      
   }
}
