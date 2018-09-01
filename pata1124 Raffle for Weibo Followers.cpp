#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int maxn=1010;
set<string> ss;
int main(){
	int m,n,s;
	string str[maxn];
	scanf("%d%d%d",&m,&n,&s);
	for(int i=1;i<=m;i++){
		//scanf("%s",str[i]);
        cin>>str[i];
	}
	for(int i=s;i<=m;i+=n){
		if(ss.find(str[i])==ss.end()){
			//printf("%s\n",str[i]);
			cout<<str[i]<<endl;
			ss.insert(str[i]);
		}else{
			while(ss.find(str[i])!=ss.end()){
				i++;
			}
			cout<<str[i]<<endl;
			ss.insert(str[i]); 
		}
	}
	if(ss.size()==0) printf("Keep going...") ;
	return 0;
}
