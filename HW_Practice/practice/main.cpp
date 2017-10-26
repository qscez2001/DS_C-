#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "code.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	abstractAdd& ra = *new Implement();
	string input;
	while(getline(std::cin, input)){
		istringstream testcase(input);
		int a,b;
		testcase >> a;
		testcase >> b;
		cout << ra.myAdd(a,b) << endl;
	}

	return 0;
}
