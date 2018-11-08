import java.util.Scanner;

class ArrayEx2{

   public static void main( String[] args ){

      Scanner sc = new Scanner(System.in);
      int i, n;
      String[] list;

 
      System.out.print("Enter the list length: ");
      n = sc.nextInt();

     
      list = new String[n];

      System.out.println("Enter " + n + " words: ");
      for(i=0; i<n; i++){
         list[i] = sc.next();
      }

         System.out.print("\nIn reverse order: ");
      for(i=n-1; i>=0; i--){
         System.out.print(list[i]+" ");
      }
      System.out.println("\n");
   
   }

}


