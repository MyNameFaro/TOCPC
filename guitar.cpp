#include <bits/stdc++.h>
using namespace std;
using lli=long long;
using tll=tuple<long long,int,int>;

lli dis[305][305] ,P[305][305];
bool visited[305][305];
int S[305];
int main()
{
	int N,M,K;
	lli ans=2e18;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			scanf("%lld",&P[i][j]);
		}
	}
	for(int i=1;i<=M;++i)
	{
		scanf("%d",&S[i]);
	}
	for(int i=0;i<305;++i)
	{
		for(int j=0;j<305;++j)
		{
			dis[i][j]=2e18;
		}
	}
	priority_queue <tll,vector <tll>,greater<tll>> PQ;
	for(int i=1;i<=1 + K;++i)
	{
		dis[i][K-i+1]=0;
		PQ.emplace(dis[i][K-i+1] , i , K-i+1);
	}
	while(!PQ.empty())
	{
		int i=get<1>(PQ.top());
		int k=get<2>(PQ.top());PQ.pop();
		
		if(visited[i][k]) continue;
		visited[i][k]=true;
		
		//cout << dis[i][k] << endl;
		
		if(i+k > M)
		{
			ans=dis[i][k];
			break;
		}
		for(int j=i+1;j<=i+1+k;++j)
		{
			if(dis[j][k-(j-i-1)] > dis[i][k] + P[S[i]][S[j]])
			{
				//cout << j << " " << k-(j-i-1) << endl;
				dis[j][k-(j-i-1)] = dis[i][k] + P[S[i]][S[j]];
				PQ.emplace(dis[j][k-(j-i-1)] , j , k-(j-i-1));
			}
		}
	}
	printf("%lld",ans);
}
