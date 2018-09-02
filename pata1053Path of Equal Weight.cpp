#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int data;
	vector<int> child;
};
vector<node> v;
bool cmp(int a,int b){
	return v[a].data>v[b].data;
}
int n,m,s;
vector<int> path;
void dfs(int index,int sum){
	if(sum==s){
		if(v[index].child.size()==0){
			for(int i=0;i<path.size();i++){
				printf("%d",v[path[i]].data);
				if(i<path.size()-1) printf(" ");
				else printf("\n");
			}
			return;
		}else return;
	}
	for(int i=0;i<v[index].child.size();i++){
		int child=v[index].child[i];
		if(sum+v[child].data<=s){
			path.push_back(child);
			dfs(child,sum+v[child].data);
			path.pop_back();
		}
	}
}
int main(){
	int x,k,ch;
	scanf("%d%d%d",&n,&m,&s);
	v.resize(n);
	for(int i=0;i<n;i++)
	 scanf("%d",&v[i].data);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&k);
		for(int j=0;j<k;j++){
		 scanf("%d",&ch); 
	     v[x].child.push_back(ch);
		}
		sort(v[x].child.begin(),v[x].child.end(),cmp);
	}
	path.push_back(0);
	dfs(0,v[0].data);
	return 0;
} 
