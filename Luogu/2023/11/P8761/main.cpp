#include <bits/stdc++.h>

using namespace std;

string input;

int main(int argc, char *argv[]) {
    cin >> input;
    for(auto& i : input){
        i = (char)toupper(i);
    }
    cout << input;
    return 0;
}