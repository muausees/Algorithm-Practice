#include <bits/stdc++.h>

using namespace std;

int a, b, c, d ,M;

int main(int argc, char *argv[]) {
    cin >> a >> b >> c >> d >> M;
    if(c * 5 > M){
        if(c * 5 + d * 20 - (b - d) * 20 <= 0) cout << 0;
        else cout << c * 5 + 2 * d * 20 - b * 20;
    }
    else{
        if(c * 5 - (b - d) * 20 <= 0) cout << 0;
        else cout << c * 5 + d * 20 - b * 20;
    }
    return 0;
}