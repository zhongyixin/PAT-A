#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int G[maxn][maxn]={0};
bool vis[maxn];
int n;
void dfs(int v){
	vis[v]=true;
	for(int i=1;i<=n;i++){
		if(vis[i]==false&&G[v][i]==1)
		  dfs(i);
	}
}
int main(){
	int u,v,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	for(int i=0;i<k;i++){
	    fill(vis,vis+maxn,false);
		scanf("%d",&u);
		int numB=0;
	    vis[u]=true;
	    for(int v=1;v<=n;v++){
		 if(vis[v]==false){
			 dfs(v);
			 numB++;
		 }
	    }
		printf("%d\n",numB-1);
	}
	return 0;
}
