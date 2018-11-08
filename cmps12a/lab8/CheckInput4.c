#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
   int i, n;
   double x[3];
   char str[100];

   // get three positive doubles from the user
   for(i=0; i<3; i++){
      printf("Enter a positive double: ");
      n = scanf(" %s", str); // read one token from stdin
      
      while( 1 ){ // seemingly infinite loop
      
         
         while( !isDouble(str) ){ // if its not a double
            printf("Please enter a positive double: "); // ask again
            n = scanf(" %s", str);             // get another string
         }
         // at this point str is a string that should be convertable to double

         sscanf(str, "%lf", &x[i]);  // convert str to double and store in array x[]
         if( x[i]>0 ){               // if it's positive
            break;                   // get out of the while loop
         }
         printf("Please enter a positive double: "); // otherwise ask again
         n = scanf(" %s", str);                      // and get another
      }
      // break lands here
   }
   // do the whole thing 3 times and end up here
   printf("Here they are: %f %f %f\n", x[0], x[1], x[2]);

   return 0;
}

// isDouble()
// Returns 1 (true) if string s[] can be interpreted as a double, and
// returns 0 (false) otherwise.
int isDouble(char s[]){
   int i, n, num_points;
   
   if( s==NULL ) 
      return 0; 
   n = strlen(s);  
   if( n==0 ) 
      return 0;
   num_points = ( s[0]=='.' ? 1 : 0 );
   if( s[0]!='.' && s[0]!='-' && s[0]!='+' && !isdigit(s[0])  )
      return 0;
   for(i=1; i<n; i++){
      if( s[i]=='.' ) num_points++;
      if( ( !isdigit(s[i]) && s[i]!='.' ) || num_points>1 ) 
         return 0;
   }
   return 1;
}


