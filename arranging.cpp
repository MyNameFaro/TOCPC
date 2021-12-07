#include <bits/stdc++.h>
using namespace std;

int P[22];
bool visited[22];
int ans=2e9;

void solve(int N,int aim)
{
	set <int> S;
	int pre = -1;
	int type=1;
	int size = 0;
	for(int i=1;i<=N;++i)
	{
		if(visited[P[i]] or i==aim) continue;
		S.insert(P[i]);
		if(pre != -1 and P[pre] != P[i])
		{
			++type;
		}
		pre = i;
		++size;
	}
	if(type == (int) S.size())
	{
		ans = min(ans , N - size);
	}
}

void solve2(int n,int N)
{
	if(n == N + 1) return;
	visited[n]=true;
	for(int i=1;i<=N;++i)
	{
		solve(N , i);
	}
	solve2(n + 1,N);
	visited[n]=false;
	for(int i=1;i<=N;++i)
	{
		solve(N , i);
	}
	solve2(n + 1,N);
}
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&P[i]);
	}
	solve2(1 , N);
	printf("%d",ans);
}
