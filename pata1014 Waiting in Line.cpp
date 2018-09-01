#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int pt,time;
};
int main(){
	int n,m,k,q,temp;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	vector<node> cus(k);
	vector<int> win(n,0);
	queue<int> que[n];
	for(int i=0;i<k;i++){
		scanf("%d",&cus[i].pt);
	}
	for(int i=0;i<k;i++){
		int min=0;
	    for(int j=0;j<n;j++){
			if(que[j].size()<que[min].size())
			 min=j;
		}	
		if(que[min].size()==m){
			for(int j=0;j<n;j++){
				if(cus[que[j].front()].time<cus[que[min].front()].time)
				 min=j;
			}
			que[min].pop();
		}
		que[min].push(i);
		cus[i].time=win[min]>=540?-1:win[min]+cus[i].pt;
		win[min]+=cus[i].pt;
	}
	for(int i=0;i<q;i++){
		scanf("%d",&temp);
		temp--;
		if(cus[temp].time==-1){
		  printf("Sorry\n");
		  continue;
	    }
	    int ti=cus[temp].time+8*60;
	    printf("%02d:%02d\n",ti/60,ti%60);
	}
	return 0;
}
