//AC
#include <bits/stdc++.h>

using namespace std;

int T, M;

bool rational(double x) { // 判断有理数
	if (x - (int)x <= 0.00001) return true;
	return false;
}

void multiTest(){
	int a, b, c; // 一元二次方程系数
	cin >> a >> b >> c;
	int delta = b * b - 4 * a * c; // Δ
	if (delta < 0) { // 无解
		cout << "NO\n";
		return;
	}
	if (delta == 0) { // delta == 0，解一定是有理数
		int sup = 0, sdown = 0; // a,b的符号，0为正，1为负
		int up = -b, down = 2 * a; // a, b绝对值方便运算
		bool symbol = false; // -b / 2a的符号，true代表负
		if (up < 0) sup = 1;
		if (down < 0) sdown = 1;
		symbol = sup ^ sdown;
		up = abs(up);
		down = abs(down);
		int gcd = __gcd(up, down);
		up /= gcd;
		down /= gcd;
		if (symbol) {
			up = 0 - up;
		}
		if (down == 1) cout << up << '\n';
		else cout << up << '/' << down << '\n';
		return;
	} else { // delta != 0
		int isSy = 0; // 0则解为-b + sqrt(delta) / 2a
		if (2 * a < 0) isSy = 1; // -b - sqrt(delta) / 2a
		//此时问题变为判断解整体为有理数，关键在于sqrt(delta)是有理数
		double sqrtDelta = sqrt(delta);
		bool isRational = false;
		isRational = rational(sqrtDelta);
		if (isRational) { // 解为有理数
			bool symbol = false; // 输出的符号，true代表负
			int up;
			if (isSy) {
				up = -b - (int)(sqrtDelta); // 分子
			} else up = -b + (int)(sqrtDelta);
			int down = 2 * a;
			int sup = 0, sdown = 0; // up,down的符号，0为正，1为负
			if (up < 0) sup = 1;
			if (down < 0) sdown = 1;
			symbol = sup ^ sdown;
			up = abs(up);
			down = abs(down);
			int gcd = __gcd(up, down); // 最大公因数
			up /= gcd;
			down /= gcd;
			if (symbol) {
				up = 0 - up;
			}
			if (down == 1) cout << up << '\n';
			else cout << up << '/' << down << '\n';
			return;
		} else { // 不是有理数
			// 分成-b / 2a和sqrt(delta) / 2a来处理，也就是有理和无理分开处理
			//-b / 2a部分
			bool symbolF = false;
			bool have = true; // 有常数项
			int upF = -b;
			int downF = 2 * a;
			int supF = 0, sdownF = 0;
			if (upF < 0) supF = 1;
			if (downF < 0) sdownF = 1;
			symbolF = supF ^ sdownF;
			upF = abs(upF);
			downF = abs(downF);
			int gcdF = __gcd(upF, downF); // 最大公因数
			upF /= gcdF;
			downF /= gcdF;
			if (symbolF) {
				upF = 0 - upF;
			}
			if (downF == 1) {
				if (upF != 0) cout << upF;
				else have = false;
			} else {
				if (upF != 0) cout << upF << '/' << downF;
				else have = false;
			}
			//sqrt(delta)部分
			//将sqrt(delta)化到最简
			int maxFac = 1;
			for (int m = 2; m * m <= delta; m++) {
				if (delta % (m * m) == 0) {
					maxFac = m;
				}
			}
			int cloneDelta = delta / maxFac / maxFac;
			//处理系数
			bool symbolS = false;
			int upS = maxFac;
			int downS = 2 * a;
			int supS = 0, sdownS = 0;
			if (upS < 0) supS = 1;
			if (downS < 0) sdownS = 1;
//				symbolS = supS ^ sdownS;
//				symbolS ^= isSy;
			int s = supS + sdownS + isSy;
			if (s % 2 != 0) symbolS = true;
			upS = abs(upS);
			downS = abs(downS);
			int gcdS = __gcd(upS, downS); // 最大公因数
			upS /= gcdS;
			downS /= gcdS;
			if (have) {
				if (symbolS) cout << '-';
				else cout << '+';
			}
			if (downS == 1) {
				if (upS != 1) cout << upS << '*';
				cout << "sqrt(" << cloneDelta << ")\n";
			} else {
				if (upS != 1) cout << upS << '*';
				cout << "sqrt(" << cloneDelta << ")/" << downS << '\n';
			}
		}
	}
}

int main(int argc, char** argv) {
	cin >> T >> M;
	for (int i = 0; i < T; i++) {
		multiTest();
	}
	return 0;
}
