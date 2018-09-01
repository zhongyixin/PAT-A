#include<cstdio>
#include<cmath>
bool isPrime(int n){
	if(n<=1) return false;
	int x=(int)sqrt(1.0*n);
	for(int i=2;i<=x;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n,d;
	while(scanf("%d",&n)!=EOF){
		if(n<0) break;
		scanf("%d",&d);
		if(isPrime(n)==false){
		   printf("No\n");
		   continue;
		}
		int len=0,arr[100];
		while(n!=0){
			arr[len++]=n%d;
			n/=d;
		}
		int ren=0;
		for(int i=0;i<len;i++){
			ren=ren*d+arr[i];
		}
		if(isPrime(ren)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
