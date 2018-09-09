#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int choice[10010][110];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
    vector<int> w(n);
    vector<int> dp(m+1,0);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	sort(w.begin(),w.end(),cmp);
	for(int i=0;i<n;i++)
      for(int v=m;v>=w[i];v--){
      	if(dp[v-w[i]]+w[i]>=dp[v]){
      		dp[v]=dp[v-w[i]]+w[i];
      	    choice[i][v]=1;
		  }
	  }
	if(dp[m]!=m) printf("No Solution");
	else{
		int k=n-1,num=0,v=m;
		while(v>0){
			if(choice[k][v]==1){
				num++;
				if(num==1) printf("%d",w[k]);
				else printf(" %d",w[k]);
				v-=w[k];
			}
			k--;
		}
	}
    return 0;
}
