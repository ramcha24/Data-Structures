#include <bits/stdc++.h>

using namespace std;

#define MAX (int)1e5
#define tr(container,it) \
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)
#define all(c) c.begin(),c.end()

vector<long long> Graph[MAX+1];
int level[MAX+1];
int visited[MAX+1];

int main()
{
	long long N,M,i,a,b;

	cin >> N >> M;

	for(i=0;i<M;i++)
	{
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	long long currentlevel=0;

	queue<int> q;

	q.push(0);

	long long x = 0;
	level[0]=0;

	while(!q.empty())
	{
		x = q.front();
		cout<< "Processing node - " << x <<endl;
		visited[x]=1;
		//level[x]=currentlevel;
		cout << "It is at level - " << level[x] << endl;
		q.pop();
		for(i=0;i<Graph[x].size();i++)
		{
			if(visited[Graph[x][i]]!=1)
			{	
				q.push(Graph[x][i]);
				level[Graph[x][i]] = level[x]+1;
			}
		}
	}
}