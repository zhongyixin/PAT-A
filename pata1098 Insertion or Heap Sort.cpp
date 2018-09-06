#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> orgi,now,temp;
bool isInsertion(){
	int next=0;
	for(int i=2;i<=n;i++){
		int j=i-1;
		int x=temp[i];
		while(temp[j]>x&&j>=1){
			temp[j+1]=temp[j];
			j--;
		}
		temp[j+1]=x;
		if(next==1) return true;
		if(temp==now)
			next=1;
	}
	return false;
}
void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&temp[j+1]>temp[j]) j++;
		if(temp[j]>temp[i]){
			swap(temp[i],temp[j]);
			i=j;
			j=i*2;
		}else break; 
	}
}
void Heap(){
	int next=0;
	for(int i=n/2;i>=1;i--)
	  downAdjust(i,n);
	for(int i=n;i>=2;i--){
		swap(temp[1],temp[i]);
		downAdjust(1,i-1);
		if(next==1) return;
		if(temp==now) next=1;
	} 
}
int main(){
	scanf("%d",&n);
	orgi.resize(n+1);
	now.resize(n+1);
	for(int i=1;i<=n;i++)
	   scanf("%d",&orgi[i]);
	for(int i=1;i<=n;i++)
	   scanf("%d",&now[i]);
	 temp=orgi;
	 if(isInsertion()){
	 	printf("Insertion Sort\n");
	 	for(int i=1;i<=n;i++){
	 		printf("%d",temp[i]);
	 		if(i<n) printf(" ");
		 }
	 }else{
	 	temp=orgi;
	 	printf("Heap Sort\n");
	 	Heap();
		 for(int i=1;i<=n;i++){
		 	printf("%d",temp[i]);
		 	if(i<n) printf(" ");
		 }
	 }
	 return 0; 
}
