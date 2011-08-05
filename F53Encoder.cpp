#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "F53Encoder.h"

using namespace std;

const char encoderTable[65] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', NULL, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};

const unsigned int encoderTableLength = 65;

const int magicCondesner = 0x3F; // value of 0b00111111 so theres only 6 bits left, yayz

static uint6_t condense(int i) {
	

	cout << i << endl;
	uint6_t result = *(uint6_t *)&i;

	return result;

}

uint6_t F53Encoder::encodeChar(char c) {

	for (int i = 0; i <= 52; i++) {

		if (c == encoderTable[i])
			return condense(i);

	}

	for (int i = 54; i <= encoderTableLength; i++) {

		if (c == encoderTable[i])
			return condense(i);

	}

	return condense(54);
//i think this will work.... cuz of spill over, not sure, works with int to char so hopefully this works with two bits less
}

uint6_t *F53Encoder::encodeStatement(char *c) {

	uint6_t *result = (uint6_t *)calloc(strlen(c), sizeof(uint6_t));

	for (int i=0; i < strlen(c); i++) {
		result[i] = encodeChar(c[i]);
	}

	return result;

	//note you are in charge of freeing this, yes sorry no fancy schmancy c++ class for one of these 6 bit ints....
}

