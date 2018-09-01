#include<iostream>
struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};
int n;
int data[1010];
void insert(node* &root,int x){
	if(root==NULL){
		root=new node();
		root->data=x;
	    root->lchild=root->rchild=NULL;
		return;
	}
	if(x<=root->data){
		insert(root->lchild,x);
	}else insert(root->rchild,x);
}
node* Create(){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
}
int maxdepth=-1;
int num[1010]={0};
void dfs(node* v,int depth){
	if(v==NULL){
		if(depth>maxdepth) maxdepth=depth;
		return;
		}
	num[depth]++;
	dfs(v->lchild,depth+1);
	dfs(v->rchild,depth+1);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	node *bst=Create();	
	dfs(bst,0);
    printf("%d + %d = %d", num[maxdepth-1], num[maxdepth-2], num[maxdepth-1] + num[maxdepth-2]);
	return 0;
}
