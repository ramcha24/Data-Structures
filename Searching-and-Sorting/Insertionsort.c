/* Insertion Sort Algorithm 

Author - Ramcha

Time Complexity : O(n^2)
Auxiliary Space : O(1+)


*/

#include<stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void getinp(int *N,int A[])
{

	printf("Enter the number of elements: ");
	scanf("%d",N);
	printf("%d",*N);
	printf("Enter the array :  ");
	int i;
	for(i=0;i<*N;i++)
	{
		scanf("%d",&A[i]);
	}

}


void showout(int N,int *A)
{

	int i=0;
	printf("\n");
	for(i=0;i<N;i++)
	{	
		printf("%d \t",A[i]);
	}
	printf("\n");
}


void Insertionsort(int N,int A[])
{
	int i,j,key;
	for(i=1;i<N;i++)
	{	
		for(j=i;j>0;j--)
		{   
			if(A[j]<A[j-1])
				swap(&A[j],&A[j-1]);
		}
	}
}

int main()
{
	int N;
	int A[10];

	getinp(&N,A);
	Insertionsort(N,A);
	showout(N,A);

	return 0;
}
