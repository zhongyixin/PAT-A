#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	int N;
	scanf("%d", &N);
	vector<int >num(N);
	for (int i = 0; i<N; i++){
		scanf("%d", &num[i]);
	}
	if (N == 1){
		printf("%d", num[0]);
		return 0;
	}
	sort(num.begin(), num.end(), cmp);
	int m = (int)ceil(sqrt(1.0*N));
	while (N%m != 0){
		m++;
	}
	int n = N / m;
	int x = 0, y = 0, index = 0;
	int X[4] = { 0, 1, 0, -1 };
	int Y[4] = { 1, 0, -1, 0 };
	vector<vector<int> > ans(m, vector<int>(n));
	while (index<N){
		ans[x][y] = num[index++];
		for (int i = 0; i<4; i++){
			int xi = x + X[i];
			int yi = y + Y[i];
			if (xi >= 0 && xi<m&&yi >= 0 && yi<n&&ans[xi][yi] == 0){
			/*	if (i == 0 && xi>0 && yi>0 && ans[xi - 1][yi - 1] == 0){
					//每一次判断右面是否为空的时候先判断上面为不为空
					//若为空,向上填空
					x = xi - 1;
					y = yi - 1;
					break;
				}//若不为空则向右填 */ 
				x = xi;
				y = yi;
				break;
			}
		}
	}
	for (int i = 0; i<m; i++){
		for (int j = 0; j<n; j++){
			printf("%d", ans[i][j]);
			if (j != n - 1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
