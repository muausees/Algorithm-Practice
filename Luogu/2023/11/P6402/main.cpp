#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> name;

int main(int argc, char *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string namein;
        cin >> namein;
        name[namein]++;
    }
    for (int i = 0; i < n - 1; ++i) {
        string namein;
        cin >> namein;
        name[namein]--;
    }
    for(auto it : name){
        if(it.second == 1) cout << it.first;
    }
    return 0;
}