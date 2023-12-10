#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

int n, c;
int ans = 0;
array<int, 200005> a;

int check(int i, int b){
    if(a[i] - a[b] == c) return 0;
    else if(a[i] - a[b] > c) return 1;
    else return -1;
}

int binary_search(int i){
    int out = 0;
    int l = i;
    int r = n - 1;
    while(r >= l){
        int mid = ceil((double)(l + r) / 2);
        int s = check(mid, i);
        if(s == 0){
            ++out;
            while(check(mid - 1, i) == 0){
                --mid;
                ++out;
            }
            return out;
        }
        else if(s == 1){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return out;
}

int main(int argc, char* argv[]){
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.begin() + n, [](int a, int b) -> bool{ return a < b; });
    for(int i = 0; i < n; ++i){
        ans += binary_search(i);
    }
    cout << ans;
    return 0;
}