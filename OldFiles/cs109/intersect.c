// CPP program to check if a line touches or  
// intersects or outside a circle. 
#include <stdio.h> //printf
#include <math.h> //sqrt
#include <stdlib.h> //abs

void checkCollision(int a, int b, int c,  
                  int x, int y, int radius) 
{ 
    // Finding the distance of line from center. 
    int dist = (abs(a * x + b * y + c)) /  
                     sqrt(( a * a + b * b )); 
  
    // Checking if the distance is less than,  
    // greater than or equal to radius. 
    if (radius == dist) 
        printf("Touch\n"); 
    else if (radius > dist) 
	printf("Intersect\n");
    else
	printf("Outside\n");
} 
  
// Driven Program 
int main() 
{ 
    int radius = 5; 
    int x = 0, y = 0; 
    int a = 3, b = 4, c = 25; 
    checkCollision(a, b, c, x, y, radius); 
    return 0; 
} 
