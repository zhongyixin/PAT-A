#include<iostream>
#include<string>
#include<queue>
using namespace std;

int stoi(string s){
	int len=s.length(),ans=0;
	for(int i=0;i<len;i++)
	   ans=10*ans+s[i]-'0';
	return ans; 
}
int n;
struct Node{
	bool root;
	int lchild;
	int rchild;
}node[20];
int main(){
	scanf("%d",&n);
	string l,r;
	for(int i=0;i<n;i++){
	    cin>>l>>r;
		if(l=="-") node[i].lchild=-1;
		else{
		  node[i].lchild=stoi(l);
		  node[stoi(l)].root=true;
	    }
		if(r=="-") node[i].rchild=-1;
		else{		
		  node[i].rchild=stoi(r);	
          node[stoi(r)].root=true;		
		}
	}
	int root;
	for(int i=0;i<n;i++){
		if(node[i].root==false){
			root=i;break;
		}
	}
	queue<int> q;
	q.push(root);
	int cnt=0,lastnode;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now!=-1){
			lastnode=now;
			cnt++;
		}else{
			if(cnt==n) printf("YES %d",lastnode);
			else printf("NO %d",root);
			return 0;
		}
		q.push(node[now].lchild);
		q.push(node[now].rchild);
	}
	return 0;
}
