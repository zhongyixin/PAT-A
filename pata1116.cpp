#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
const int maxn=10010;

int ran[10000]={0};
bool isPrime(int n){
	if(n<=1) return false;
	int x=sqrt(double(n));
	for(int i=2;i<=x;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n,k,id;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&id);
		ran[id]=i;
	}
	set<int> ID;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&id);
		if(ran[id]==0) {
		  printf("%04d: Are you kidding?",id);
		}else if(ID.find(id)==ID.end()){
			ID.insert(id);
			if(ran[id]==1) printf("%04d: Mystery Award",id);
			else if(isPrime(ran[id])){
				printf("%04d: Minion",id);
			}else printf("%04d: Chocolate",id);
		}else printf("%04d: Checked",id);
		if(i<k-1) printf("\n");
	}
	return 0;
}
