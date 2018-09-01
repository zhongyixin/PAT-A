#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m[100010];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&m[i]); 
	sort(m+1,m+n+1,cmp);
	int e=1;
	while(e<=n&&e+1<m[e]) e++;
	printf("%d",e);
	return 0;
}
