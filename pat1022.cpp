#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
map<string,set<int>> title,author,key,pub,year;
void query(map<string,set<int>> &mp,string str){
	if(mp.find(str)!=mp.end()){
		for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++){
			printf("%07d\n",*it);
		}
	}else cout<<"Not Found"<<endl;
}
int main(){
	int n,id,m,te;
	string tit,auth,ke,pu,ye,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		getchar();
		getline(cin,tit);
		title[tit].insert(id);
		getline(cin,auth);
		author[auth].insert(id);
		while(cin>>ke){
			key[ke].insert(id);
			if(getchar()=='\n') break;
		}
		getline(cin,pu);
		pub[pu].insert(id);
		getline(cin,ye);
		year[ye].insert(id);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d: ",&te);
		getline(cin,temp);
		cout<<te<<": "<<temp<<endl;
		if(te==1) query(title,temp);
		else if(te==2) query(author,temp);
		else if(te==3) query(key,temp);
		else if(te==4) query(pub,temp);
		else if(te==5) query(year,temp); 
	}
    return 0;
}
 
