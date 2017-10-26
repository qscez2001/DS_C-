#ifndef _FUNCTION_H_
#define _FUNCTION_H_
class abstractAdd
{
public:
	abstractAdd(){};
	~abstractAdd(){};
	virtual int myAdd(int a, int b) = 0;

};

class Implement;

#endif