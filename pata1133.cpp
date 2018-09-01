#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
	int data,next;
}list[100010];
vector<int> v[3];
int main(){
	int root,n,k,addr;
	scanf("%d%d%d",&root,&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&addr);
		scanf("%d%d",&list[addr].data,&list[addr].next);
	}
	int p=root;
	while(p!=-1){
		int data=list[p].data;
		if(data<0) v[0].push_back(p);
		else if(data>k) v[2].push_back(p);
		else v[1].push_back(p);
		p=list[p].next;
	}/*
	for(int i=1;i<3;i++){
		for(int j=0;j<v[i].size();j++){
			v[0].push_back(v[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		if(i!=n-1) printf("%05d %d %05d\n",v[0][i],list[v[0][i]].data,v[0][i+1]);
		else printf("%05d %d -1",v[0][i],list[v[0][i]].data);
	}*/
	int flag=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<v[i].size();j++){
			if(flag==0){
				printf("%05d %d ",v[i][j],list[v[i][j]].data);
				flag=1;
			}else{
				printf("%05d\n%05d %d ",v[i][j],v[i][j],list[v[i][j]].data);
			}
		}
	}
	printf("-1");
	return 0;
}
