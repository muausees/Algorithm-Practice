#include <bits/stdc++.h>

using namespace std;

int H, T, N;
int h[55], t[55], k[55];
int dp[55][405][405];

int main(int argc, char** argv) {
	cin >> H >> T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> h[i] >> t[i] >> k[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= H; j++) {
			for (int m = 0; m <= T; m++) {
				if (j >= h[i] && m >= t[i]) {
					dp[i][j][m] = max(dp[i - 1][j][m], dp[i - 1][j - h[i]][m - t[i]] + k[i]);
				}
				else dp[i][j][m] = dp[i - 1][j][m];
			}
		}
	}
	cout << dp[N][H][T];
	return 0;
}
