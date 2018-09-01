//这样做最后一个点运行超时，name用char[] 存，字符串比较用strcmp()即可 
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct node{
	int id,grade;
	string name;
};
bool cmp1(node a,node b){
	return a.id<b.id;
}
bool cmp2(node a,node b){
	return (a.name!=b.name)?a.name<b.name:a.id<b.id;
}
bool cmp3(node a,node b){
	return (a.grade!=b.grade)?a.grade<b.grade:a.id<b.id;
}
int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	vector<node> stu(n);
	for(int i=0;i<n;i++)
		cin>>stu[i].id>>stu[i].name>>stu[i].grade;
	getchar();
	if(c==1) sort(stu.begin(),stu.end(),cmp1);
	if(c==2) sort(stu.begin(),stu.end(),cmp2);
	if(c==3) sort(stu.begin(),stu.end(),cmp3);
	for(int i=0;i<n;i++){
		printf("%06d ",stu[i].id);
		cout<<stu[i].name<<" "<<stu[i].grade<<endl;
	}
	return 0;
}
