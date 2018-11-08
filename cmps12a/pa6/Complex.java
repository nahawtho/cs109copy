// Complex.java
// Nicholas Hawthorne
// nahawtho 1536694
// pa6
// performs a variety of mathematical operations on expressions from input,
// creating a new output file
//-----------------------------------------------------------------------------
// Complex.java
// Represents complex numbers as a pair of doubles
//
// pa6
// Fill in the function definitions below. See class notes, or the project 
// description for the definitions of the complex arithmetic operations.
//-----------------------------------------------------------------------------
import java.lang.*;


class Complex{

   //--------------------------------------------------------------------------
   // Private Data Fields 
   //--------------------------------------------------------------------------
   private double re;
   private double im;
   
   //--------------------------------------------------------------------------
   // Public Constant Fields 
   //--------------------------------------------------------------------------
   public static final Complex ONE = Complex.valueOf(1,0);
   public static final Complex ZERO = Complex.valueOf(0,0);
   public static final Complex I = Complex.valueOf(0,1);

   //--------------------------------------------------------------------------
   // Constructors 
   //--------------------------------------------------------------------------
   Complex(double a, double b){
      this.re = a;
      this.im = b;
   }

   Complex(double a){
      this.re = a;
      this.im = 0;
   }

   Complex(String str){
      // Fill in this constructor.
      // It should accept expressions like "-2+3i", "2-3i", "3", "5i", etc..
      // Throw a NumberFormatException if s cannot be parsed as Complex.
      double[] part = new double[2];
       
      String s = str.trim();
      String NUM = "(\\d+\\.\\d*|\\.?\\d+)";
      String SGN = "[+-]?";
      String OP =  "\\s*[+-]\\s*";
      String I =   "i";
      String OR =  "|";
      String REAL = SGN+NUM;
      String IMAG = SGN+NUM+"?"+I;
      String COMP = REAL+OR+
                    IMAG+OR+
                    REAL+OP+NUM+"?"+I;
      
      if( !s.matches(COMP) ){
         throw new NumberFormatException(
                   "Cannot parse input string \""+s+"\" as Complex");
      }
      s = s.replaceAll("\\s","");     
      if( s.matches(REAL) ){
         part[0] = Double.parseDouble(s);
         part[1] = 0;
      }else if( s.matches(SGN+I) ){
         part[0] = 0;
         part[1] = Double.parseDouble( s.replace( I, "1.0" ) );
      }else if( s.matches(IMAG) ){
         part[0] = 0;
         part[1] = Double.parseDouble( s.replace( I , "" ) );
      }else if( s.matches(REAL+OP+I) ){
         part[0] = Double.parseDouble( s.replaceAll( "("+REAL+")"+OP+".+" , "$1" ) );
         part[1] = Double.parseDouble( s.replaceAll( ".+("+OP+")"+I , "$1"+"1.0" ) );
      }else{   //  s.matches(REAL+OP+NUM+I) 
         part[0] = Double.parseDouble( s.replaceAll( "("+REAL+").+"  , "$1" ) );
         part[1] = Double.parseDouble( s.replaceAll( ".+("+OP+NUM+")"+I , "$1" ) );
      }
	this.re = part[0];
	this.im = part[1];
   }

   //---------------------------------------------------------------------------
   // Public methods 
   //---------------------------------------------------------------------------

   // Complex arithmetic -------------------------------------------------------

   // copy()
   // Return a new Complex equal to this Complex
   Complex copy(){
      // Fill in
	Complex B = new Complex(re, im);
	return B;
   }
   
   // add()
   // Return a new Complex representing the sum this plus z.
   Complex add(Complex z){
      // Fill in
      //  Complex B = new Complex(this.re+z.re, this.im+z.im);
      //	return B;
    	this.re = this.re+z.re;
	this.im = this.im+z.im;
	Complex B = new Complex(this.re, this.im);
	return B;
   }
   
   // negate()
   // Return a new Complex representing the negative of this.
   Complex negate(){
   	Complex B = new Complex(-1*(this.re), -1*(this.im));
	return B;
   }

   // sub()
   // Return a new Complex representing the difference this minus z.
   Complex sub(Complex z){
      	Complex B = new Complex(this.re-z.re, this.im-z.im);
        return B;
   }

   // mult()
   // Return a new Complex representing the product this times z.
   Complex mult(Complex z){
        Complex B = new Complex(this.re*z.re-this.im*z.im, this.re*z.im+this.im*z.re);
	return B;
   }

   // recip()
   // Return a new Complex representing the reciprocal of this.
   // Throw an ArithmeticException with appropriate message if 
   // this.equals(Complex.ZERO).
   Complex recip(){
   	if(this.equals(Complex.ZERO)){
        	throw new NumberFormatException(
			"Cannot find reciprocal of string");
	}
	Complex B = new Complex(this.re/
		(Math.pow(this.re, 2)+Math.pow(this.im, 2)),  
		(-1*this.im)/
		(Math.pow(this.re, 2)+Math.pow(this.im, 2)));
	return B;
   }

   // div()
   // Return a new Complex representing the quotient of this by z.
   // Throw an ArithmeticException with appropriate message if 
   // z.equals(Complex.ZERO).
   Complex div(Complex z){
      	if(this.equals(Complex.ZERO)){
                throw new NumberFormatException(
                        "Cannot find quotient of string"); 
	}
//	Complex B = new Complex((this.re*this.im+z.re*z.im)/
//		(Math.pow(this.re,2) + Math.pow(z.re,2)), 
//		((this.re*z.im-z.re*this.im)/
//		(Math.pow(this.re,2) + Math.pow(z.re,2))));
	Complex B = new Complex((this.re*z.re+this.im*z.im)/
                (Math.pow(z.im,2) + Math.pow(z.re,2)), 
                ((this.im*z.re-this.re*z.im)/
                (Math.pow(z.im,2) + Math.pow(z.re,2)))); 
	return B;
   }

   // conj()
   // Return a new Complex representing the conjugate of this Complex.
   Complex conj(){
	Complex B = new Complex(this.re, -1*this.im);
	return B;
   }
   
   // Re()
   // Return the real part of this.
   double Re(){
      return re;
   }

   // Im()
   // Return the imaginary part of this.
   double Im(){
      return im;
   }

   // abs()
   // Return the modulus of this Complex, i.e. the distance between 
   // points (0, 0) and (re, im).
   double abs(){
	return Math.sqrt(Math.pow(this.re, 2) + Math.pow(this.im, 2));
   }

   // arg()
   // Return the argument of this Complex, i.e. the angle this Complex
   // makes with positive real axis.
   double arg(){
      return Math.atan2(im, re);
   }

   // Other functions ---------------------------------------------------------
   
   // toString()
   // Return a String representation of this Complex.
   // The String returned will be readable by the constructor Complex(String s)
   public String toString(){
	String a = Double.toString(this.re);
	String b = Double.toString(this.im);
	if (this.im>0){
		if(this.re==0.0){
                	return(b+"i");
		}
		else return(a+"+"+b+"i");
	}
   	
	else if(this.im<0){
		return(a+b+"i");
	}
	else if(this.im==0.0){
		return(a);
	}
	else return ("NaN");
   }

   // equals()
   // Return true iff this and obj have the same real and imaginary parts.
   public boolean equals(Object obj){
	if (obj==this){
		return true;
	} else { 
		return false;
	}
   }

   // valueOf()
   // Return a new Complex with real part a and imaginary part b.
   static Complex valueOf(double a, double b){
	Complex B = new Complex(a, b);
	return B;
   }

   // valueOf()
   // Return a new Complex with real part a and imaginary part 0.
   static Complex valueOf(double a){
	Complex B = new Complex(a);
	return B;
   }

   // valueOf()
   // Return a new Complex constructed from s.
   static Complex valueOf(String s){
	Complex B = new Complex(s);
	return B;
   }
}
