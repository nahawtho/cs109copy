//-----------------------------------------------------------------------------
// PersonTest.java
// Uses the Person class
//-----------------------------------------------------------------------------

class PersonTest{

   public static void main(String[] args){
      Person a = new Person("Dick", "123-456-7890", 6, 50.0);
      Person b = new Person("Jane", "123-456-7890", 5, 40.0);
      Person c = new Person("Dick");

      // print out vital statistics
      System.out.println(a);
      System.out.println(b);
      System.out.println(c);
      
      // fill in rest of c's fields
      c.setPhoneNumber("123-456-7890");
      c.setAge(6);
      c.setWeight(55.0);
      
      // compare a and c for equality
      System.out.println("\n" + a.equals(c));
      
      // reset one of a's fields
      a.setWeight(55.0);
      
      // compare a and c again
      System.out.println("\n" + c.equals(a));
      
      // the following line prints false, given our definition of equals()
      // if we leave out the instanceof check in equals(), it throws ClassCastException
      System.out.println(a.equals("Dick"));
      
      // uncomment either line below to get a syntax error
      // System.out.println(a.name);
      // b.age = 6;
   }
}

