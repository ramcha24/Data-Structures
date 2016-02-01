#include <iostream>
#include <stdio.h>

using namespace std;

void printARR(int *arr, int len){

	for(int i=0; i<len;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

long long int Merge(int *arr, int start, int mid, int end){
	long long int inversion=0;
	int i=0;
	int j=0;
	int k=start;

	// A = [start.....mid]
	int l1 = mid-start+1;
	int A[l1];
	for(i=start,j=0;i<=mid;++i,++j)
		A[j]=arr[i];

	// B = [mid+1...end]
	int l2 = end-(mid+1)+1;
	int B[l2];
	for(i=mid+1,j=0;i<=end;++i,++j)
		B[j]=arr[i];
	
	i=0;
	j=0;
	while( i<l1 && j<l2 ){
		if(A[i]<=B[j]){
			arr[k++]=A[i++];
		}
		else{
			int demi=i+start;
			inversion+=mid+1-demi;
			// inversion+=mid+1-i;
			arr[k++]=B[j++];
		}
	}

	while( i<l1 )
		arr[k++]=A[i++];

	while( j<l2 )
		arr[k++]=B[j++];

	return inversion;
}

long long int merge_sort(int *arr, int start, int end){
	long long int inversion=0;
	if(start<end) {
		int mid = (start + end)/2;
		inversion+=merge_sort(arr, start, mid);
		inversion+=merge_sort(arr, mid+1, end);
		inversion+=Merge(arr, start, mid, end);
	}
	return inversion;
}

int main(int argc, char const *argv[]) 
{
	int arr[200001];
	int N;
	int i;

	scanf ("%d",&N);
	for (i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	cout<<merge_sort(arr,0,N-1)<<"\n";

	return 0;
}
