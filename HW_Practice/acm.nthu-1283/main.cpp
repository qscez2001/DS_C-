#include <iostream>
#include "function.h"

using namespace std; 

class Implement : public abstractAdd {
    public:
        int myAdd(int a, int b) {
            return a+b;
        }
};

int main() {

    Implement i;

    int int1, int2;
    while ( cin >> int1 >> int2 ) {
        cout << i.myAdd(int1, int2) << endl;
    }
   
    return 0; 
}
