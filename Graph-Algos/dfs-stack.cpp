#include <bits/stdc++.h>

#define MN (int)1e5

using namespace std;

#define all(c) c.begin(),c.end()
#define tr(container, it) \ 
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)

vector<long long int> Graph[MN+1];
int visited[MN+1];

//depth first search which maintains a visited array and a distance array.
//traverses depth first from starting node and marks nodes visitied along the way.

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

	stack<long long int> s;

	s.push(0);

	long long x;

	while(!s.empty())
	{
		x = s.top();
		visited[x] = 1;
		s.pop();
		cout<< "Processing node - " << x <<endl;
		
		for(i=0;i < Graph[x].size(); i++)
		{
			if(visited[Graph[x][i]] != 1)
				s.push(Graph[x][i]);
		}

	}

	return 0;
	
}
