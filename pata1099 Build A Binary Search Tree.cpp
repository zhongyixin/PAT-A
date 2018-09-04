#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int data;
	int lchild,rchild;
};
int n,data[110],cnt=0;
vector<node> bst;
void inorder(int root){
	if(root==-1) return;
	inorder(bst[root].lchild);
	bst[root].data=data[cnt++];
	inorder(bst[root].rchild);
}
void bfs(int root){
	cnt=0;
	queue<node> q;
	q.push(bst[root]);
	while(!q.empty()){
		node now=q.front();
		q.pop();
		cnt++;
		printf("%d",now.data);
		if(cnt<n) printf(" ");
		if(now.lchild!=-1) q.push(bst[now.lchild]);
		if(now.rchild!=-1) q.push(bst[now.rchild]); 
	}
}
int main(){
	scanf("%d",&n);
	bst.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&bst[i].lchild,&bst[i].rchild);
	for(int i=0;i<n;i++)
	  scanf("%d",&data[i]);
	sort(data,data+n);
	inorder(0);
	bfs(0);
	return 0;
}
