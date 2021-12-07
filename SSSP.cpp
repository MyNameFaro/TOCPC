#include<bits/stdc++.h>
using namespace std;

long long dis[100006];
bool visited[100006];
vector <pair<int,long long>> G[100006];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	int u,v;
	long long w;
	while(M--)
	{
		scanf("%d%d%lld",&u ,&v ,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=N;++i)
	{
		dis[i]=2e18;
	}
	priority_queue <pair<long long,int>,vector<pair<long long,int>> ,greater<pair<long long,int>>> PQ;
	dis[1]=0;
	PQ.emplace(dis[1],1);
	while(!PQ.empty())
	{
		u=PQ.top().second;PQ.pop();
		
		if(visited[u]) continue;
		visited[u]=true;
		
		for(auto vw:G[u])
		{
			v=vw.first;
			w=vw.second;
			if(!visited[v] and dis[v] > dis[u]+w)
			{
				dis[v]=dis[u]+w;
				PQ.emplace(dis[v],v);
			}
		}
	}
	for(int i=1;i<=N;++i)
	{
		printf("%lld ",dis[i]);
	}
}
