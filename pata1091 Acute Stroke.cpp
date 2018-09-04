#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int z,x,y;
};
int m,n,l,t;
int pixel[65][1300][130];
bool vis[65][1300][130]={false};
int Z[6]={0,0,0,0,1,-1};
int X[6]={0,0,1,-1,0,0};
int Y[6]={1,-1,0,0,0,0};
bool judge(int z,int x,int y){
	if(z>=l||z<0||x>=n||x<0||y>=m||y<0) return false;
	if(pixel[z][x][y]==0||vis[z][x][y]==true) return false;
	return true;
}
int BFS(int z,int x,int y){
    int tot=0;
	vis[z][x][y]=true;
	queue<node> q;
	q.push(node{z,x,y});
	while(!q.empty()){
		node now=q.front();
		q.pop();
		tot++;
		for(int i=0;i<6;i++){
			int z1=now.z+Z[i];
			int x1=now.x+X[i];
			int y1=now.y+Y[i];
			if(judge(z1,x1,y1)){
			   q.push(node{z1,x1,y1});
		       vis[z1][x1][y1]=true;
			}
		}
	}
	if(tot>=t) return tot;
	else return 0;
}
int BFSTrave(){
	int total=0;
	for(int z=0;z<l;z++)
	  for(int x=0;x<m;x++)
	    for(int y=0;y<n;y++)
		  if(pixel[z][x][y]==1&&vis[z][x][y]==false){
	    	total+=BFS(z,x,y);
		}
	return total;
}
int main(){
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int z=0;z<l;z++)
	  for(int x=0;x<m;x++)
	    for(int y=0;y<n;y++)
	     scanf("%d",&pixel[z][x][y]);
	printf("%d",BFSTrave());
	return 0;
} 
