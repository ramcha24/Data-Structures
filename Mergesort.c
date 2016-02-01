#include<stdlib.h>
#include<stdio.h>

int main()
{
	int i,j,k;

}

void mergesort(int A[], int beg, int end)
{
	if(beg<end)
	{	int mid = (beg+end)2;
		mergesort(A,beg,mid);
		mergesort(A,mid+1,end);
		Merge(A,beg,mid,end);
	}
}

void Merge(int A[],int beg,int mid,int end)
{
	int i,j,k;
	j= mid+1;
	i=k=beg;
	int B[end];


	while(i<=mid && j<end)
	{
		if(A[i] > A[j])
		{	B[k] = A[j];
			k++; j++;
		}
		else
		{	B[k] = A[i];
			k++;i++;
		}
	}

	while(i<=mid)
	{
		B[k] = A[i];
		k++; i++;
	}

	while(j< end)
	{
		B[k] = A[j];
		k++; j++;
	}
	
	for(k=beg;k<end;k++)
	{
		A[k] = B[k];
	}
}
