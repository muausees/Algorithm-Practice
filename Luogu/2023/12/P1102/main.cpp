#include <bits/stdc++.h>

using namespace std;

int n, c;
array<int, 200010> a;
array<pair<int, int>, 200010> b;
int j = 1;
int64_t ans = 0;

int main(int argc, char *argv[]) {
	//freopen("question.in", "r", stdin);
	//freopen("question.out", "w", stdout);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.begin() + n, less<>());
	for (int i = 0; i < n; i++) { // 去重，用pair存储每个数及其个数，方便双指针
		int first = a[i];
		int second = 1;
		while (a[i + 1] == a[i] && i + 1 <= n) {
			i++;
			second++;
		}
		pair<int, int> p(first, second);
		b[j++] = p;
	}
	for (int i = 0, x = 0; x < n;) {
		if (b[x].first - b[i].first == c) {
			ans += (int64_t)b[x].second * (int64_t)b[i].second;
			i++;
			x++;
		}
		else if (b[x].first - b[i].first > c) {
			i++;
		}
		else {
			x++;
		}
	}
	cout << ans;
	return 0;
}