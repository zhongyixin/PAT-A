#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int main(){
	int k,n,a[maxn];
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&n);
		bool result=true;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
			for(int t=1;t<j;t++){
				if(a[j]==a[t]||abs(j-t)==abs(a[j]-a[t])){
					result=false;
					break;
				}
			}
		}
		if(result==false) {
			printf("NO\n");
		}else printf("YES\n");
	}
	return 0;
}
