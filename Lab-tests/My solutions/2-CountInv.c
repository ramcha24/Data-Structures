#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printarray(long long int A[],int N);
long long int CountInv(long long int A[],int left, int right);
long long int CountInvAcross(long long int A[],int left,int mid,int right);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    long long int A[100000];
    scanf("%d\n",&N);
    int i;
    for(i=0;i<N;i++)
    {
        scanf("%lld",&A[i]);
    }
    
    long long int count = CountInv(A,0,N-1);
    
    printf("%lld\n",count);
    //printf("%lld\n",CountInvAcross(A,0,2,4));
    
    //printarray(A,N);   
        
    return 0;
}

void printarray(long long int A[],int N)
{
	int i;
    for(i=0;i<N;i++)
    {
        printf("%lld ",A[i]);
    }    
}   

long long int CountInv(long long int A[],int left, int right)
{	
	long long int count = 0;
	long long int cil,cir,cia;
	cil=0;
	cir=0;
	cia=0;
    if(left<right)
    {
        int mid = left + (right - left)/2;
        cil = CountInv(A,left,mid);
        cir = CountInv(A,mid+1,right);
        cia = CountInvAcross(A,left,mid,right);
    }
    count = cil+cir+cia;
    return count;
}    

long long int CountInvAcross(long long int A[],int left,int mid,int right)
{
    int i,j,k;
    long long int count=0;
    
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    long long int L[n1],R[n2];
    
    k=0;
    for(i=left;i<=mid;i++)
    {
        L[k]=A[i];
        k++;
    }
    
    
    k=0;
    for(i=mid+1;i<=right;i++)
    {
        R[k]=A[i];
        k++;
    }
    
    i=j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
            k++;
        }
        else
        {
            A[k]=R[j];
            j++;
            k++;
            count = count + n1 - i;
        }
    }
    
    while(i<n1)
    {
            A[k]=L[i];
            i++;
            k++;
    }    
    
    while(j<n2)
    {
            A[k]=R[j];
            j++;
            k++;
    }
    
  
    return count;
    
    
}

