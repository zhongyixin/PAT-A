#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string> id(n);
	vector<string> pw(n);
	vector<int> iid;
	for(int i=0;i<n;i++){
		cin>>id[i]>>pw[i];
		bool flag=false;
		for(int j=0;j<pw[i].length();j++){
			if(pw[i][j]=='1') {pw[i][j]='@';flag=true;}
			else if(pw[i][j]=='l') {pw[i][j]='L';flag=true;}
			else if(pw[i][j]=='0') {pw[i][j]='%';flag=true;}
			else if(pw[i][j]=='O') {pw[i][j]='o';flag=true;}
		} 
		if(flag) iid.push_back(i);
	}
	if(iid.size()>0){
		cout<<iid.size()<<endl;
		for(int i=0;i<iid.size();i++){
			cout<<id[iid[i]]<<" "<<pw[iid[i]]<<endl;
		}
	}else if(n==1){
		 printf("There is 1 account and no account is modified");
	}	else printf("There are %d accounts and no account is modified",n);
	
	return 0;
}
