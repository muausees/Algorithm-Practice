#include <bits/stdc++.h>

using namespace std;

int M, N, a[105], dp[105][10005], ans = 0;

int main(int argc, char** argv) {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= N; i++) {
		for(int j = M; j >= 0; j--) {
			if(j < a[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			if(j == a[i]) {
				dp[i][j] = dp[i - 1][j] + 1;
			}
			if(j > a[i]) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
			}
		}
	}
	cout << dp[N][M];
	return 0;
}
