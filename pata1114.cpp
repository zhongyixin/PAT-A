#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int father[10000];
int visit[10000];
struct Person{
	int id,fid,mid,num,area;
	int cid[10];
}person[1010];
struct Family{
	int id,person;
	double num,avg;
	bool flag=false;
}ans[10000];
int findFather(int x){
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}
void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA>faB) father[faA]=faB;
	else if(faA<faB) father[faB]=faA;
}
bool cmp(Family a,Family b){
	return a.avg!=b.avg?a.avg>b.avg:a.id<b.id;
}
int main(){
	int n,k,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<10000;i++)
		father[i]=i;
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&person[i].id,&person[i].fid,&person[i].mid,&k);
		visit[person[i].id]=true;
		if(person[i].fid!=-1){
			visit[person[i].fid]=true;
			Union(person[i].id,person[i].fid);
		}
		if(person[i].mid!=-1){
			visit[person[i].mid]=true;
			Union(person[i].id,person[i].mid);
		}
		for(int j=0;j<k;j++){
			scanf("%d",&person[i].cid[j]);
			visit[person[i].cid[j]]=true;
			Union(person[i].id,person[i].cid[j]);
		}
		scanf("%d%d",&person[i].num,&person[i].area);
	} 
	for(int i=0;i<n;i++){
		int f=findFather(person[i].id);
		ans[f].id=f;
		ans[f].num+=person[i].num;
		ans[f].avg+=person[i].area;
		ans[f].flag=true;
	}
	for(int i=0;i<10000;i++){
		if(visit[i]){
			ans[findFather(i)].person++;
		}
		if(ans[i].flag)
		    cnt++;
	}
	for(int i=0;i<10000;i++){
		if(ans[i].flag){
			ans[i].num=(double)(ans[i].num/ans[i].person);
			ans[i].avg=(double)(ans[i].avg/ans[i].person);
		}
	}
	sort(ans,ans+10000,cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].person,ans[i].num,ans[i].avg);
	}
	return 0;	
}
