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

	int T;
	cin >> T;

	while(T>=0)
	{ 
		T--;
	int n,e,u,v,w;

	cin >> n;
	//G.resize(n+1);
	cin >> e;

	//cout << "Vertices , Edges - " << n << " " << e << endl;

	int i;

	for(i=1;i<=e;i++)
	{
		cin >> u >> v >> w;
		//cout << "Vertex1 , Vertex 2 , Weight - " << u << " " << v << " " << w << endl;
		G[u].push_back(pp(v,w));
		G[v].push_back(pp(u,w));
	}

	int source;
	cin >> source;
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
		u = Q.top().first;
		Q.pop();

		visited[u] = true;
		int size = G[u].size();

		for(int i=0;i<size;i++)
		{
			v = G[u][i].first;
			w = G[u][i].second;

			if(d[v] > d[u] + w)
			{	
				//cout << " INSIDE " << endl;
				d[v] = d[u] + w;
				Q.push(pp(v,d[v]));
			}
		}
	}

	/*for(i=0;i<n;i++)
	{
		cout << "Distance from source of vertex - " << i << " is " << d[i] << endl;
	}*/

	if(visited[n-1])
		cout << d[n-1] << endl;
	else
		cout << -1 << endl;
		

	}
	return 0;

}