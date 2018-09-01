#include<iostream>
#include<map>
using namespace std;
const int maxn=2010;
map<string,int> stringToInt;
map<int,string> intToString;
map<string,int> ans;
int G[maxn][maxn],weight[maxn];
bool vis[maxn]={false};
int n,k,pos=0;
int stoint(string str){
	if(stringToInt.find(str)!=stringToInt.end()){
		return stringToInt[str];
	}else{
		stringToInt[str]=pos;
		intToString[pos]=str;
		return pos++;
	}
}
void dfs(int u,int &head,int &num,int &totalweight){
	vis[u]=true;
	num++;
	if(weight[u]>weight[head])
	   head=u;
	for(int v=0;v<pos;v++){
		if(G[u][v]!=0){
			totalweight+=G[u][v];
			G[u][v]=G[v][u]=0;
			if(vis[v]==false)
    			dfs(v,head,num,totalweight);
		}
	}
}
void dfsTrave(){
	for(int i=0;i<pos;i++){
		if(vis[i]==false){
			int head=i,num=0,totalweight=0;
			dfs(i,head,num,totalweight);
			if(num>2&&totalweight>k)
			  ans[intToString[head]]=num;
		}
	}
}
int main(){
	string str1,str2;
	int wei;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>str1>>str2>>wei;
		int id1=stoint(str1);
		int id2=stoint(str2);
		weight[id1]+=wei;
		weight[id2]+=wei;
		G[id1][id2]+=wei;
		G[id2][id1]+=wei;
	}
	dfsTrave();
	cout<<ans.size()<<endl;
	for(map<string,int>::iterator it=ans.begin();it!=ans.end();it++){
		cout<<it->first<<" "<<it->second<<endl; 
	}
	return 0;
}
