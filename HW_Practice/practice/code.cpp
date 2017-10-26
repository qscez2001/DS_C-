
#include <iostream>
#include "function.h"
// Please implement the add function in the class implement.

// int implement::add(int,int)
//考virtual用法

class Implement : public abstractAdd
{
  public:
    Implement(){};
    int myAdd(int a,int b)
    {
      return a+b;
    }
};