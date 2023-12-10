#include <bits/stdc++.h>

using namespace std;

const int V = 28800;

int n, t;
array<int, 210> v, c;
array<int, 40000> vclone, cc;
array<int, 40000> dpA, dpB;
int k = 1;

int main(int argc, char** argv) {
	//freopen("P2851.in", "r", stdin);
	//freopen("P2851.out", "w", stdout);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		int cclone = c[i];
		int w = 1;
		while (w < cclone) {
			cc[k] = w;
			vclone[k++] = w * v[i];
			cclone -= w;
			w *= 2;
		}
		if (cclone > 0) {
			cc[k] = w;
			vclone[k++] = cclone * v[i];
		}
	}
	k--;
	dpA.fill(INT32_MAX / 2);
	dpB.fill(INT32_MAX / 2);
	dpA[0] = 0;
	dpB[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = V + t; j >= vclone[i]; j--) {
			dpA[j] = min(dpA[j], dpA[j - vclone[i]] + cc[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = v[i]; j <= V; j++) {
			dpB[j] = min(dpB[j], dpB[j - v[i]] + 1);
		}
	}
	int ans = INT32_MAX / 2;
	for (int i = 0; i <= V; i++) {
		ans = min(ans, dpA[i + t] + dpB[i]);
	}
	if (ans == INT32_MAX / 2) cout << -1;
	else cout << ans;
	return 0;
}
