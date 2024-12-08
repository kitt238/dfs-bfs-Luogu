#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#define int long long
#define INF 0x7fffffff
#define Pi 3.1415926535897932384626
using namespace std;

double sum, rearea, r[9];
int n, xs, ys, xe, ye;
int x[9], y[9],rec[9];

double min(double a1, double a2, double a3 = INF, double a4 = INF) {
	double a = a1;
	if (a > a2)a = a2;
	if (a > a3)a = a3;
	if (a > a4)a = a4;
	return a;
}

double perarea(int k) {
	double minr=min(abs(xs-x[k]), abs(xe - x[k]), abs(ys - y[k]), abs(ye - y[k]));
	for (int i = 1; i <=n; i++) {
		if (k!=i&&rec[i]) {
			double d = sqrt(pow(abs(x[k] - x[i]), 2) + pow(abs(y[k] - y[i]), 2));
			minr = min(minr, d-r[i]);
		}
	}
	if (minr < 0)minr = 0;
	r[k] = minr;
	return Pi*pow(minr,2);
}

void dfs(int step,double persum) {
	if (step == n) {
		sum = max(persum, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!rec[i]) {
			persum += perarea(i);
			rec[i] = 1;
			dfs(step + 1,persum);
			persum -= perarea(i);
			rec[i] = 0;
		}
	}
}

signed main() {
	cin >> n;
	cin >> xs >> ys >> xe >> ye;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	dfs(0, 0);
	rearea = abs(ye - ys) * abs(xe - xs) - sum+0.5;
	cout << (int)rearea;
	return 0;
}