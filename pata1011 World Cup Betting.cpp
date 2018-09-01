#include<cstdio>
#include<iostream>
int main(){
	double ans=1.0,a;
	for(int i=0;i<3;i++){
		int index;
		double max=0.0;
		for(int j=0;j<3;j++){
			scanf("%lf",&a);
			if(a>max) {
				max=a;
				index=j;
			}
		}
		if(index==0) printf("W ");
		if(index==1) printf("T ");
		if(index==2) printf("L ");
		ans*=max;
	}
	printf("%.2f",(ans*0.65-1)*2);
	return 0;
}
