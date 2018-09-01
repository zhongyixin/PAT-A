#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=1000000000;
int n,m,st,ed;
int G[maxn][maxn],cost[maxn][maxn];
int d[maxn],c[maxn],pre[maxn];

bool vis[maxn]={false};
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	fill(c,c+maxn,INF);
	d[s]=0;
	c[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}else if(d[u]+G[u][v]==d[v]&&c[u]+cost[u][v]<c[v]){
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}
			}
		}   
	}
}
void dfs(int v){
	if(v==st){
		printf("%d ",v);
		return;
	}
		dfs(pre[v]);
		printf("%d ",v);

} 
int main(){
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	fill(G[0],G[0]+maxn*maxn,INF);
	int a,b,dis,cos;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&dis,&cos);
		G[a][b]=G[b][a]=dis;
		cost[a][b]=cost[b][a]=cos;
	}
	Dijkstra(st);
	dfs(ed);
	printf("%d %d",d[ed],c[ed]);
	return 0;
}
