#include <bits/stdc++.h>

#define MN (int)1e5

using namespace std;

#define all(c) c.begin(),c.end()
#define tr(container, it) \ 
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)

vector<long long int> Graph[MN+1];
vector<long long int> dist(MN+1);
int visited[MN+1];

//depth first search which maintains a visited array and a distance array.
//traverses depth first from starting node and marks nodes visitied along the way.
//calculates distance of each node processed from the starting node

void dfs(long long root,long long parent,long long startd)
{	
	cout << "Processing node - " << root << " from parent - " << parent << endl;
	visited[root]=1;
	dist[root]=startd;
	long long i=0;
	if(Graph[root].size()!=1 || (Graph[root].size()==1 && parent == -1))
	{
		for(i=0;i<Graph[root].size();i++)
		{
			if(Graph[root][i]!=parent)
			{
				dfs(Graph[root][i],root,startd+1);
			}
		}
	}
}

int main() 
{
	long long int N,M,i,a,b;
	cin >> N >> M;
	
	dist.resize(N);
	
	for(i=0;i<M;i++)
	{   
		a=b=0;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	dfs(0,-1,0);

	tr(dist,it)
		cout << *it << endl;		

	return 0;
	
}
