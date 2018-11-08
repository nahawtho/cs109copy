#define NUMELTS 100
# include <stdio.h>
#include <iostream>
#include <math.h>
void radixsort(int a[],int);
int main()
{  
	int n,a[20],i;
 	printf("enter the number :");
	scanf("%d",&n);
	printf("ENTER THE DATA -\n");
	for(i=0;i<n;i++)
	{
	      printf("%d.  ",i+1);
	      scanf("%d",&a[i]);
   	}
	radixsort(a,n);
}
void radixsort(int a[],int n)
{
	int rear[10],front[10],first,p,q,exp,k,i,y,j;
	struct
	{
		int info;
  		int next;
	}node[NUMELTS];
	for(i=0;i<n-1;i++)
	{
		node[i].info=a[i];
  		node[i].next=i+1;
	}
	node[n-1].info=a[n-1];
	node[n-1].next=-1;
	first=0;
	for(k=1;k<=2;k++)     
	{
		for(i=0;i<10;i++)
		{
			front[i]=-1;
		      	rear[i]=-1;	
		}
		while(first!=-1)
		{
		       p=first;
		       first=node[first].next;
		       y=node[p].info;
		       exp=pow(10,k-1);
		       j=(y/exp)%10;
		       q=rear[j];
		       if(q==-1)
               	           front[j]=p;
		       else
		            node[q].next=p;
			    rear[j]=p;
 		}
    		for(j=0;j<10&&front[j]==-1;j++);
		first=front[j];
    		while(j<=9)
                 {
      		        for(i=j+1;i<10&&front[i]==-1;i++);
		        if(i<=9)
			{
				p=i;
	                         node[rear[j]].next=front[i];
			}
			j=i;
			}
			node[rear[p]].next=-1;
         	}
		for(i=0;i<n;i++)
		{
			a[i]=node[first].info;
			first=node[first].next;
		}
		printf("DATA AFTER SORTING:\n");
		for(i=0;i<n;i++)
		printf("%d .   %d\n",i+1,a[i]);
	}
