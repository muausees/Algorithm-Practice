#include <bits/stdc++.h>

using namespace std;

int n, s, m;
double point;
double pointNow = 0;

int binarySolve(){
    int left = 0;
    int right = m;
    int mid = 0;
    while(right > left){
        mid = (left + right) / 2;
        if(s - (mid * point / 2 + pointNow) >= 0 && s - (mid * point / 2 + pointNow) <= n){
            pointNow = mid * point / 2 + pointNow;
            return mid;
        }
        else if(s - (mid * point / 2 + pointNow) < 0){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return mid;
}

int main(int argc, char *argv[]) {
    cin >> n >> s >> m;
    point = (double)1e7 / (double)n;
    pointNow += (n - m) * point;
    int f = binarySolve();
    int l = m - f;
    cout << 'p' << n - m << "(+" << s - floor(pointNow) << ") f" << f << " l" << l;
    return 0;
}