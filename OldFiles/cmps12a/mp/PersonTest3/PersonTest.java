//-----------------------------------------------------------------------------
// PersonTest.java
// Uses the Person class
//-----------------------------------------------------------------------------

class PersonTest{

   public static void main(String[] args){
      Person a = new Person();
      Person b = new Person();

      // initialize a
      a.name = "Dick";
      a.phoneNumber = "123-456-7890";
      a.age = 6;
      a.weight = 50.0;

      // initialize b
      b.name = "Jane";
      b.phoneNumber = "123-456-7890";
      b.age = 5;
      b.weight = 40.0;

      // print out stats
      System.out.println();
      a.printPerson();          // notice how printPerson() is called
      System.out.println();
      b.printPerson();          // notice how printPerson() is called
      System.out.println();

      // compare ages
      if( a.isOlderThan(b) )
         System.out.println(a.name + " is older than " + b.name);
      else if( b.isOlderThan(a) )
         System.out.println(b.name + " is older than " + a.name);
      else
         System.out.println(a.name + " and " + b.name + " are the same age");
   }
}

