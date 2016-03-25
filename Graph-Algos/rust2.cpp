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

struct edge{
	int length;
	int u;
	int v;
};

int main()
{
	int T;
	cin >> T;

	while(T>0)
	{ 
		T--;
	
	priority_queue < pp , vector<pp> , Prioritize > Q;
	priority_queue < pp , vector<pp> , Prioritize > Q2;
	
	vector <pp> G[MAX];
	vector<int> ds(MAX,MAX);
	vector<int> dd(MAX,MAX);	
	vector< pair< pair<int,int>,int > > Taxidata(MAX);
	//vector<edge> Taxidata(MAX);
	bool visiteds[MAX],visitedd[MAX];

	int n,e,u,v,w,taxi;

	cin >> n;
	//G.resize(n+1);
	cin >> e;

	//cout << "Vertices , Edges - " << n << " " << e << endl;

	int i;

	for(i=1;i<=e;i++)
	{
		cin >> u >> v >> w >> taxi;
		//cout << "Vertex1 , Vertex 2 , Weight - " << u << " " << v << " " << w << endl;
		G[u].push_back(pp(v,w));
		G[v].push_back(pp(u,w));
		//edge e;
		//e.length = taxi;
		//e.u = u;
		//e.v = v;		
		//Taxidata.push_back(e);
		Taxidata.push_back(make_pair(make_pair(u,v),taxi));
	}

	int source,destination;
	cin >> source >> destination;
	ds.resize(n+1);
	dd.resize(n+1);

	for(i=1;i<n;i++)
	{
		ds[i] = dd[i] = MAX;
		visiteds[i] = visitedd[i] = false;
	}

	ds[source] = 0;
	visiteds[source] = true;

	Q.push(pp(source,ds[source]));

	while(!Q.empty())
	{
		u = Q.top().first;
		Q.pop();

		visiteds[u] = true;
		int size = G[u].size();

		for(int i=0;i<size;i++)
		{
			v = G[u][i].first;
			w = G[u][i].second;

			if(ds[v] > ds[u] + w)
			{	
				//cout << " INSIDE " << endl;
				ds[v] = ds[u] + w;
				Q.push(pp(v,ds[v]));
			}
		}
	}


	// second Dijkstra

	dd[destination] = 0;
	visitedd[destination] = true;
	Q2.push(pp(destination,dd[destination]));

	while(!Q2.empty())
	{
		u = Q2.top().first;
		Q2.pop();

		visitedd[u] = true;
		int size = G[u].size();

		for(int i=0;i<size;i++)
		{
			v = G[u][i].first;
			w = G[u][i].second;

			if(dd[v] > dd[u] + w)
			{	
				//cout << " INSIDE " << endl;
				dd[v] = dd[u] + w;
				Q2.push(pp(v,dd[v]));
			}
		}
	}

	int normaldist = ds[destination];
	int length,minlength,a,b;

	minlength = normaldist;

	/*tr(Taxidata,it)
	{
		length = it->second;
		pair<int,int> tpair = it->first;
		a = tpair.first;
		b = tpair.second;
		//a = it->first;
		//cout << a;
		//b = it.first.second;
		//length = it->length;
		//a = *it.u;
		//b = *it.v;
		int min0 = min(ds[a]+dd[b],dd[a]+ds[b]);

		minlength = min(min0+length, minlength);
	}*/

	for( auto &i : Taxidata)
	{	
		length = i.second;
		pair<int,int> tpair = i.first;
		a = tpair.first;
		b = tpair.second;
		//a = it->first;
		//cout << a;
		//b = it.first.second;
		//length = it->length;
		//a = *it.u;
		//b = *it.v;
		int min0 = min(ds[a]+dd[b],dd[a]+ds[b]);

		minlength = min(min0+length, minlength);
 	}


	/*for(i=1;i<2*n+1;i++)
	{
		cout << "Distance from source of vertex - " << i << " is " << d[i] << endl;
	}*/

	if(visiteds[destination])
		cout << minlength << endl;
	else
		cout << -1 << endl;
		

	}
	return 0;
}