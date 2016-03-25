#include <bits/stdc++.h>

#define MN (int)1e5

using namespace std;9

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
	cin >> N >> R;
	dist.resize(N+1);

	for(i=1;i<=N-1;i++)
	{
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	farthestleaf(R,-1,0);

	long long maxleaf = 0;

	vector<long long>::iterator it2 = max_element(dist.begin(),dist.end());
	
	maxleaf = distance(dist.begin(),it2);

	long long mh=0;

	for(i=1;i<=N;i++)
	{
		if(mh==0 && Graph[i].size()==1)
			mh = dist[i];

		else if(Graph[i].size()==1 && dist[i] < mh)
			mh = dist[i];
	}	

	cout << dist[maxleaf] + 1 << " " << mh+1 << endl;
			
	return 0;
	
}