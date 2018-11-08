//-----------------------------------------------------------------------------
// CounterTest.java
// Test the Counter class
//-----------------------------------------------------------------------------

class CounterTest{

   public static void main( String[] args ){

      Counter a = new Counter(10);
      Counter b = new Counter(113);
      Counter c = new Counter(113);

      // uncomment to see syntax errors related to access private
      // a.limit = 100;
      // a.value = 50;

      a.click();
      System.out.println(a.getValue());
      System.out.println(a);
      System.out.println(b);
      System.out.println(c);
      for(int i=0; i<196; i++){
         a.click();
         b.click();
         c.click();
      }
      System.out.println(a);
      System.out.println(b);
      System.out.println(c);
      System.out.println(b.equals(a));
      System.out.println(b.equals(c));
      
      c.reset();
      System.out.println(a);
      System.out.println(b);
      System.out.println(c);
      System.out.println(b.equals(a));
      System.out.println(b.equals(c));
      System.out.println(c.equals(0));

   }
}
