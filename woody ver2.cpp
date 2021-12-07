#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using pii=tuple<long long,int,int>;

lli dis[1000][1000];
bool visited[20];
lli P[1000][4];

lli ans=2e18;
vector <int> slug;

void solve(int n,int N,int X ,int Y)
{
	if(n == N + 1) return;
	
	int x=0,y=0;
	lli cc=0;
	
	if(n > 0)
	{
		for(auto a:slug)
		{
			cc += P[a][3];
			x += (int) P[a][1];
			y += (int) P[a][2];
			if(x >= X and y >= Y)
			{
				cout << cc << endl;
				ans=min(ans ,cc);
				return;
			}
		}
	}
	
	for(int i=1;i<=N;++i)
	{
		if(visited[i]) continue;
		visited[i]=true;
		slug.push_back(i);
		solve(n + 1,N,X,Y);
		visited[i]=false;
		slug.pop_back();
	}
}
int main()
{
	int N,X,Y;
	scanf("%d%d%d",&N,&X,&Y);
	for(int i=1;i<=N;++i)
	{
		scanf("%lld%lld%lld",&P[i][1],&P[i][2] ,&P[i][3]);
	}
	solve(0 , N,X,Y);
	if(ans==2e18)
	{
		printf("-1");
		return 0;
	}
	else
	{
		printf("%lld",ans);
	}
}


