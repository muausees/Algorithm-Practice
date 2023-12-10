#include <bits/stdc++.h>

using namespace std;

string s;
stack<int> St;

int main(int argc, char** argv) {
	cin >> s;
	for(auto it : s){
		if(it == '('){
			St.push(1);
		}
		else if(it == ')'){
			if(St.empty()){
				cout << "NO";
				return 0;
			}
			else{
				St.pop();
			}
		}
	}
	if(St.empty()){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}
