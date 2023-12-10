#include <bits/stdc++.h>

using namespace std;

int n;
array<int, 105> a, b;

int main(int argc, char *argv[]) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if(i >= 1){
            a[i] = b[i] * i - b[i - 1] * (i - 1);
        }
        else
            a[i] = b[i];
    }
    for(int i = 1; i <= n; ++i){
        cout << a[i] << ' ';
    }
    return 0;
}