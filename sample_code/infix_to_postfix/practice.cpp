#include <iostream>
#include <string>
#include <cctype>

class Stack
{
public:
  Stack();
  ~Stack();
  void Push(int a);
  int Pop();
  Top();
};



void postfix()
{
  //read infix
  char infix_q[100];
  //assume the last token of e is '#'
  int rear = -1;
  while(infix_q[rear] != '\n')
  {
    cin.get(infix_q[++rear]);
  }
  infix_q[rear] = '#';

  //a function nextToken is used to get next token in e
  Stack<Token> stack;
  for(char x = NextToken(infix_q[100]); x!= '#'; x = NextToken(infix_q[100]))
  {
    if(isdigit)
    {
      cout << x;
    }
    else if(x == ')')//pop until '('
    {
      for(; stack.Top()!='('; stack.Pop())
      {
        cout<<stack.Top();
      }
      stack.Pop();//pop '('
    }
    else //x is an operator
    {
      for(;icp(stack.Top()) <= icp(x);stack.Pop())
      {
        cout<<stack.Top();
      }
      stack.Push(x);
    }
    //end of expression; empty the stack
    for(;!stack.IsEmpty(); cout << stack.Top(), stack.Pop());
  }
}

char NextToken(char infix_q[100])
{
  
  return infix[i];
}