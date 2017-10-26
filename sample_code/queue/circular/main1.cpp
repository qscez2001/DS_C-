//環狀佇列
//使用環狀佇列加上Tag處理資料:新增.刪除.輸出
#include<iostream>

using namespace std;
#define MAX 5

class Cqueue
{
private:
  char item[MAX][20];
  int front;
  int rear;
  //tag為記憶front所在是否有儲存資料, 0為沒有存放資料, 1為有存放資料
  int tag;
public:
  Cqueue();
  void enqueue_f(void);
  void dequeue_f(void);
  void list_f(void);
};

Cqueue::Cqueue()
{
  front = MAX-1;
  rear = MAX-1;
  tag = 0;
}

//add
//如果(rear+1) % MAX = 0 便可以進入環狀佇列的前端
//rear = (rear+1) % MAX 這行其實已經代表推進一格
void Cqueue::enqueue_f(void)
{
  //當佇列已滿,則顯示錯誤
  if (front == rear && tag == 1)
  {
    cout<<"環狀佇列已滿\n";
  }
  else
  {
    rear = (rear+1) % MAX;
    cout<<"請輸入一個物件: ";
    cin>>item[rear];
    //省一個空間 多了tag
    if(front == rear)
    {
      tag = 1;
    }
  }

}

//delete
void Cqueue::dequeue_f(void)
{
  //當佇列沒有資料存在,則顯示錯誤
  if(front == rear && tag == 0)
  {
    cout<<"環狀佇列是空的\n";
  }
  else
  {
    //把front往前移
    front = (front+1) % MAX;
    cout<<item[front]<<"已被刪除\n";
    if(front == rear)
    {
      tag = 0;
    }  
  }
}

void Cqueue::list_f(void)
{
  int count = 0, i;
  if(front == rear && tag == 0)
  {
    cout<<"佇列是空的\n";
  }
  else
  {
    cout<<"ITEM\n";
    cout<<"----------------------\n";
    for(i = (front+1)%MAX; i != rear; i = ++i % MAX)
    {
      cout<<" ";
      cout<<item[i]<<endl;
      count++;
    }
    cout<<item[i]<<endl;
    cout<<"----------------------\n";
    cout<<"總共有: "<<++count<<"\n";
  }
}

int main()
{
  Cqueue obj;
  char option;
  while(1)
  {
    cout<<"\n*********************\n";
    cout<<"    <1>插入(enqueue)\n";
    cout<<"    <2>刪除(dequeue)\n";
    cout<<"    <3>列出\n";
    cout<<"    <4>退出\n";
    cout<<"*********************\n";
    cout<<"請輸入選項...";
    cin>>option;
    cout<<option<<endl;
    switch(option) 
      {
        case '1': 
          obj.enqueue_f();
          break;
        case '2':
          obj.dequeue_f();
          break;
        case '3':
          obj.list_f();
          break;
        case '4':
          return 0;
      }
  }
}