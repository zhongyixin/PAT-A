#include<cstdio>
struct node{
	int data;
	node* lchild;
	node* rchild;
};
bool unique=true;
int pre[35],post[35],n;
node* create(int preL,int preR,int postL,int postR){
	if(postL>postR) return NULL;
	if(pre[preL]==post[postR]){
		node* root=new node;
		root->data=pre[preL];
		int k;
		for(k=preL+1;k<=preR;k++){
			if(pre[k]==post[postR-1])
			 break;
		}
		int numL=k-preL-1;
		if(numL>0){
			root->lchild=create(preL+1,k-1,postL,postL+numL-1);
		}else {
		  unique=false;
		  root->lchild=NULL;
	    }
	    root->rchild=create(k,preR,postL+numL,postR-1);
	    return root;
	}
}
int cnt=0;
void inorder(node* root){
	if(root==NULL) return;
	inorder(root->lchild);
	cnt++;
	if(cnt<n)
     printf("%d ",root->data);
    else printf("%d",root->data);
	inorder(root->rchild);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
	  scanf("%d",&post[i]);
	node* root=create(0,n-1,0,n-1);
	if(unique==true) printf("Yes\n");
	else printf("No\n");
	inorder(root);
	return 0;
}
