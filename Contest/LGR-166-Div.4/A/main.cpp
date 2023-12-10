#include <bits/stdc++.h>

using namespace std;

int a, b, R, V, M;

int main(int argc, char *argv[]) {
    cin >> a >> b >> R >> V >> M;
    cout << 4 * R * a + R * b << ' ' << 6 * V * a + V * b << ' ' << 6 * M * a + M * b;
    return 0;
}