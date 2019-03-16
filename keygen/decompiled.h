#pragma once

#include "defs.h"

void ACFXGenCodeSecert(const char *code, _BYTE *secert);
void ACFXGenCodeSecertBeautify(const char *code, _BYTE *secert);
char ACFXMatchSecert(const char *name, const _BYTE *secert);
char ACFXMatchSecertBeautify(const char *name, const _BYTE *secert);

int sub_40A8F0(int a1);

char ACFCharToUpper(char a1);
bool ACFCharIsLower(unsigned __int8 a1);

static _BYTE ACDXMatchedResult[5];

static _BYTE ACDXSecertCode0[32] = {
	0x59,
	0x35,
	0x45,
	0x37,
	0x55,
	0x5A,
	0x39,
	0x58,
	0x50,
	0x32,
	0x33,
	0x51,
	0x57,
	0x4B,
	0x4D,
	0x4E,
	0x36,
	0x41,
	0x2B,
	0x54,
	0x53,
	0x43,
	0x21,
	0x34,
	0x56,
	0x46,
	0x47,
	0x48,
	0x4A,
	0x52,
	0x2D,
	0x44
};

static _BYTE ACDXSecretCode1[8] = { // 5 elements enough
	0x5D,
	0x22,
	0x4F,
	0x4E,
	0x0FC,
	0,
	0,
	0
};

static _BYTE ACDXSecretCode2[8] = { // 5 elements enough
	2,
	3,
	5,
	8,
	9,
	0,
	0,
	0
};
