#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;
int main(){
	int n,a[maxn];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(n%2==0) printf("0 ");
	else printf("1 ");
	int m=n/2;
	int s1=0,s2=0;
	for(int i=0;i<m;i++){
		s1+=a[i];
	} 
	for(int i=m;i<n;i++){
		s2+=a[i];
	} 
	printf("%d",s2-s1);
	return 0;
} 
