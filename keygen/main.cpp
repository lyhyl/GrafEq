#include "decompiled.h"

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void ACFXGetSecertByName(const char *name, _BYTE *secert)
{
	int nameLen = strlen(name);
	_BYTE vResult[5];
	vResult[0] = secert[0] = 0; // rand();
	vResult[1] = secert[1] = 0; // rand();
	vResult[2] = secert[4] = 0; // rand();
	vResult[3] = secert[6] = 0; // rand();
	vResult[4] = secert[7] = 0; // rand();

	for (int i = 0; i < 5; i++)
	{
		char v16 = ACDXSecretCode1[i];
		for (int j = 0; j < nameLen; j++)
		{
			v16 += name[j] | (17 * i + vResult[(i + j) % 5]);
		}
		secert[ACDXSecretCode2[i]] = v16;
	}
}

void ACFXGetCodeBySecert(const _BYTE *secert, char *code)
{
	_BYTE xcode[16];
	_BYTE s[11];
	memcpy_s(s, sizeof s, secert, 10);

	for (size_t i = 0; i < 16; i++)
	{
		int bb = i * 5;
		int c = bb / 8;
		int cr = bb % 8;
		xcode[i] = ((s[c] >> cr) | (s[c + 1] << (8 - cr))) & 0b11111;
	}

	for (size_t i = 0; i < 16; i++)
	{
		code[i] = ACDXSecertCode0[xcode[i]];
	}
}

int main()
{
	int mode;

	cout << "Enter mode(0=gen, otherwise=test):" << endl;
	cin >> mode;
	if (mode)
	{
		string name, code;
		_BYTE secert1[10];
		_BYTE secert2[10];
		while (cin >> name >> code)
		{
			ACFXGenCodeSecert(code.c_str(), secert1);
			ACFXGenCodeSecertBeautify(code.c_str(), secert2);
			cout << (ACFXMatchSecertBeautify(name.c_str(), secert1) ? "Matched" : "Failed") << endl;
		}
	}
	else
	{
		string name;
		while (cin >> name)
		{
			for (size_t i = 0; i < name.size(); i++)
				name[i] = toupper(name[i]);

			_BYTE secert[10];
			ACFXGetSecertByName(name.c_str(), secert);
			char code[17];
			code[16] = 0;
			ACFXGetCodeBySecert(secert, code);
			cout << code << endl;
		}
	}
	getchar();
	return 0;
}