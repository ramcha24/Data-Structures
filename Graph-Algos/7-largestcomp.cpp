// Find the size of the largest connected component

#include <bits/stdc++.h>

#define MN (int)1e5

using namespace std;

#define all(c) c.begin(),c.end()
#define tr(container, it) \ 
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)

vector<long long int> Graph[MN+1];
int visited[MN+1];
vector<int> numofcolour(MN+1);

long long currentcolour = 0;
	
void dfscolour(long long root,long long parent)
{	
	visited[root]=1;
	numofcolour[currentcolour]++;
	
	long long i=0;
	for(i = 0; i < Graph[root].size(); i += 1) 
    {
        if (Graph[root][i] != parent) 
        {   
            if(visited[Graph[root][i]]!=1)
                dfscolour(Graph[root][i], root);
        }
    }
    
    if (Graph[root].size() == 1 & Graph[root][0] == parent) 
    { return; } 	
	
}

int main() 
{
	long long int N,M,i,a,b;
	cin >> N >> M;
	
	numofcolour.resize(N);
	
	for(i=0;i<M;i++)
	{   
		a=b=0;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
    
    for(i=0;i<N;i++)
	{	
	    numofcolour[i]=0;
	    visited[i]=0;
	}
	
	long long key = 0;
	
	for(i=0;i<N;i++)
	{
		if(visited[i]!=1)
		{	
			dfscolour(i,-1);
			currentcolour++;
		}
			
	}

    numofcolour.resize(currentcolour);
    
    vector<int>::const_iterator it = max_element(numofcolour.begin(), numofcolour.end());
    
    cout << *it << endl;
    
	return 0;
	
}