class Quine{
   public static void main(String[] args){
      char[] c = {32,32,32,32,32,32,32,32,32};
      String s = new String(c);
      String[] p = {
         "class Quine{",
         "   public static void main(String[] args){",
         "      char[] c = {32,32,32,32,32,32,32,32,32};",
         "      String s = new String(c);",
         "      String[] p = {",
         "      };",
         "      for(int i=0;i<5;i++) System.out.println(p[i]);",
         "      for(int i=0;i<p.length;i++) System.out.println(s+(char)34+p[i]+(char)34+',');",
         "      for(int i=5;i<p.length;i++) System.out.println(p[i]);",
         "   }",
         "}",
      };
      for(int i=0;i<5;i++) System.out.println(p[i]);
      for(int i=0;i<p.length;i++) System.out.println(s+(char)34+p[i]+(char)34+',');
      for(int i=5;i<p.length;i++) System.out.println(p[i]);
   }
}
