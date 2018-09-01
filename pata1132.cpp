#include<cstdio>
#include<cstring>
#include<cmath>
int main(){
	int n,len;
	char s[12];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		len=strlen(s);
		int a=0,b=0;
		for(int j=0;j<len/2;j++){
			a=a*10+s[j]-'0';
		}
		for(int j=len/2;j<len;j++){
			b=b*10+s[j]-'0';
		}
		if(a*b!=0&&(a*(int)(pow(10,len/2))+b)%(a*b)==0){
			printf("Yes\n");
		}else printf("No\n");
	}
	return 0;
}
