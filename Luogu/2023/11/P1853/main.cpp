#include <bits/stdc++.h>

using namespace std;

int s, n, d;
int a[15], b[15];
array<int, 5000005> dp;

int main(int argc, char** argv) {
	cin >> s >> n >> d;
	for (int i = 1; i <= d; i++) {
		cin >> a[i] >> b[i];
	}
	int ss = s;
	for (int k = 1; k <= n; k++) {
		dp.fill(0);
		for (int i = 1; i <= d; i++) {
			for (int j = a[i] / 1000; j <= ss / 1000; j++) {
				dp[j] = max(dp[j], dp[j - a[i] / 1000] + b[i]);
			}
		}
		if (k == n) {
			cout << dp[ss / 1000] + ss;
		}
		ss += dp[ss / 1000];
	}
	return 0;
}
