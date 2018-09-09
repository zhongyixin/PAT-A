#include<cstdio>
struct Node{
	char data;
	int next;
}node[100010];
int hash[100010]={0};
int main(){
	int st1,st2,n,addr;
	scanf("%d%d%d",&st1,&st2,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&addr);
		scanf(" %c %d",&node[addr].data,&node[addr].next);
	}
	int p=st1;
	while(p!=-1){
		hash[p]=1;
		p=node[p].next;
	}
	p=st2;
	while(p!=-1&&hash[p]!=1){
		p=node[p].next;
	}
	if(p!=-1)
	  printf("%05d",p);
	else printf("-1");
} 
