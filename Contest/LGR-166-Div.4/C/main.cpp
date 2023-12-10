#include <bits/stdc++.h>

using namespace std;

int maxGrade = 0, Grade3 = 0, Grade8 = 0;

int main(int argc, char *argv[]) {
    for(int i = 0; i < 8; i++){
        int power;
        cin >> power;
        maxGrade = max(maxGrade, power);
        if(power >= 41){
            ++Grade3;
        }
        if(power >= 63){
            ++Grade8;
        }
    }
    if(maxGrade >= 118){
        cout << 10;
        return 0;
    }
    if(Grade8 >= 4){
        cout << 8;
        return 0;
    }
    if(Grade3 >= 4){
        cout << 3;
        return 0;
    }
    cout << 1;
    return 0;
}