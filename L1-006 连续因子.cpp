#include<cstdio>
#include<cmath>
int main(){
	int num;
	scanf("%d",&num);
	int first,len=0,maxn=sqrt(num);
	for(int i=2;i<=maxn;i++){
		int j,temp=1;
		for(j=i;j<=maxn;j++){
			temp*=j;
			if(num%temp!=0) break;
		}
		if(j-i>len){
			len=j-i;
			first=i;
		}
	}
	if(first==0) printf("1\n%d",num);
	else{
	printf("%d\n",len);
	printf("%d",first);
	for(int i=1;i<len;i++){
		printf("*%d",first+i);
	}
	}
	return 0;
}
