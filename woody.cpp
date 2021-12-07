#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using pii=tuple<long long,int,int>;

lli dis[1000][1000];
bool visited[1000][1000];
lli P[1000][4];

int main()
{
	int N,X,Y;
	lli ans=-1;
	scanf("%d%d%d",&N,&X,&Y);
	for(int i=1;i<=N;++i)
	{
		scanf("%lld%lld%lld",&P[i][1],&P[i][2] ,&P[i][3]);
	}
	
	for(int i=1;i<1000;++i)
	{
		for(int j=1;j<1000;++j)
		{
			dis[i][j]=2e18;
		}
	}
	priority_queue<pii,vector<pii>,greater<pii>> PQ;
	dis[0][0]=0;
	PQ.emplace(dis[0][0] , 0 ,0);
	while(!PQ.empty())
	{
		int x=get<1>(PQ.top());
		int y=get<2>(PQ.top());PQ.pop();
		
		if(visited[x][y]) continue;
		visited[x][y]=true;
		
		//cout << x << " " << y << " " << dis[x][y] << endl;
		
		if(x >= X and y>= Y)
		{
			cout << x << " " << y << endl;
			ans=dis[x][y];
			break;
		}
		
		for(int i=1;i<=N;++i)
		{
			int xx=x + (int) P[i][1];
			int yy=y + (int) P[i][2];
			
			lli w=P[i][3];
			//sif(x == 5 and y == 5) cout << xx << " " << yy << " " << w << endl;
			if(xx >= 1000 or yy >= 1000) continue;
			if(dis[xx][yy] > dis[x][y] + w)
			{
				dis[xx][yy] = dis[x][y] + w;
				PQ.emplace(dis[xx][yy] ,xx ,yy);
			}
		}
	}
	printf("%lld",ans);
}


