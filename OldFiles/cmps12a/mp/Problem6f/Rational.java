// Rational.java
class Rational{
	int numerator; int denominator; // Fields
	Rational(int n, int d){ // Constructor
		if(d==0) throw new RuntimeException("zero denominator");
		numerator = n; denominator = d;
	}
	Rational plus(Rational Q){
		int a = this.numerator*Q.denominator;
		int b = this.denominator*Q.denominator; //should = d
		int c = Q.numerator*this.denominator;
		int d = Q.denominator*this.denominator;
		Rational B = new Rational (a+c, d);
		return B;
	}
	Rational times(Rational Q){
		Rational B = new Rational (this.numerator*Q.numerator,
		this.denominator*Q.denominator); 
		return B;
	}
	public String toString(){
		String B = new String(this.numerator+"/"+this.denominator);
		return B; 
	}
	public boolean equals(Object x){
		Rational z = (Rational)x;
		double a = (double)this.numerator;
		double b = (double)this.denominator;
		double c = (double)z.numerator;
		double d = (double)z.denominator;
		return (a/b == c/d);
	}
} // end of class Rational
