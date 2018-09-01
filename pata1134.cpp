#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int n,m,k,v1,v2;
	scanf("%d%d",&n,&m);
	vector<int> v[n];
	for(int i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		v[v1].push_back(i);
		v[v2].push_back(i);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int nv,flag=0,ve;
		scanf("%d",&nv);
		vector<int> hash(m,0);
		for(int j=0;j<nv;j++){
			scanf("%d",&ve);
			for(int t=0;t<v[ve].size();t++)
			   hash[v[ve][t]]++;
		}
		for(int j=0;j<m;j++){
			if(hash[j]==0) {
			flag=1;
			printf("No\n");
			break;
		}
		}
		if(flag==0) printf("Yes\n");
	}
	return 0;
}
