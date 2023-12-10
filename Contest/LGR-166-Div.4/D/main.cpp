#include <bits/stdc++.h>

using namespace std;

int n;
array<int, 10005> p;

int isPrime(int input){
    if(p[input] != 0) return p[input];
    if(input <= 1){
        p[input] = -1;
        return p[input];
    }
    int sqrtIn = sqrt(input);
    for(int i = 2; i <= sqrtIn; i++){
        if(input % i == 0){
            p[input] = -1;
            return p[input];
        }
    }
    p[input] = 1;
    return p[input];
}

int main(int argc, char *argv[]) {
    cin >> n;
    for(int i = 1; i <= n; i++){
        int maxChar = i * i;
        int charNum = 0;
        for(int j = 1; ; j++){
            if(isPrime((i - 1 + charNum) % 26 + 65 + j) == -1){
                cout << ' ';
                continue;
            }
            else{
                cout << (char)((i - 1 + charNum) % 26 + 65);
                charNum++;
            }
            if(charNum >= maxChar) break;
        }
        cout << endl;
    }
    return 0;
}