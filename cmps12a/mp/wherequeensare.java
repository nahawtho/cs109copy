//wherequeensare.java
import java.util.Scanner;

class wherequeensare{
        public static void main (String [] args){
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
                for (int i=n; i<=i-1 ; i++){ //prints the checking function above
        		for (int j=i+1; i<=n; j++){
                		System.out.print(i + " " + j + " ");
        		}
        	System.out.println();
		}
	}
}
