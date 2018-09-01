#include<cstdio>

const int maxn=10010;
int father[maxn];
int isroot[maxn];
int find(int x){
	int a=x;
	while(x!=father[x])
      x=father[x];
    while(a!=father[a]){
    	int z=a;
    	a=father[a];
    	father[z]=x;
	}
	return x;
}
void Union(int a,int b){
	int faA=find(a);
	int faB=find(b);
	if(faA!=faB) father[faA]=faB;
}
bool exist[maxn];
int main(){
	int n,k,q,b,b0;
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&k,&b0);
		exist[b0]=true;
        int root=find(b0);
        Union(b0,root);
        for(int j=1;j<k;j++){
        	scanf("%d",&b);
        	exist[b]=true;
        	Union(b,root);
		}
	}
	for(int i=0;i<maxn;i++){
		if(exist[i])
		  isroot[find(i)]++;
	}
	int tree=0,num=0;
	for(int i=0;i<maxn;i++){
		if(isroot[i]>0) tree++,num+=isroot[i];
	}
	printf("%d %d\n",tree,num);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&b0,&b);
		if(find(b0)==find(b)) printf("Yes\n");
		else printf("No\n");
	} 
}
