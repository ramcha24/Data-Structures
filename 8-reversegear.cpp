#include <bits/stdc++.h>

#define MAX (int)1e5
#define pp pair<int,int>
#define tr(container,it) \
	for(typeof(container.begin()) it = container.begin();it != container.end(); it++)

using namespace std;

class Prioritize
{
	public:	
		int operator() (const pair<int,int>& p1, const pair<int,int>& p2)
		{
			return p1.second > p2.second;
		}
};

vector <pp> G[MAX];
vector<int> d(MAX,MAX);
bool visited[MAX];

int main()
{
	priority_queue < pp , vector<pp> , Prioritize > Q;

	int n,e,u,v,w;

	cin >> n;
	cin >> e;
	int i;

	for(i=1;i<=e;i++)
	{
		cin >> u >> v;
		G[u].push_back(pp(v,0));
		G[v].push_back(pp(u,1));
	}

	int source = 0;
	//cin >> source;
	d.resize(n+1);

	for(i=0;i<n;i++)
	{
		d[i] = MAX;
		visited[i] = false;
	}

	d[source] = 0;
	visited[source] = true;

	Q.push(pp(source,d[source]));

	while(!Q.empty())
	{
		pp top = Q.top();
		u = top.first;
		int dist = top.second;
		Q.pop();

		//if(visited[u])
		//	continue;

		visited[u] = true;
		int size = G[u].size();

		for(int i=0;i<size;i++)
			{
				v = G[u][i].first;
				w = G[u][i].second;

				if(d[v] > d[u] + w)
				{	
					d[v] = d[u] + w;
					Q.push(pp(v,d[v]));
				}
			}
	}

	if(visited[n-1])
		cout << d[n-1] << endl;
	else
		cout << -1 << endl;
	return 0;
}
