#include<iostream>
#include<vector>
using namespace std;

int e[210][210];
int main(){
	int nv,ne,v1,v2,m,k;
	scanf("%d%d",&nv,&ne);
	for(int i=0;i<ne;i++){
		scanf("%d%d",&v1,&v2);
		e[v1][v2]=e[v2][v1]=1;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&k);
		vector<int> v(k);
		int hash[210]={0},isClique=1,isMaximal=1;
		for(int j=0;j<k;j++){
			scanf("%d",&v[j]);
			hash[v[j]]=1;
		}
		for(int j=0;j<k;j++){
			if(isClique==0) break;
			for(int t=j+1;t<k;t++){
				if(e[v[j]][v[t]]==0) {isClique=0;break;}
			}
		}
		if(isClique==0) {
			printf("Not a Clique\n");continue;
		}
		for(int j=1;j<=nv;j++){
			if(hash[j]==0){
				int t;
				for(t=0;t<k;t++){
					if(e[j][v[t]]==0) break;
				}
				if(t==k) {isMaximal=0;printf("Not Maximal\n");break;}
			}
			if(isMaximal==0) break;
		}
		if(isMaximal) printf("Yes\n");
	}
	return 0;
}
