//-----------------------------------------------------------------------------
//  AbstractCounter.java
//  An abstract class, i.e. a class with some undefined (abstract) methods
//-----------------------------------------------------------------------------

abstract class AbstractCounter{
      
   // Member variables
   protected int value;  // try making either of these fields private
   protected int limit;  // instead of protected, see what happens

   // Abstract methods
   abstract void click();
   
   // Defined methods
   void reset(){ value = 0;}
   int getValue(){ return value; }
   public String toString(){ return String.valueOf(value); }

}

