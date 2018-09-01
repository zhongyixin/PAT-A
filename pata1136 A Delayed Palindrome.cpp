#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string a,string b){
	int len=a.length(),carry=0;
	string ans;
	for(int i=0;i<len;i++){
		int num=a[i]-'0'+b[i]-'0'+carry;
		carry=0;
		if(num>=10){
		  carry=1;
		  num-=10;
		} 
		ans+=char(num+'0');
	}
	if(carry==1) ans+='1';
	reverse(ans.begin(),ans.end());
	return ans; 
}
int main(){
	string num;
	cin>>num;
    int count=10;
	while(count){
		string rnum=num;
		reverse(rnum.begin(),rnum.end());
		if(rnum==num){
			cout<<num<<" is a palindromic number." ;
		    break;
		}else{
			cout<<num<<" + "<<rnum<<" = "<<add(num,rnum)<<endl;
			num=add(num,rnum);
			count--;
		}
	}	
	if(count==0) cout<<"Not found in 10 iterations.";
	return 0; 
}
