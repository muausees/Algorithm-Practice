#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		string name;
		map<string, Node*> son;
		Node() {
			name = " ";
		}
		Node(string n) {
			name = n;
		}
};

int N;

int64_t bfs(Node* &h) {
	int64_t ans = 0;
	queue<Node*> Q;
	Q.push(h);
	while (!Q.empty()) {
		for (auto it : Q.front() -> son) {
			Q.push(it.second);
			ans++;
		}
		Q.pop();
	}
	return ans;
}

int main(int argc, char** argv) {
	Node* head = new Node("$");
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int d = 0;
		string name;
		bool ISFIRST = true;
		Node* last = nullptr;
		for (int pos = 0; pos < str.length(); pos++) {
			if (str[pos] != '/') {
				name += str[pos];
			}
			if (str[pos] == '/' || str[pos + 1] == '\0') {
//				while(str[pos + 1] != '/' && str[pos + 1] != '\0'){
//					pos++;
//					name += str[pos];
//				}
				if(!ISFIRST){
					if (d == 0) {
						if (head -> son[name] == nullptr) {
							head -> son[name] = new Node(name);
						}
						last = head -> son[name];
						d = 1;
					} else {
						if (last -> son[name] == nullptr) {
							last -> son[name] = new Node(name);
						}
						last = last -> son[name];
					}
				}
				else ISFIRST = false;
				string n;
				name = n;
			}
		}
		cout << bfs(head) << '\n';
	}
	return 0;
}
