/* Selection Sort Algorithm 

Author - Ramcha

Worst Case Time Complexity : O(n^2)
Best Case Time Complexity : O(n)
Auxiliary Space : O(n)


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
	int i,j,key;
	for(i=0;i<N;i++)
	{	
		key=i;
		
		for(j=i;j<N;j++)
		{   
			if(A[j]<A[key])
				key=j;
		}
		swap(&A[i],&A[key]);
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
