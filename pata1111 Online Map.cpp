#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=510;
const int INF=999999999;
int n,m,st,ed,minnode=INF,G[maxn][maxn],time[maxn][maxn];
int d[maxn],t[maxn],pred[maxn],pret[maxn];
vector<int> tempret[maxn],dispath,timepath,temppath;
bool vis[maxn]={false};
void dfsDistance(int v){
	dispath.push_back(v);
	if(v==st) return;
	dfsDistance(pred[v]);
}
void dfsTime(int v){
	temppath.push_back(v);
	if(v==st){
		if(temppath.size()<minnode){
			minnode=temppath.size();
			timepath=temppath;
		}
		//temppath.pop_back();
		return;
	}
	for(int i=0;i<tempret[v].size();i++)
	  dfsTime(tempret[v][i]);
	//temppath.pop_back();
}
void Dijkstra(){
	fill(d,d+maxn,INF);
	fill(t,t+maxn,INF);
	for(int i=0;i<n;i++)
	  pred[i]=i;
	d[st]=0;
	t[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					t[v]=t[u]+time[u][v];
					pred[v]=u;
				}else if(d[u]+G[u][v]==d[v]&&t[u]+time[u][v]<t[v]){
					t[v]=t[u]+time[u][v];
					pred[v]=u;
				}
			}
		}
	}
	dfsDistance(ed);
	fill(t,t+maxn,INF);
	fill(vis,vis+maxn,false);
	for(int i=0;i<n;i++)
	  pret[i]=i;
	t[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&t[j]<MIN){
				MIN=t[j];
				u=j;
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&time[u][v]!=INF){
				if(t[u]+time[u][v]<t[v]){
					t[v]=t[u]+time[u][v];
					pret[v]=u;
					tempret[v].clear();
					tempret[v].push_back(u);
				}if(t[u]+time[u][v]<t[v]){
					tempret[v].push_back(u);
				}
			}
		}
	}
	dfsTime(ed); 
} 
int main(){
	int u,v,o,dis,ti;
	fill(G[0],G[0]+maxn*maxn,INF);
	fill(time[0],time[0]+maxn*maxn,INF);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&u,&v,&o,&dis,&ti);
		G[u][v]=dis;
		time[u][v]=ti;
		if(o==0){
			G[v][u]=dis;time[v][u]=ti;
		} 
	}
	scanf("%d%d",&st,&ed);
	Dijkstra();
	printf("Distance = %d",d[ed]);
	if(dispath!=timepath){
		printf(": ");
	  for(int i=dispath.size()-1;i>=0;i--){
	  	printf("%d",dispath[i]);
	  	if(i>0) printf(" -> ");
	  }
	  printf("\n");
	}else printf("; ");
	printf("Time = %d: ",t[ed]);
	for(int i=timepath.size()-1;i>=0;i--){
		printf("%d",timepath[i]);
		if(i>0) printf(" -> ");
	}
	return 0;
} 
