#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> arr(n),v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		v[i]=arr[i];
	} 
	int cnt=0,max=0;
	vector<int> ans;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		if(arr[i]==v[i]&&v[i]>max){
			cnt++;
			ans.push_back(v[i]);
		}
		if(v[i]>max) max=v[i];
	}
	printf("%d\n",cnt);
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i<ans.size()-1) printf(" ");
	}
	return 0;
} 
