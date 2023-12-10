#include "core.h"

int main() {
	StartInfo();
	while(true) {
		int8_t choiceMenu = Menu();
		SwitchCalculator(choiceMenu);
	}
	return 0;
}