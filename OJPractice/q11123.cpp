#include <iostream>
#include <sstream>
using namespace std; 

int main() {
  string line;
  while ( getline(cin, line)) {
    istringstream iss(line);
    string word;
    //c_str(): get C string equivalent
    while ( getline( iss, word, ' ' ) ) {
      printf( "%s\n", word.c_str() );
    }
  }
 return 0; 
}
