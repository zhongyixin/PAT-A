#include<iostream>
#include<string>
using namespace std;
char dig[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'}; 
int main(){
	int co[3];
	scanf("%d%d%d",&co[0],&co[1],&co[2]);
	string ans="";
	for(int i=2;i>=0;i--){
		int n=co[i];
		int t=2;
		while(t--){
			ans.push_back(dig[n%13]);
			n/=13;
		}
	}
	ans.push_back('#');
	for(int i=ans.length()-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
