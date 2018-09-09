#include<cstdio>
const int maxn=200010;
const int INF=0x7fffffff; 
int A[maxn],B[maxn],C[2*maxn];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&A[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	  scanf("%d",&B[i]);
	  A[n]=B[m]=INF;
	int i=0,j=0,index=0;
	A[n]=B[m]=INF;
	int mid=(n+m-1)/2;
	while(index<mid){
		if(A[i]<=B[j]){
			i++;
		}else j++;
		index++;
	}
	if(A[i]<B[j]){
		printf("%d",A[i]);
	}else{
		printf("%d",B[j]);
	}
	return 0; 
}
