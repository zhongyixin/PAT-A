#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int> idtonum;
map<int,int> numtoid; 
int n,G[310][310];
int hash[10000]={0};
int main(){
	int m,k,id1,id2;
	scanf("%d%d",&n,&m);
	map<int,vector<int> > node;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id1,&id2);
		if(id1<0){
			id1=-id1;
			hash[id1]=1;
		}
		if(id2<0){
			id2=-id2;
			hash[id2]=1;
		}
		G[id1][id2]=G[id2][id1]=1;
		if(hash[id1]==hash[id2]){
			node[id1].push_back(id2);
			node[id2].push_back(id1);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&id1,&id2);
		
	}
}
