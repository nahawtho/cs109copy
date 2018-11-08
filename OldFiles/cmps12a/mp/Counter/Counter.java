//-----------------------------------------------------------------------------
// Counter.java
// A wrap-around counter
//-----------------------------------------------------------------------------

class Counter{

   // Member variables
   private int value;  // ranges from 0 to limit-1
   private int limit;

   // Constructor
   Counter(int limit){
      this.limit = limit;
      this.value = 0;
   }

   // Methods
   void reset(){ value = 0;}
   
   int getValue(){ return value; }
   
   void click(){ 
      value += 1;
      value = (value<limit?value:0);
   }
   
   public String toString(){
      return String.valueOf(value);
   }
   
   public boolean equals(Object x){
      boolean eq = false;
      Counter c;

      if( x instanceof Counter){
         c = (Counter)x;
         eq = ( this.limit==c.limit && this.value==c.value );
      }
      return eq;
   }
   
}

