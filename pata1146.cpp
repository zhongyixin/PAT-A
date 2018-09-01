#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1010;
vector<int> node[maxn];
int in[maxn]={0};
int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		node[a].push_back(b);
		in[b]++;
	}
	int k,num=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		bool flag=true;
		vector<int> tin(in,in+n+1);
		for(int j=0;j<n;j++){
			scanf("%d",&a);
			if(tin[a]!=0) flag=false;
			for(vector<int>::iterator it=node[a].begin();it!=node[a].end();it++)
			    tin[*it]--;
		}
		if(flag==false){
			num++;
			if(num==1) printf("%d",i);
			else printf(" %d",i);
		}
	} 
	return 0;
}
