#include<cstdio>
#include<vector>
using namespace std;
int n,m;
vector<int> v[110];
int numch[100]={0},maxdep=0;
void dfs(int root,int depth){
	if(v[root].size()==0){
		numch[depth]++;
		if(maxdep<depth) maxdep=depth;
		return;
	}
	for(int i=0;i<v[root].size();i++)
		  dfs(v[root][i],depth+1);
}
int main(){
	scanf("%d%d",&n,&m);
	int id,k,idch;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&idch);
			v[id].push_back(idch);
		}
	}
	dfs(1,0);
	printf("%d",numch[0]);
	for(int i=1;i<=maxdep;i++){
		printf(" %d",numch[i]);
	}
	return 0;
}
