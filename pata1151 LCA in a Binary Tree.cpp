#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=1010;
int n,m;
int in[maxn],pre[maxn];
map<int,bool> mp;
int main(){
	int u,v;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
		mp[in[i]]=true;
	} 
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		if(mp[u]==false&&mp[v]==false) printf("ERROR: %d and %d are not found.\n",u,v);
		else if(mp[u]==false) printf("ERROR: %d is not found.\n",u);
		else if(mp[v]==false) printf("ERROR: %d is not found.\n",v);
		else{
		int st,ed,jj;
		for(jj=0;jj<n;jj++){
			if(in[jj]==u||in[jj]==v) {st=jj;break;}
		}
		for(jj=jj+1;jj<n;jj++){
			if(in[jj]==u||in[jj]==v) {ed=jj;break;}
		}
		int ss,st2;
		for(ss=0;ss<n;ss++){
			if(in[ss]==u||in[ss]==v) {st2=ss;}
		}
		int lca=-1;
		for(int t=0;t<=st2;t++){
		   for(int j=st;j<=ed;j++){
		   	if(pre[t]==in[j]){
		   		lca=pre[t];
		   		break;
			   }
		   }
		   if(lca!=-1) break;
	    }
		if(lca==u||lca==v) printf("%d is an ancestor of %d.\n",lca,lca==u?v:u);
		else printf("LCA of %d and %d is %d.\n",u,v,lca);
	}
	}
	return 0;
}
