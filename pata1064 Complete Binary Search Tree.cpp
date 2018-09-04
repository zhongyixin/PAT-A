#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,cnt=0;
vector<int> in,bst;
void inorder(int root){
	if(root>n) return;
	inorder(2*root);
	cnt++;
	bst[root]=in[cnt];
	inorder(2*root+1);
}
int main(){
	scanf("%d",&n);
	in.resize(n+1);
	bst.resize(n+1);
	for(int i=1;i<=n;i++)
	  scanf("%d",&in[i]);
	sort(in.begin()+1,in.end());
	inorder(1);
	printf("%d",bst[1]);
	for(int i=2;i<=n;i++)
	  printf(" %d",bst[i]);
	return 0; 
} 

