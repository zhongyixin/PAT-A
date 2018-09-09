#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	string str;
	int n;
	cin>>n; 
	getchar();
	getline(cin,str);
	vector<char> v;
	int len=str.length();
	int row=(len%n==0)?len/n:len/n+1;
	for(int i=0;i<n;i++){
		v.clear();
		for(int j=0+i;j<len;j+=n){
			v.push_back(str[j]);
		}
		if(v.size()<row){
			for(int j=0;j<row-v.size();j++)
			 cout<<" ";
		}
		for(int j=v.size()-1;j>=0;j--)
		 cout<<v[j];
		cout<<endl;
	}
	return 0;
}
