#include <bits/stdc++.h>

using namespace std;

int n, maxt = 0;
int t[2005], c[2005];
int64_t dp[4005]; // dp[j]表示前i件物品耗时j的最小金额
int64_t ans = 9000000000000000000;

int main(int argc, char** argv) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> c[i];
		t[i]++;
		maxt = max(maxt, t[i]);
	}
	maxt += n;
	memset(dp, 0x7f, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = maxt; j >= t[i]; j--) {
			dp[j] = min(dp[j], dp[j - t[i]] + c[i]);
		}
	}
	for(int i = n; i <= maxt; i++){
		ans = min(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
