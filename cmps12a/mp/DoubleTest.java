//-----------------------------------------------------------------------------
//   DoubleTest.java
//   Tests the Double wrapper class
//-----------------------------------------------------------------------------

class DoubleTest{

   public static void main(String[] args){
      Double a = new Double("12.34");   // constructor from String
      Double b = new Double(12.34);     // constructor from double
      Double c = 12.34;                 // shortcut constructor from double

      System.out.println(a);
      System.out.println(b);
      System.out.println(c);

      // arithmetic operators work on Double as on double
      a *= 5;
      System.out.println( a+b*c );

      // this is the right way to compare reference types for equality
      System.out.println(a.equals(b));
      System.out.println(b.equals(c));
      System.out.println(c.equals(a));

      // this is the wrong way to compare reference types for equality
      System.out.println(b==c); 

      // if a reference type supports size comparison, this is how to do it
      System.out.println(a.compareTo(b)); // <0 if a<b, ==0 if a=b, >0 if a>b
      System.out.println(b.compareTo(c));
      System.out.println(c.compareTo(b));

      System.out.println( a.longValue() );
      System.out.println(Double.valueOf("98.765"));      // same as new Double("98.765")
      System.out.println(Double.parseDouble("98.765"));  // parseDouble() returns double not Double

      try{ 
         System.out.println(Double.parseDouble("5.6x7")); 
      }catch(NumberFormatException e){ 
         System.out.println(e.getMessage()+": cannot parse as double");
      }
      
      System.out.println(Double.MAX_VALUE);
      System.out.println(Double.MIN_VALUE);
      System.out.println(Double.MAX_EXPONENT);
      System.out.println(Double.MIN_EXPONENT);
      System.out.println(Double.SIZE);
      
      System.out.println(Double.MAX_VALUE+1.0);
      System.out.println(Double.MIN_VALUE-1.0);

   }
}
