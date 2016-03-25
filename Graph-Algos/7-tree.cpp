// Check if a given graph is a Tree
/*
if(N-1 edges)
 {
	if(No cycles)  [checking for no cycles since graph can n-1 edges and have cycles]
	{
		A tree with output YES
		}
	}
 }
 */

#include <bits/stdc++.h>

#define MN (int)1e5

using namespace std;

#define all(c) c.begin(),c.end()
#define tr(container, it) \ 
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)

vector<long long int> Graph[MN+1];
vector<long long int> dist(MN+1);
bool cycle=false;

//depth-first search from starting node till you find the farthest leaf

void farthestleaf(long long root,long long parent,long long startd)
{		
	//cout << "Processing node - " << root << " from parent - " << parent << endl;
	if(dist[root]!=0)
	{
		//cout << "Cycle Exists!" << endl;
		cycle = true;
		return;
	}

	dist[root]=startd;
	long long i=0;
	if(Graph[root].size()!=1 || (Graph[root].size()==1 && parent == -1))
	{
		for(i=0;i<Graph[root].size();i++)
		{
			if(Graph[root][i]!=parent)
			{
				farthestleaf(Graph[root][i],root,startd+1);
			}
		}
	}
}

long long zeronode(long long N)
{	
	long long node = -1;
	long long i=1;
	while(i<N)
	{
		if(dist[i]==0)
		{	
			node = i;
			break;
		}
		i++;
	}
	return node;
}

int main() 
{
	long long int N,M,i,a,b;
	cin >> N >> M;
	
	if(M!=N-1)
	{
		cout << "NO" << endl;
		return 0;
	}

	dist.resize(N);
	fill(dist.begin(), dist.end(), 0);
	
	for(i=0;i<M;i++)
	{   
		a=b=0;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
    
    //take a random node to be root. dfs to find the vertex at max distance from it. 
	farthestleaf(0,-1,0);
    long long key = zeronode(N);
    if(key == -1)
    {
	    if(cycle)
	    {
		    //cout<< " Cycle exists" << endl;
		    cout << "NO"<<endl;
	    	return 0;
	    }
		else 
	    {
	        cout << "YES" << endl;   
	    }	

	}
	else
	{   
	    cout << "NO"<<endl;
	    return 0;
	}
	
	return 0;
	
}
