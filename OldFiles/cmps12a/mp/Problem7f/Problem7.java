// Problem7.java
import java.util.Scanner;
import java.io.*;
class Problem7{
	public static void main(String[] args){

		Scanner sc=null;
		double n=0; int i=0;

		if (args.length!=1){
			Usage();
		}
		//attempt to open file args[0]
		try{
			sc = new Scanner(new File(args[0])); //possible 
			//FileNotFoundException
		}catch(FileNotFoundException e){
			System.err.println(e.getMessage());
			Usage();
		}
		while(sc.hasNext()){
			if(sc.hasNextDouble()){
				n+=sc.nextDouble();
				i++;	
			}
			else{
				sc.next(); //discard
			}
		}
		sc.close();
		System.out.println("The average value in the file test is "+n/i);
	}
	static void Usage(){
		System.err.println("Usage: java Problem7 <input file>");
		System.exit(1);
	}
}

//problems encountered: must close main before functions. Must remember how to throw exceptions. Scanner is always capitalized, as is System. Always initialize variables to zero if their initialization is dependent on an if or while statement or something of the kind.


