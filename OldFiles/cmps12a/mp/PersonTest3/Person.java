//-----------------------------------------------------------------------------
// Person.java
// Includes instance methods to print out a Person object, and to compare
// the ages of different Person objects.
//-----------------------------------------------------------------------------

class Person{

   String name;
   String phoneNumber;
   int age;
   double weight;

   void printPerson(){  // this function is not static!
      System.out.println("Name: " + name);
      System.out.println("Phone Number: " + phoneNumber);
      System.out.println("Age: " + age);
      System.out.println("Weight: " + weight);
   }

   boolean isOlderThan(Person x){
      return ( this.age>x.age );
   }
}

