#include<bits/stdc++.h>
using namespace std;

const int NN =1e6+2;
vector <int> R[NN] ,C[NN]; //contain column , row
//int canvas[1000][1000];

int bs(vector <int> &v,int x)
{
	int l=0,r=v.size()-1;
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(v[mid]<x)
		{
			l=mid+1;
			ans=max(ans,mid);
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	int N,M,W;
	int r,c;
	int mx_R_size=-2e9,mx_C_size=-2e9;
	int sr,sc,er,ec;
	scanf("%d%d%d",&N,&M,&W);
	for(int j=1;j<=M;++j)
	{
		C[j].push_back(0);
		C[j].push_back(N+1);
	}
	for(int i=1;i<=N;++i)
	{
		R[i].push_back(0);
		R[i].push_back(M+1);
	}
	for(int i=1;i<=W;++i)
	{	
		cin >> r >> c;
		//canvas[r][c]=1;
		R[r].push_back(c);
		mx_R_size = max((int) mx_R_size , (int) R[r].size());
		C[c].push_back(r);
		mx_C_size = max((int) mx_C_size , (int) C[c].size());
	}
	for(int j=1;j<=M;++j)
	{
		sort(C[j].begin(),C[j].end());
	}
	for(int i=1;i<=N;++i)
	{
		sort(R[i].begin(),R[i].end());
	}
	scanf("%d%d%d%d",&sr,&sc,&er,&ec);
	int sr_i = bs(R[sr] , sc);
	int sc_i = bs(C[sc] , sr);
	int er_i = bs(R[er] , ec);
	int ec_i = bs(C[ec] , er);
	int visited[mx_R_size][mx_C_size];
	for(int i=0;i<mx_R_size;++i)
	{
		for(int j=0;j<mx_C_size;++j)
		{
			visited[i][j]=0;
		}
	}
	visited[R[sr][sc]]
	
	
}
