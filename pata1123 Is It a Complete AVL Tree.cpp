#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int v,height;
	node *lchild,*rchild;
};

node* newNode(int v){
	node* Node=new node;
	Node->v=v;
	Node->height=1; 
	Node->lchild=Node->rchild=NULL;
	return Node;  
}

int getHeight(node* root){
	if(root==NULL) return 0;
	return root->height;
}
void updataHeight(node* root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
int getBalanceFactor(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updataHeight(root);
	updataHeight(temp);
	root=temp;
}
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updataHeight(root);
	updataHeight(temp);
	root=temp;
}
void insert(node* &root,int v){
	if(root==NULL){
		root=newNode(v);
		return;
	}
	if(v<root->v){
		insert(root->lchild,v);
		updataHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,v);
		updataHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				L(root);
			}else if(getBalanceFactor(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
}	
int n;
int cnt=0,after=0,flag=1;
void bfs(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		cnt++;
		printf("%d",now->v);
		if(cnt<n) printf(" ");
		if(now->lchild!=NULL){
			if(after) flag=0;
			q.push(now->lchild);
		}else after=1;
		if(now->rchild!=NULL){
			if(after) flag=0;
			q.push(now->rchild);
		}else after=1;
	}
}
int main(){
	int data;
	scanf("%d",&n);
	node* root=NULL;
	for(int i=0;i<n;i++){
	    scanf("%d",&data);
	    insert(root,data);
	}
	bfs(root);
	if(flag) printf("\nYES");
	else printf("\nNO");
	return 0;
}
