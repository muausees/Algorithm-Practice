#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 1;
char pre = '\0';

int main(int argc, char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char input;
        cin >> input;
        if(input != pre) ++ans;
        pre = input;
    }
    cout << ans;
    return 0;
}