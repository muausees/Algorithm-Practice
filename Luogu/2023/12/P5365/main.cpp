#include <bits/stdc++.h>

using namespace std;

int64_t N, M;
int k[5005], c[5005];
int64_t total = 0;
int64_t dp[250000];

int main(int argc, char** argv) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> k[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= N; i++) {
		total += (int64_t)k[i] * (int64_t)c[i];
	}
	dp[0] = 1;
//	for (int i = 1; i <= N; i++) {
//		for (int x = 1; x <= k[i]; x++) {
//			for (int j = total; j >= x * c[i]; j--) {
//				dp[j] = max(dp[j], dp[j - x * c[i]] * x);
//			}
//		}
//	}
	for (int i = 1; i <= N; i++) {
		for (int j = total; j >= 0; j--) {
			for (int x = 1; x <= k[i] && x * c[i] <= j; x++) {
				dp[j] = max(dp[j], dp[j - x * c[i]] * x);
			}
		}
	}
	for (int j = 0; j <= total; j++) {
		if (dp[j] >= M) {
			cout << j;
			return 0;
		}
	}
	return 0;
}
