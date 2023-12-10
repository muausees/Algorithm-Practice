#include <bits/stdc++.h>

using namespace std;

int T;
int a[105];
int dp[25005];

// 思路，如果货币系统中其中一个面额的货币可以被另外的其他货币表示出来，那么这个货币就是没有必要的，去掉它的新货币系统与原先等价
// 因此将全部可以去掉的货币去掉就能得出答案

int main(int argc, char** argv) {
	cin >> T;
	for (int k = 1; k <= T; k++) {
		memset(a, 0, sizeof a);
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = n;
		for (int i = 1; i <= n; i++) {
			memset(dp, 0, sizeof dp);
			dp[0] = 1;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				for (int k = a[j]; k <= a[i]; k++) {
					dp[k] = dp[k] + dp[k - a[j]];
				}
			}
			if(dp[a[i]] != 0) ans--;
		}
		cout << ans << endl;
	}
	return 0;
}
