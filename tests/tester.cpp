#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "test_types.h"

using namespace std;
using namespace sgl;

int _tmain(int argc, _TCHAR* argv[]) {
	cout << "Simple geometry library (SGL)" << endl;

	// Types
	TestTypes test_types(std::cout);
	test_types.RunTests();
	test_types.PrintErrors();

	getchar();

	return 0;
}

