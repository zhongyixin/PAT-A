#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
struct node{
	string val;
	int left,right;
};
vector<node> v;
int n;
int root=1;
string dfs(int index){
	if(index==-1) return "";
	if(v[index].right!=-1){
		v[index].val=dfs(v[index].left)+v[index].val+dfs(v[index].right);
		if(index!=root) v[index].val='('+v[index].val+')';
	}
	return v[index].val;
}
int main(){
	cin>>n;
	v.resize(n+1);
	vector<bool> isroot(n+1,true);
	for(int i=1;i<=n;i++){
		cin>>v[i].val>>v[i].left>>v[i].right;
		if(v[i].left!=-1) isroot[v[i].left]=false;
		if(v[i].right!=-1) isroot[v[i].right]=false;
	}
	while(isroot[root]==false) root++;
	cout<<dfs(root)<<endl;
	return 0;
} 
