#include "decompiled.h"

#include <iostream>
#include <string>

using namespace std;

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

	}
	getchar();
	return 0;
}