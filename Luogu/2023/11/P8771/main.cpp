#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
array<int, 1000005> p;

int main(int argc, char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i < n; ++i) {
        if(abs(p[i] - p[i - 1]) <= 1) continue;
        ans++;
    }
    cout << ans;
    return 0;
}