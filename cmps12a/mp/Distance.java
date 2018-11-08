//Distance.java

class Distance{
// Data Field
	private double meters;
// Constructor
	Distance(double m){meters = m;}
// Methods
	double getMeters(){
	return meters;
	}
	double getFeet(){
	return (meters * 3.28);
	}
	double getFurlongs(){
	return (meters / 201.17);
	}
} 
