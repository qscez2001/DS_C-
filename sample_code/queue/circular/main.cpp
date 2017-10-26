//環狀佇列
#include<iostream>
#include<math.h>

using namespace std;
#define MAX 5

class Queue
{
private:
  char cq[MAX];
  //初始值
  int front = MAX-1;
  int rear = MAX-1;
  int tag = 0;
public:
  Queue(){}
  ~Queue(){} 
  void enqueue_f();
  void dequeue_f();
  
};

//add
//如果(rear+1) % MAX = 0 便可以進入環狀佇列的前端
void Queue::enqueue_f(void)
{
  if (front == rear && tag == 1)
  {
    //將rear退到正確位置
    rear = (rear+1) % MAX;
    if(rear == 0)
    {
      rear = MAX-1;
    }
    else
    {
      rear = rear - 1;
    }
    cout<<"環狀佇列已滿\n";
  }
  else
  {
    rear = (rear+1) % MAX;
    cout<<"請輸入一個物件: ";
    cin>>cq[rear];
    //省一個空間 多了tag
    if(front == rear)
    {
      tag = 1;
    }
  }

}

//delete
void Queue::dequeue_f(void)
{
  if(front == rear && tag == 0)
  {
    cout<<"環狀佇列是空的\n";
  }
  else
  {
    //把front往前移
    front = (front+1) % MAX;
    cout<<cq[front]<<"已被刪除\n";
    if(front == rear)
    {
      tag = 0;
    }  
  }
}

int main()
{
  Queue obj;
  obj.enqueue_f();
  obj.dequeue_f();
}