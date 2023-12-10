//
// Created by MRWintermeow on 2023/11/23.
//

#include "core.h"
#include "calculate.h"

void StartInfo() {
	printf("Welcome to MUAUSEES's Calculator\n");
	printf("Version: %s\n", VERSION_OF_CALCULATOR);
}

uint8_t Menu() {
	uint8_t MenuChoice;
	printf("1 Add 2 Subtract 3 Multiply 4 Exit\n");
	scanf("%d", &MenuChoice);
	return MenuChoice;
}

bool SwitchCalculator(int8_t choice) {
	switch(choice) {
		int first, second;
		case 1:
			scanf("%d %d", &first, &second);
			Add(first, second);
			break;
		case 2:
			scanf("%d %d", &first, &second);
			Sub(first, second);
			break;
		case 3:
			scanf("%d %d", &first, &second);
			Mul(first,second);
		default:
			return false;
	}
	return true;
}
