#include <bits/stdc++.h>

using namespace std;

int h, n;
int p[105], c[105];
array<int, 55005> dp;

int main(int argc, char *argv[]) {
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> c[i];
	}
	dp.fill(0x7f7f7f7f);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= h + 5000; j++) {
			if (j >= p[i]) {
				dp[j] = min(dp[j], dp[j - p[i]] + c[i]);
			}
		}
	}
	int minx = 0x7f7f7f7f;
	for(int i = h; i <= h + 5000; i++){
		minx = min(minx, dp[i]);
	}
	cout << minx;
	return 0;
}