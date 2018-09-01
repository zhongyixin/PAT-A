#include<iostream>
int arr[10010];
int main(){
	int n;
	scanf("%d",&n);
	int nowmax=0,numL=0,numR=n-1,sum=-1,tempindex=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		nowmax+=arr[i];
		if(nowmax>sum){
			sum=nowmax;
			numL=tempindex;
			numR=i;
		}else if(nowmax<0){
			nowmax=0;
			tempindex=i+1;
		}
	}
	if(sum<0) sum=0;
	printf("%d %d %d",sum,arr[numL],arr[numR]);
	return 0;
}
