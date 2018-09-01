#include<cstdio>
#include<vector>
using namespace std;
vector<int> v[500];
vector<bool> visit;
int n,m,cnt=0;
void DFS(int index){
	visit[index]=true;
	cnt++;
	for(int i=0;i<v[index].size();i++){
		if(visit[v[index][i]]==false)
		   DFS(v[index][i]); 
	}
}
int main(){
	int v1,v2,odd=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	for(int i=1;i<=n;i++){
		printf("%d",v[i].size());
		if(i<n) printf(" ");
		else printf("\n");
		if(v[i].size()%2==1) odd++;
	}
	visit.resize(n+1,false);
    DFS(1);
	if(cnt<n){
		printf("Non-Eulerian");
	}else{
		if(odd==0) printf("Eulerian");
		else if(odd==2) printf("Semi-Eulerian");
		else printf("Non-Eulerian");
	}
	return 0;
}
