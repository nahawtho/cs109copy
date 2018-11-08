// Problem3a.java
// midterm 2 review problem 3
class Problem3a{
 public static void main(String[] args) {
 System.out.println(f(7));
 }
 static int f(int n){
 System.out.println( "f(" + n + ")" );
 if(n<=1)
 return 2;
 else
 return f(n-1) + 5;
 }
}
