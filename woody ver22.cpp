#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using tll=tuple<long long,int ,int ,int>;
using tii=tuple<long long,int ,int>;

bool visited[20];
lli P[1000][4];

lli ans=2e18;
vector <int> slug;

void solve(int n,int x,int y, lli c,int N,int X ,int Y)
{
	if(n == N + 2) return;
	
	if(x >= X and y >= Y)
	{
		ans=min(ans,c);
	}
	solve(n + 1,x + (int) P[n][1] , y + (int) P[n][2] , c + P[n][3], N,X,Y);
	solve(n + 1,x, y, c, N,X,Y);
}
int main()
{
	int N,X,Y;
	scanf("%d%d%d",&N,&X,&Y);
	int sx=0,sy=0;
	for(int i=1;i<=N;++i)
	{
		scanf("%lld%lld%lld",&P[i][1],&P[i][2] ,&P[i][3]);
		sx += P[i][1];
		sy += P[i][2];
	}
	solve(1 , 0 , 0 ,0,N,X,Y);
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


