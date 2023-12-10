#include <iostream>

using namespace std;

int s, v;

int main(int argc, char* argv[]){
    cin >> s >> v;
    int t = s / v;
    if((double)s - (double)(v * (s / v)) >= 0.000001)
    {
        t++;
    }
    t += 10;
    int h, m;
    if(t % 60 == 0){
        if(t / 60 > 8){
            h = 32 - t / 60;
        }
        else{
            h = 8 - t / 60;
        }
        m = 0;
    }
    else{
        if(t / 60 > 8){
            h = 31 - t / 60;
        }
        else{
            h = 7 - t / 60;
        }
        m = 60 - t % 60;
    }
    if(h < 10){
        if(m < 10)
            cout << 0 << h << ':' << 0 << m << endl;
        else
            cout << 0 << h << ':' << m << endl;
    }
    else{
        if(m < 10)
            cout << h << ':' << 0 << m << endl;
        else
            cout << h << ':' << m << endl;
    }
    return 0;
}