#include<iostream>
#include<queue>
#define int long long
#define INF 0x7fffffff
using namespace std;

int director(char k) {
	if (k == 'E')return 0;
	if (k == 'S')return 1;
	if (k == 'W')return 2;
	if (k == 'N')return 3;
}

typedef struct {
	int x, y,dir,ans;
}dot;

queue<dot>q;
int dx[][4] = { {0,1,0,-1},{0,2,0,-2},{0,3,0,-3} };
int dy[][4] = { {1,0,-1,0},{2,0,-2,0},{3,0,-3,0} };
int a[55][55],n,m,xs,ys,xe,ye,dir0;
int rec[4][55][55];//记录某个点的某个方向是否走过
//int recc[10][11];
int minans = INF;

//int straight(int length) {
//	return length / 3 + length % 3 / 2 + length % 3 % 2;
//}//计算直线路径时间

bool crash(dot d, int i, int j) {
	for (int k = 0; k <= i; k++) {
		if (a[d.x + dx[k][j]][d.y + dy[k][j]] == 1||d.x+dx[k][j]<=0||d.x+dx[k][j]>=n||d.y+dy[k][j]<=0||d.y+dy[k][j]>=m) {
			return 1;
		}
	}
	return 0;
}

void bfs(dot d) {
	if (d.x == xe && d.y == ye) {
		if (d.ans < minans)minans = d.ans;
	}
	for (int j = 0; j < 4; j++) {
		//recc[d.x + dx[i][j]][d.y + dy[i][j]]++;
		dot q0;
		if (j != d.dir) {
			if (!((j - d.dir) % 2))continue;//补药往回走
			if (rec[j][d.x][d.y]==1)continue;
			rec[j][d.x][d.y] = 1;
			q0 = { d.x ,d.y,j,d.ans+1 };
			q.push(q0);
		}
		else {
			for (int i = 2; i >=0; i--) {
				if (d.x + dx[i][j] < 0 || d.x + dx[i][j] > n || d.y + dy[i][j]<0 || d.y + dy[i][j]>m)continue;//越界跳过
				if (crash(d, i, j) || rec[j][d.x + dx[i][j]][d.y + dy[i][j]])continue;//撞墙或已走跳过
				rec[j][d.x + dx[i][j]][d.y + dy[i][j]] = 1;
				q0 = { d.x + dx[i][j],d.y + dy[i][j],d.dir,d.ans + 1 };
				q.push(q0);
			}
		}
	}
	if (!q.empty()) {
		dot q1 = q.front();
		q.pop();
		bfs(q1);
	}
}

signed main() {
	char k;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			if (x) {
				a[i][j] = 1;
				a[i - 1][j] = 1;
				a[i][j - 1] = 1;
				a[i - 1][j - 1] = 1;
			}
		}
	}
	cin >> xs >> ys >> xe >> ye >> k;
	//recc[xs][ys] = -100;
	//recc[xe][ye] = -100;
	rec[director(k)][xs][ys] = 1;
	dot d0 = { xs,ys,director(k),0};
	bfs(d0);
	if (minans == INF)cout << -1;
	else cout << minans;
	return 0;
}//我嘞个骚刚  