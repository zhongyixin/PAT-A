#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=10010;
//int X[4]={0,1,0,-1};
//int Y[4]={1,0,-1,0};
int num[maxn],ans[maxn][maxn]={0};
int N;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	if(N==1){
		printf("%d",num[0]);
		return 0;
	}
	sort(num,num+N,cmp);
    int m=(int)ceil(sqrt(1.0*N));
    while(N%m!=0){
    	m++;
	}
	int n=N/m;
	int x=0,y=0,index=0;
	int U=0,D=m,L=0,R=n;
	while(index<N){
		//ans[x][y]=num[index++];
		/*
		for(int i=0;i<4;i++){
			int xi=x+X[i];
			int yi=y+Y[i];
			if(xi>=0&&xi<m&&yi>=0&&yi<n&&ans[xi][yi]==0){
				x=xi;
				y=yi;
				break;
			}
		}*/
		while(index<N&&y+1<R){
			ans[x][y]=num[index++];
			y++;
		}
		while(index<N&&x+1<D){
			ans[x][y]=num[index++];
			x++;
		}
		while(index<N&&y-1>=L){
			ans[x][y]=num[index++];
			y--;
		}
		while(index<N&&x-1>=U){
			ans[x][y]=num[index++];
			x--;
		}
		U++,D--,L++,R--;
		x++,y++;
		if(index==N-1){
			ans[x][y]=num[index++];
		} 
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",ans[i][j]);
			if (j!=n-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;	
}
