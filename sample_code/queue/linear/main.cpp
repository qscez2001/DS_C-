//線性佇列
#include<iostream>

using namespace std;

int MAX = 5;
int front = -1;
int rear = -1;
//add
void Queue::enqueue_f(void)
{
  if(rear >= MAX-1)
  {
    cout<<"佇列已滿\n";
  }
  else
  {
    rear++;
    cout<<"請輸入一個物件到佇列: ";
    cin>>a[rear];
  }
}

//delete
void Queue::dequeue_f(void)
{
  if(front == rear)
  {
    cout<<"佇列是空的\n";
  }
  else
  {
    front++;
    cout<<"從佇列刪除<<a[front]\n";    
  }
}

int main()
{

}