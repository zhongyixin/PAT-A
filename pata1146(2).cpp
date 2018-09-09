#include<iostream>
#include<vector>
using namespace std;
const int maxn=1010;
int main(){
	int n,m,k,in[maxn]={0};
	int a,b,num=0;
	cin>>n>>m;
	vector<int> node[maxn];
	for(int i=0;i<m;i++){
		cin>>a>>b;
		node[a].push_back(b);
		in[b]++;
	}
	cin>>k;
	for(int i=0;i<k;i++){
		bool flag=true;
		vector<int> tempin(in,in+n+1);
		for(int j=0;j<n;j++){
			cin>>a;
			if(tempin[a]!=0){
				flag=false;
				continue;
			}else{
				for(int it=0;it<node[a].size();it++){
					tempin[node[a][it]]--;
				}
			}
		}
		if(flag==false){
			num++;
			if(num==1) cout<<i;
			else cout<<" "<<i;
		}
	}
	return 0;
} 
