//GCD.c
//Nicholas Hawthorne
//1536694
//lab8
//emulates GCD program from pa3 using the c programming language.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	int i, n; /* initializes min max and remainder */
	char str[100];
	double x[2];
	for(i=0; i<1; i++){	
		printf("Enter a positive integer: ");
		n = scanf( "%s", str);
		while(1){
			while( !isDouble(str) ) {
				printf("Please enter a positive integer: ");
				n = scanf( "%s", str);
			}
			//str can now be converted to double

			sscanf(str, "%lf", &x[i]);
			if ( x[i]>0 ) break;
			printf("Please enter a positive integer: ");
			n = scanf( "%s", str);
		}
	}
	 for(i=1; i<2; i++){ 
                printf("Enter another positive integer: ");
                n = scanf( "%s", str);
                while(1){
                        while( !isDouble(str) ) {
                                printf("Please enter a positive integer: ");
                                n = scanf( "%s", str);
                        }
                        //str can now be converted to double

                        sscanf(str, "%lf", &x[i]);
                        if ( x[i]>0 ) break;
                        printf("Please enter a positive integer: ");
                        n = scanf( "%s", str);
                }
        }
	
	
	int a = (int) x[0]; int b = (int) x[1];
	printf("The GCD of %d and %d is %d\n", a, b, gcd(a, b));
	return 0;
}
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
int gcd(int a, int b){
	int r, temp;
	while (b!=0){ r = a%b; a=b; b=r;}
	return a;
}

