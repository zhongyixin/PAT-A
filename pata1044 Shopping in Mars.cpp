#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100010;
int n,m,a,sum[maxn];
void func(int i,int &j,int &tempsum){
	int left=i,right=n;
	while(left<right){
		int mid=(left+right)/2;
		if(sum[mid]-sum[i-1]>=m){
			right=mid;
		}else left=mid+1;
	}
	j=left;
	tempsum=sum[left]-sum[i-1];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		sum[i]=sum[i-1]+a;
	}
	int min=sum[n];
	vector<int> ans;
	for(int i=1;i<=n;i++){
		int j,tempsum;
		func(i,j,tempsum);
		if(tempsum>min) continue;
		if(tempsum>=m){
			if(tempsum<min){
				ans.clear();
				min=tempsum;
			}
			ans.push_back(i);
			ans.push_back(j);
		}
	}
	for(int i=0;i<ans.size();i+=2){
		printf("%d-%d\n",ans[i],ans[i+1]);
	}
	return 0;
} 
