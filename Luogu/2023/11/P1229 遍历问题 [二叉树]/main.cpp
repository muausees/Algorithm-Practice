#include <bits/stdc++.h>

using namespace std;

string s1, s2; // s1前缀，s2后缀
int64_t ans = 1;

int main() {
	// 只有在一个节点只有一个子树时，才会因为不知道该子树在左边还是右边产生两种情况
	// 因此，统计只有一个节点的个数，根据乘法原理得到结果
	// 如果前序遍历存在两个节点如AB，后续遍历出现两个节点BA，代表A有且仅有一个子节点B
	cin >> s1 >> s2;
	for(int i = 0; i <= s1.length() - 2; i++){
		for(int j = 0; j <= s2.length() - 2; j++){
			string ss = s2.substr(j, 2);
			reverse(ss.begin(), ss.end());
			if(s1.substr(i, 2) == ss){
				ans *= 2; //乘法原理
			}
		}
	}
	cout << ans;
	return 0;
}
