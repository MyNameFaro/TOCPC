#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int DP[1000006];
int main()
{
	int N,s0;
	int s,t;
	int ans=0;
	pii P[1000006];
	scanf("%d%d",&N,&s0);
	P[0].first=0;
	P[0].second=s0;
	deque <int> deq;
	for(int i=1;i<=N;++i)
	{
		scanf("%d%d",&P[i].second,&P[i].first);
	}
	sort(P , P+N+1);
	deq.push_back(0);
	for(int i=1;i<=N;++i)
	{
		//for(int j=0;j<i;++j)
		//{
			while(!deq.empty() and abs(P[i].first - P[deq.front()].first) < abs(P[i].second - P[deq.front()].second))
			{
				deq.pop_front();
			}
			if(deq.size() > 0) DP[i] = max(DP[i] , 1 + DP[deq.front()]);
			ans=max(ans , DP[i]);
			while(!deq.empty() and DP[i] > DP[deq.back()])
			{
				deq.pop_back();
			}
			deq.push_back(i);
		//}
	}
	printf("%d",ans);
}
