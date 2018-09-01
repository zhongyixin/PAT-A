#include<cstdio>
#include<set>
using namespace std;
int main(){
	int n,num;
	int max=0;
	set<int> ss;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(num>max) max=num;
		if(num>0) ss.insert(num);
	}
	for(int i=1;i<=max+1;i++){
		if(ss.find(i)==ss.end()){
			printf("%d",i);break;
		}
	} 
	return 0;
}
