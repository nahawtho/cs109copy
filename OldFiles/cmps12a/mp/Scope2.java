//-----------------------------------------------------------------------------
// Scope2.java
// Another syntax error, will not compile.
//-----------------------------------------------------------------------------

class Scope2{
   
   public static void main( String[] args ){

      int a=6;
      int b=8;

      System.out.println(a);
      {
         int b = 8;                // syntax error
         System.out.println(a);
         System.out.println(b);
      }
      System.out.println(a);
      System.out.println(b);
   }
}
