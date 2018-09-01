#include<cstdio>
#include<cstring>
#include<queue> 
#include<algorithm>
using namespace std;
struct node{
	int data;
	node* lchild;
	node* rchild; 
}; 
int in[31],post[31],n;
node* create(int inL,int inR,int postL,int postR){
	if(postL>postR){
		return NULL;
	}
	node* root=new node;
	root->data=post[postR];
	int k;
	for(int k=inL;k<=inR;k++){
		if(in[k]==post[postR])
		 break;
	}
	int numL=k-inL;
	root->lchild=create(inL,k-1,postL,postL+numL-1);
	root->rchild=create(k+1,inR,postL+numL,postR-1);
	return root;
}
int num=0;   //????????????
void BFS(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	} 
} 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	 scanf("%d",&in[i]);
	for(int i=0;i<n;i++)
	 scanf("%d",&post[i]); 
	node *root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}
