#include <iostream>
#include <sstream>
using namespace std; 

int main() {
  string line;
  while (getline(cin, line)) {
    istringstream iss(line);
    string word;
    int i = 0;
    //count the string numbers
    while ( getline( iss, word, ' ' ) ) {
      i++;
    }
    cout << i << endl; 
  }
 return 0; 
}
