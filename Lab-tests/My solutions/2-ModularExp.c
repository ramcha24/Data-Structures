#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int M = 1000000007;

/*
void printarray(long long int A[],int N);
void mergesort(long long int A[],int left, int right);
void Merge(long long int A[],int left,int mid,int right);
*/


long long int Modulo(long long int A,long long int B);


int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    long long int A,B;
    scanf("%lld %lld",&A,&B);
   
   	long long int result = Modulo(A,B);
   	printf("%lld\n",result);
        
    return 0;
}

long long int Modulo(long long int A,long long int B)
{	
	if(B==0)
	{return 1;}
	
	if(B==1)
	{
		return A%M;
	}
	else
	{
		long long int m1,m2,result;
		if(B%2==0)
		{	
			m1 = m2 = Modulo(A,B/2);
			result = (m1*m2)%M;
		}
		else
		{
			m1 = Modulo(A,B/2);
			m2 = Modulo(A,B-B/2);
			result = (m1*m2)%M; 
		}
		return result%M;
	}
}

