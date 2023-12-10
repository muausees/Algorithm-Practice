#include <iostream>
#include <string>

using namespace std;

class baseClass{
public:
	virtual void print(string a) = 0;
};

class OddP : baseClass{
public:
	void print(string a) override{
		cout << a << ' ' << 1 << endl;
	}
}oddp;

class NOddP : baseClass{
public:
	void print(string a) override{
		cout << a << ' ' << 2 << endl;
	}
}noddp;

int main(int argc, char** argv) {
	oddp.print("Hello World");
	noddp.print("Hello World");
	return 0;
}
