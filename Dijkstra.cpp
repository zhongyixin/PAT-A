#include<cstdio>
#include<algorithm>
using namespace std;
const int maxv=1000;
const int INF=1000000000;

int n,m,s,G[maxv][maxv];
int d[maxv];
bool vis[maxv]={false};

void Dijkstra(int s){
	fill(d,d+maxv,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
			}
		} 
	}
} 
int main(){
	scanf("%d%d%d",&n,&m,&s);
	fill(G[0],G[0]+maxv*maxv,INF);
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
	}
	Dijkstra(s);
	printf("%d",d[0]);
	for(int i=1;i<n;i++){
		printf(" %d",d[i]);
	}
	return 0;
}
