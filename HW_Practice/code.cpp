#include <iostream>
#include "function.h"

using namespace std; 

class Implement : public abstractAdd {
    public:
        int myAdd(int a, int b) {
            return a+b;
        }
};
