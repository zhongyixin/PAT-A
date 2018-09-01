#include<cstdio>
#include<vector>
using namespace std;
int G[210][210]={0};
int n,m,x,y,k;
vector<int> q;
bool isConnected(){
	if(q[0]!=q[x-1]) return false;
	else{
		for(int i=0;i<n;i++){
			if(G[q[i]][q[i+1]]!=1)
			  return false;
		}
	}
	return true;
}
bool isOnce(){
	vector<int> cnt(x,0);
	for(int i=0;i<n;i++){
		cnt[q[i]]++;
		if(cnt[q[i]]>1) 
		   return false;
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		G[x][y]=1;
		G[y][x]=1;
	}
	scanf("%d",&k);
	int node;
	for(int i=0;i<k;i++){
		scanf("%d",&x);
		q.clear();
		//q.resize(x);
		for(int j=0;j<x;j++){
			scanf("%d",&node);
			q.push_back(node);
		}
		if(x==n+1 && isConnected() && isOnce() ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
