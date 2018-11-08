//Problem10a
class Problem10a{
	public static void main(String[] args){
	String[] A = {"one", "two", "three", "four"};
	
	printStringArray(A);
	}
	static void printStringArray(String[] X){
		int i;
		for(i = (X.length-1); i>=0; i--){
			System.out.println(X[i]);
		}
	}
}
