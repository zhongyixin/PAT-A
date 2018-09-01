#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,x;
	vector<double> rope;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		rope.push_back(1.0*x);
	}
	sort(rope.begin(),rope.end());
	for(int i=0;i<n-1;i++){
		double d=(rope[0]+rope[1])/2;
		rope.erase(rope.begin(),rope.begin()+2);
		int j=0;
		while(rope.size()!=0&& rope[j]<d) j++;
		rope.insert(rope.begin()+j,d);
	}
	printf("%d",(int)rope[0]);
	return 0;
} 
