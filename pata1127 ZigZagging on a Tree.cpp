#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int data,layer;
	node* lchild;
	node* rchild;
}; 
int in[35],post[35];
node* create(int inL,int inR,int postL,int postR){
	if(postL>postR) return NULL;
	node* root=new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR])
		 break;
	}
	int numL=k-inL;
	root->lchild=create(inL,k-1,postL,postL+numL-1);
	root->rchild=create(k+1,inR,postL+numL,postR-1);
	return root;
}
vector<int> ans[35];
void bfs(node* root){
	queue<node*> q;
	root->layer=0;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		ans[now->layer].push_back(now->data);
		if(now->lchild!=NULL){
			now->lchild->layer=now->layer+1;
			q.push(now->lchild);
		}
		if(now->rchild!=NULL){
			now->rchild->layer=now->layer+1;
			q.push(now->rchild);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<n;i++)
	   scanf("%d",&post[i]);
	node* root=create(0,n-1,0,n-1);
	bfs(root);
	printf("%d",ans[0][0]);
	for(int i=1;i<35;i++){
		if(i%2==1){
			for(int j=0;j<ans[i].size();j++)
			  printf(" %d",ans[i][j]);
		}else{
			for(int j=ans[i].size()-1;j>=0;j--)
			 printf(" %d",ans[i][j]);
		}
	}
	return 0;
}
