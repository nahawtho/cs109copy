// Problem4a.java
// midterm 2 review
import java.util.Scanner;
class Problem4a{
public static void main(String[] args){	
	System.out.print("enter a number");
	Scanner sc = new Scanner(System.in);
	int x = sc.nextInt();
	int sum = add(x);
	System.out.print(sum);	
}
	static int add(int n){
		int result;
		if(n==1) return 1;
		result = add(n-1) + n;
		return result;		

	}
}

