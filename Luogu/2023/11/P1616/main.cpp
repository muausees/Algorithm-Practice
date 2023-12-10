#include <bits/stdc++.h>

using namespace std;

int t, m;
int a[10005], b[10005];
long long dp[10000005];

int main(int argc, char** argv) {
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= t; j++) {
			if (j >= a[i]) {
				dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
			}
		}
	}
	cout << dp[t];
	return 0;
}
