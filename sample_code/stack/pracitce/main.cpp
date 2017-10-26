//使用堆疊處理資料：新增.刪除.輸出
#include <iostream>
#define MAX 5

using namespace std;

class Stack
{
private:
  int stack[MAX];
  int top;
public:
  Stack()
  {
    //init stack
    top=-1;
  }

  void push(int a);
  int pop();
  void list();
  
};

//加入一元素於堆疊
void Stack::push(int a)
{
  if (top >= MAX-1)
  {
    cout<<"stack is full"<<endl;
  }
  else
  {
    top++;
    //cout<<"\n請輸入一個物件到堆疊: ";
    stack[top] = a;
  }
}

int Stack::pop()
{
  if (top <= -1)
  {
    cout<<"stack is empty"<<endl;
  }
  else
  {
    cout<<"pop "<<stack[top]<<" from the stack"<<endl;
    top--;
  }
}

void Stack::list()
{
  int count = 0;
  if (top <= -1)
  {
    cout<<"stack is empty"<<endl;
  }
  else
  {
    for(int i=0;i<=top;i++)
    {
      cout<<stack[i]<<endl;
      count++;
    }
    cout<<"總共有："<<count<<"\n";
  }
}

int main()
{
  Stack obj;
  int input;
  cin>>input;
  obj.push(input);
  obj.list();
  return 0;
}