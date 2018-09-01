#include<cstdio>
#include<map>
using namespace std;
const int maxn=10010;
int main(){
	int m,n,u,v;
	int pre[maxn];
	map<int,bool> mp;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
	  scanf("%d",&pre[i]);
      mp[pre[i]]=true;
    }
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		if(mp[u]==false&&mp[v]==false) printf("ERROR: %d and %d are not found.\n",u,v);
		else if(mp[u]==false) printf("ERROR: %d is not found.\n",u);
		else if(mp[v]==false) printf("ERROR: %d is not found.\n",v);
		else{
			int a;
			for(int j=0;j<n;j++){
				a=pre[j];
				if((a>=u&&a<=v)||(a>=v&&a<=u)) break;
			} 
			if(a==u||a==v)
			  printf("%d is an ancestor of %d.\n",a,a==u?v:u);
			else printf("LCA of %d and %d is %d.\n",u,v,a);
			}
	} 
	return 0;
}
