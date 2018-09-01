#include<cstdio>
#include<set> 
using namespace std;

const int maxn=10010;

int main(){
	int n,num,fn;
	scanf("%d",&n);
	set<int> friendnum; 
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		fn=0;
		while(num){
			fn+=num%10;
			num/=10;
		}
	    friendnum.insert(fn);
	}
	printf("%d\n",friendnum.size());
	set<int>::iterator it=friendnum.begin();
	printf("%d",*it);
	for(it++;it!=friendnum.end();it++){
		printf(" %d",*it);
	}
	return 0;
}
