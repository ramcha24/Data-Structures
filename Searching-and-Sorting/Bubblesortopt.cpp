/* Bubblesort Optimized Algorithm 
Author - Ramcha

Each pass through an array passes through swaps i,i+1 for every inversion
Requires one full iteration with zero swaps to terminate

Worst Case Time Complexity : O(n^2)
Best Case Time Complexity : O(n)
Auxiliary Space : O(1)


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


void Bubblesort(int N,int A[])
{
	int i,j;
	bool swaps;
	for(i=0;i<N;i++)
	{	
		swaps=false;

		for(j=0;j<N-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
				swaps=true;
			}
		}
		
		if(swaps==false)
			return;
	}	
}

int main()
{
	int N;
	int A[10];

	getinp(&N,A);
	Bubblesort(N,A);
	showout(N,A);

	return 0;
}
