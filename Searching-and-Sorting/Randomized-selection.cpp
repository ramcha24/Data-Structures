// Normal Quicksort.
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) c.begin(),c.end()
#define tr(container, it)\ 
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)

//to generate random numbers
int rangeRandomAlg2 (int min, int max){
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);
    return min + x % n;
}

int Partition(vector<int>& A,int beg,int end)
{
	int pivotelement = A[beg];

	//two pointers i and j;
	int i,j;
	i=j=beg+1;

	while(j<=end)
	{	
		if(A[j]<pivotelement)
		{	
			swap(A[i],A[j]);
			i++;
		}
		j++;
	}

	swap(A[beg],A[i-1]);
	
	return i-1;
}

int Rselect(vector<int>& A,int beg,int end,int K)
{
	cout << "K is " << K << endl;
	cout << "Inside Rselect of beg , end " << beg << " " << end << endl;
	if(end==beg)
		return A[beg];

	//Choosing pivot randomly
	int pivotno = rangeRandomAlg2(beg,end);
	cout << "Pivot chosen randomly was - " << pivotno << " and pivotelement was - " << A[pivotno] << endl;

	swap(A[beg],A[pivotno]);

	int partitionindex = Partition(A,beg,end);

	tr(A,it)
		cout << " " << *it;

	cout << " Above partitionindex is "<< partitionindex<<endl;

	if(partitionindex == K)
		return A[partitionindex];
	else if(partitionindex > K)
		return Rselect(A,beg,partitionindex-1,K);
	else
		return Rselect(A,partitionindex+1,end,K);
}

int main()
{
	int i,j,k;
	std::vector<int> A(8);
	vector<int>::iterator it;

	cin >> k;

	for(i=0;i<8;i++)
	{
		cin >> j;
		A[i]=j;
	}

	cout << Rselect(A,0,7,k-1) << endl;
}