#include<cstdio>
#include<vector>
using namespace std;

int main(){
	int d,n;
	vector<int> a,b;
	scanf("%d%d",&d,&n);
    a.push_back(d);
	while(n-1){
		b.clear();
		for(int i=0;i<a.size();i++){
			int num=1;
			while(i+1<a.size()&&a[i+1]==a[i]){
				num++;
				i++;
			}
			b.push_back(a[i]);
			b.push_back(num);
		}
		a=b;
		n--;
	}
	for(int i=0;i<a.size();i++){
		printf("%d",a[i]);
	}
	return 0;
}
