#include<cstdio>
int hash[100000]={0};
int main(){
	int n,k,id,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		 for(int i=0;i<k;i++){
			scanf("%d",&id);
			if(k==1) break;
   			hash[id]=1;
		 } 
	}
	int flag=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&id);
		if(hash[id]==0){
			if(flag==1) printf(" ");
			printf("%d",id);
			flag=1;
			hash[id]=1;
		}
	}
	if(flag==0) printf("No one is handsome\n");
	return 0;
}
