#include<cstdio>
#include<cstring>
#include<cmath>

char str[10];
int  num=0;
double ans=0.0;

void judge(char str[]){
	int len=strlen(str);
	double data=0.0;
	int posP=len-1;
	bool flag=false;
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			data=data*10+str[i]-'0';
		}else if(str[i]=='.'&&i>=len-3){
		    posP=i;
		}else if(str[i]=='-'&&i==0){
			flag=true;
		}else{
			printf("ERROR: %s is not a legal number\n",str);
			return;
		}
	}
	if(flag) data=-data;
	data/=pow(10,len-1-posP);
	if(data>1000 || data<-1000){
		printf("ERROR: %s is not a legal number\n",str);
	    return;
	}else{
	num++;
	ans+=data;} 
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str);
		judge(str);
	}
	if(num==0){
		printf("The average of 0 numbers is Undefined");
	}else if(num==1){
		printf("The average of 1 number is %.2f",ans);
	}else{
		printf("The average of %d numbers is %.2f",num,ans/num);
	}
	return 0;
} 
