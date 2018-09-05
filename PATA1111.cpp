#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=1000000000;
int n,st,ed;
int G[maxn][maxn],time[maxn][maxn];
bool vis[maxn]={false};
int d[maxn],t[maxn],num[maxn],pre[maxn];
vector<int> disP,timeP,tempP;
void DFSdis(int v){
	disP.push_back(v);
	if(v==st) return;
	DFSdis(pre[v]);
}
void DFStime(int v){
	timeP.push_back(v);
	if(v==st) return;
	DFStime(pre[v]);
}
void Dijkstra(){
	fill(d,d+maxn,INF);
	fill(t,t+maxn,INF);
	d[st]=0;
	t[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					t[v]=t[u]+time[u][v];
					pre[v]=u;
				}else if(d[u]+G[u][v]==d[v]&&t[u]+time[u][v]<t[v]){
					t[v]=t[u]+time[u][v];
					pre[v]=u;
				}
			}
		}
	}
	DFSdis(ed);
	fill(t,t+maxn,INF);
	fill(vis,vis+maxn,false);
	fill(num,num+maxn,INF);
	num[st]=1;
	t[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&t[j]<min){
				u=j;
				min=t[j];
			} 
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&time[u][v]!=INF){
				if(t[u]+time[u][v]<t[v]){
					t[v]=t[u]+time[u][v];
					num[v]=num[u]+1;
					pre[v]=u;
				}else if(t[u]+time[u][v]==t[v]&&num[u]+1<num[v]){
					num[v]=num[u]+1;
					pre[v]=u;
				}
			}
		}
	}
	DFStime(ed);
}
int main(){
	int m,one,u,v;
	scanf("%d%d",&n,&m);
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(time[0],time[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&one);
		scanf("%d%d",&G[u][v],&time[u][v]);
		if(one==0){
			G[v][u]=G[u][v];
			time[v][u]=time[u][v];
		}
	}
	scanf("%d%d",&st,&ed);
	Dijkstra();
	printf("Distance = %d",d[ed]);
	if(disP!=timeP){
		printf(": ");
	  for(int i=disP.size()-1;i>=0;i--){
	  	printf("%d",disP[i]);
	  	if(i>0) printf(" -> ");
	  }
	  printf("\n");
	}else printf("; ");
	printf("Time = %d: ",t[ed]);
	for(int i=timeP.size()-1;i>=0;i--){
		printf("%d",timeP[i]);
		if(i>0) printf(" -> ");
	}
	return 0;
}
