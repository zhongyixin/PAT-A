#include<cstdio>
#include<vector>
using namespace std;
const int maxn=50010;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
int n;
int pre[maxn],in[maxn];
node* create(int preL,int preR,int inL,int inR){
	if(preL>preR) return NULL;
	node* root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]) break;
	}
	int numL=k-inL;
	root->lchild=create(preL+1,preL+numL,inL,k-1);
	root->rchild=create(preL+numL+1,preR,k+1,inR);
	return root;
}
vector<int> post;
void postorder(node *root){
	if(root==NULL){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	   scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
	   scanf("%d",&in[i]);
    node* root=create(0,n-1,0,n-1);
    postorder(root);
	printf("%d",post[0]);
}
