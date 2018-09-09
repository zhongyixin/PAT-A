#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=510;
const int INF=9999999999;
int G[maxn][maxn],w[maxn];
bool vis[maxn]={false};
int Cmax,n,sp,m,d[maxn],minNeed=INF,minRemain=INF;
vector<int> pre[maxn];
vector<int> tempPath,path;
void Dijkstra(){
	fill(d,d+maxn,INF);
	d[0]=0;
	for(int i=0;i<=n;i++){
		int u=-1,min=INF;
		for(int j=0;j<=n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v){
	if(v==0){
		tempPath.push_back(v);
		int need=0,remain=0;
		for(int i=tempPath.size()-1;i>=0;i--){
			int id=tempPath[i];
			if(w[id]>0){
				remain+=w[id];
			}else{
				if(remain>abs(w[id])){
					remain+=w[id];
				}else{
					need+=abs(w[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minNeed){
			path=tempPath;
			minNeed=need;
			minRemain=remain;
		}else if(need==minNeed&&remain<minRemain){
			path=tempPath;
			minRemain=remain;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
int main(){
	int u,v;
	fill(G[0],G[0]+maxn*maxn,INF);
	scanf("%d%d%d%d",&Cmax,&n,&sp,&m);
	for(int i=1;i<=n;i++){
	  scanf("%d",&w[i]);
      w[i]-=Cmax/2;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra();
	DFS(sp);
	printf("%d ",minNeed);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i!=0) printf("->");
	}
	printf(" %d",minRemain);
	return 0;
} 
