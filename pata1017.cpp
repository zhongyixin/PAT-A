#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int T,P;
};
int n,k;
vector<node> customer;
bool cmp(node a,node b){
	return a.T<b.T;
}
int main(){
	int hh,mm,ss,pp;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&pp);
		int T=3600*hh+60*mm+ss-28800;
		if(T>32400) continue;
		if(pp>60) pp=60;
		customer.push_back(node{T,pp*60});
	}
	sort(customer.begin(),customer.end(),cmp);
	vector<int> window(k,0);
	double ans=0.0;
	for(int i=0;i<customer.size();i++){
		int tindex=0,min=window[0];
		for(int j=1;j<k;j++){
			if(window[j]<min){
				tindex=j;
				min=window[j];
			}
		}
		if(window[tindex]<=customer[i].T)
		  window[tindex]=customer[i].T+customer[i].P;
		else{
			ans+=(window[tindex]-customer[i].T);
			window[tindex]+=customer[i].P;
		} 
	}
	if(customer.size()==0) printf("0.0"); 
	else printf("%.1f",ans / 60.0 / customer.size());
	return 0;
}
