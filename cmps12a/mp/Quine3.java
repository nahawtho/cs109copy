class Quine3{
   public static void main(String[] args){
      String p = "class Quine3{%c	 public static void main(String[] args){%1$c      String p = %c%s%2$c;%1$c      System.out.printf(p, 10, 34, p);%1$c   }%1$c}%1$c";
      System.out.printf(p, 10, 34, p);
   }
}
