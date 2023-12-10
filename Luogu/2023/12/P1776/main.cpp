#include <bits/stdc++.h>

using namespace std;

int n, W;
array<int64_t, 105> v, w, m;
array<int64_t, 100005> vc, wc;
array<int64_t, 100005> dp;
int num = 1;

int main(int argc, char** argv) {
	cin >> n >> W;
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> w[i] >> m[i];
		int mclone = m[i];
		for (int x = 1; x < mclone; x *= 2) { // 二进制拆分
			mclone -= x;
			vc[num] = v[i] * x;
			wc[num] = w[i] * x;
			num++;
		}
		if(mclone > 0) {
			vc[num] = v[i] * mclone;
			wc[num] = w[i] * mclone;
			num++;	
		}
	}
	num--;
	for (int i = 1; i <= num; i++) {
		for (int j = W; j >= wc[i]; j--) {
			dp[j] = max(dp[j], dp[j - wc[i]] + vc[i]);
		}
	}
	cout << dp[W];
	return 0;
}
