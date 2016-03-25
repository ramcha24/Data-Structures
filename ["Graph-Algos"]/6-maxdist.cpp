#include <bits/stdc++.h>

#define MN (int)1e5

using namespace std;

vector<long long int> Graph[MN+1];
vector<long long int> dist(MN+1);

void farthestleaf(long long root,long long parent,long long startd)
{	
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

int main() 
{
	long long int N,R,i,a,b,j;
	cin >> N;
	dist.resize(N+1);
	for(i=0;i<N-1;i++)
	{   
		a=b=0;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	farthestleaf(0,-1,0);

	long long leaf = 0;

	vector<long long>::iterator it = max_element(dist.begin(),dist.end());

	leaf = distance(dist.begin(),it);

	//take a random node to be root. dfs to find the vertex at max distance from it. 
	//make the new vertex as root and find max height.
	
	fill(dist.begin(), dist.end(), 0);

	farthestleaf(leaf,-1,0);

	for(i=0;i<N;i++)
	{
		if(dist[leaf] <= dist[i])
			leaf = i;	
	}
	
	cout << dist[leaf]<<endl;
	
		
	return 0;
	
}
