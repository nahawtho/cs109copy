//-----------------------------------------------------------------------------
//  Person.java
//  Includes equals() method that overides Object's equals() as well as a
//  toString() method.  Uses private member variables, and public getters 
//  and setters to access and manipulate field values.
//-----------------------------------------------------------------------------

class Person{

   // Fields  -----------------------------------------------------------------
   private String name;
   private String phoneNumber;
   private int age;
   private double weight;

   // Constructors  -----------------------------------------------------------
   Person(String name){
      this.name = name;
   }

   Person(String name, String phoneNumber, int age, double weight){
      this.name = name;
      this.phoneNumber = phoneNumber;
      this.age = age;
      this.weight = weight;
   }
   
   // Manipulation Procedures  -------------------------------------------------
   
   // setPhoneNumber()
   void setPhoneNumber(String s){ 
      this.phoneNumber = new String(s);
   }
   
   // setAge()
   void setAge(int age){
      this.age = age;
   }
   
   // setWeight()
   void setWeight(double weight){
      this.weight = weight;
   }
   
   
   // Access Functions  -------------------------------------------------------
   
   // getName()
   public String getName(){
      return this.name;
   }
   
   // getPhoneNumber()
   public String getPhoneNumber(){
      return this.phoneNumber;
   }
   
   // getAge()
   public int getAge(){
      return this.age;
   }
   
   // getWeight()
   public double getWeight(){
      return this.weight;
   }
   

   // Other methods  ----------------------------------------------------------

   // toString()
   // overides Objects toString() method
   public String toString(){
      return (   "\nName: " + name +
                 "\nPhone Number: " + phoneNumber +
                 "\nAge: " + age +
                 "\nWeight: " + weight  );
   }

   // equals()
   // overides Object's equals() method
   public boolean equals(Object x){
      Person p;
      boolean eq = false;

      if( x instanceof Person ){  // try leaving out this check
         p = (Person) x;
         eq = this.name.equals(p.name) &&
              this.phoneNumber.equals(p.phoneNumber) &&
              this.age==p.age &&
              this.weight==p.weight;
      }
      return eq;
   }

   // isOlderThan()
   // returns true if and only if this Person is older than x
   boolean isOlderThan(Person x){
      return (this.age>x.age);
   }
   
}
