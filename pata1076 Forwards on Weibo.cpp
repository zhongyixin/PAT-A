#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1010;
vector<int> G[maxn];
int layer[maxn],L;
bool inq[maxn];
int BFS(int id){
	int tot=0;
	fill(inq,inq+maxn,false);
	queue<int> q;
	inq[id]=true;
	layer[id]=0;
	q.push(id);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<G[now].size();i++){
			int next=G[now][i];
			if(inq[next]==false&&layer[now]+1<=L){
			    layer[next]=layer[now]+1;
				q.push(next);
				inq[next]=true;
				tot++;
			}
		}
	}
	return tot;
}
int main(){
	int n,mi,us;
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++){
		scanf("%d",&mi);
		for(int j=0;j<mi;j++){
			scanf("%d",&us);
			G[us].push_back(i);
		}
	}
	int k,id;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&id);
		printf("%d\n",BFS(id));
	}
	return 0;
} 
