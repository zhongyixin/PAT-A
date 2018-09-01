#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){
	return a+b<b+a;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<string> v(n);
	for(int i=0;i<n;i++)
	   cin>>v[i];
	sort(v.begin(),v.end(),cmp);
	int i=0;
	string s="";
	for(int i=0;i<n;i++)
		s+=v[i];
    while(s[0]=='0') s.erase(s.begin());
    cout<<s;
    if(s.size()==0) cout<<"0"; 
	return 0;
}
 
