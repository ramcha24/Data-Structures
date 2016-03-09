// Check if a given graph is Bipartite
/*
Color alternatively with two colours in dfs calls and if there are no conflicts then its a Bipartite Graph

Conflct =  trying to a colour an already colored vertex with a diff colour

*/

#include <bits/stdc++.h>

#define MN (int)1e5

using namespace std;

#define all(c) c.begin(),c.end()
#define tr(container, it) \ 
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)

vector<long long int> Graph[MN+1];
int colour[MN+1];
bool Bipartite=true;

//bipartitue default true, if conflict then false, if repeat then terminate dfs
//normal termination when all vertices exhausted

void dfscolour(long long root,long long parent,int c)
{		
	cout << "Processing node - " << root << " from parent - " << parent << endl;
	
	//check if root is already been colored with a diff color
	if(colour[root] != 0 && colour[root] != c)
	{
		cout << "Color conflict !" << endl;
		Bipartite = false;
		return;
	}
	else if(colour[root]==c)
	{
		cout << "Component will repeat again with same colours. No issue" << endl;
		Bipartite = true;
		return;
	}

	int newc = 2-((c+1)%2);
	colour[root] = c;
	long long i=0;
	if(Graph[root].size()!=1 || (Graph[root].size()==1 && parent == -1))
	{
		for(i=0;i<Graph[root].size();i++)
		{
			if(Graph[root][i]!=parent)
			{	
				cout << c << newc << endl;
				dfscolour(Graph[root][i],root,newc);
			}
		}
	}
}
	
long long zeronode(long long N)
{	
	long long node = -1;
	long long i=0;
	while(i<N)
	{
		if(colour[i]==0)
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
	
	for(i=0;i<M;i++)
	{   
		a=b=0;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	for(i=0;i<N;i++)
		colour[i]=0;

	//take a node with colour zero to be root. dfscolour with inital colour 1 , it will alternate between 1 and 2. 
	//keep repeating until no nodes with zero colour are left (for disconnected graph)
	long long key = zeronode(N);
	while(key!=-1)
	{ 	
		cout << "Key is - " << key << endl;
		dfscolour(key,-1,1);
		cout << "Out of dfs"<<endl;
		key = zeronode(N);
		cout << "New key is " << key << endl;
	}


	if(Bipartite)
		cout << "Yes! its a Bipartite graph!" << endl;
	else
		cout << "Nope!" <<endl;
	
	return 0;
	
}
