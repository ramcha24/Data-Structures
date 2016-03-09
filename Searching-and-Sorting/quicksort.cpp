// Normal Quicksort.
#include <bits/stdc++.h>

using namespace std;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) c.begin(),c.end()
#define tr(container, it)\ 
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)


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

void qsort1(vector<int>& A,int beg,int end)
{
	if(end==beg)
		return;

	//choosing first element as pivot always
	int pivotelement = A[beg];

	int partitionindex = Partition(A,beg,end);

	if(partitionindex==beg)
		qsort1(A,beg+1,end);

	else if(partitionindex==end)
		qsort1(A,beg,end-1);
	else
	{
		qsort1(A,beg,partitionindex-1);
		qsort1(A,partitionindex+1,end);
	}
}

int main()
{
	int i,j,k;
	std::vector<int> A(8);
	vector<int>::iterator it;

	for(i=0;i<8;i++)
	{
		cin >> j;
		A[i]=j;
	}

	qsort1(A,0,7);

	tr(A,it)
		cout << *it << endl;

}