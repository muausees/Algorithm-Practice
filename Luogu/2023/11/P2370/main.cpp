#include <bits/stdc++.h>

using namespace std;

struct item {
	int w, v;
} it[1005];

bool cmp(item a, item b) {
	return a.w < b.w;
}

int n, p, S;
int w[1005], v[1005];
int64_t dp[1005];

int main(int argc, char** argv) {
	cin >> n >> p >> S;
	for (int i = 1; i <= n; i++) {
		cin >> it[i].w >> it[i].v;
	}
	sort(it + 1, it + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		for (int j = S; j >= it[i].w; j--) {
			dp[j] = max(dp[j], dp[j - it[i].w] + it[i].v);
			if (dp[S] >= p) {
				cout << it[i].w;
				return 0;
			}
		}
	}
	cout << "No Solution!";
	return 0;
}
