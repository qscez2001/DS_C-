#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()

{
  freopen("i.in","r", stdin);
  
  //read a line until EOF
  string lineStr;
  while( getline(cin, lineStr) )
  {
    cout << "Current line = " << lineStr << endl;

    //make a input string stream
    istringstream iss(lineStr);

    int counter = 0;
    int iValue;
    //read from the iss until end of string
    while( iss >> iValue )
    {
      cout << iss;
      cout << iValue*2 << " | ";
      counter++;
    }
    cout << "length = " << counter << endl;
    
  } 
}
