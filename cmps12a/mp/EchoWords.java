//EchoWords.java
import java.util.Scanner;
class EchoWords{
	public static void main (String [] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextString){
			if (sc == "galumph") break;
			System.out.println(sc);
		}
	}
}
