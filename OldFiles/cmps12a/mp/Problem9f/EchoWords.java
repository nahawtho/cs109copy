//EchoWords.java
import java.util.Scanner;
class EchoWords{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String n;
		while(sc.hasNext()){
			n = sc.next();
			if(n.equals("galumph")){
				System.out.println("bye!");
				System.exit(1);
			}
			else System.out.println(n);
		}
	}
}

// notes:
// import the scanner
// declare string n
// sc.hasNextString() has ()
// print("bye!"), not (bye!)
// NEXTSTRING DNE: USE sc.next
// Strings use variable.equals("String") not ==
