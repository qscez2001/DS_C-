#include<iostream>
using namespace std;

class Stack {
  private:
    //20是限制輸入的字串長度..
    char item[MAX][20];
    int top;
  public:
    Stack();
    void push_f(void); //新增函數
    void pop_f(void); //刪除函數
    void list_f(void); //輸出函數
};

Stack::Stack()
{
  top = -1;
}

//加入一元素於堆疊
void Stack::push_f(void)
{
  if(top >= MAX - 1) {
    cout<<"\n堆疊已滿\n"; //當堆疊已滿則顯示錯誤
  }
  else {
    top++;
    cout<<"\n請輸入一個物件到堆疊: ";
    cin >> item[top];
  }
}
//刪除一元素於堆疊
void Stack::pop_f(void)
{
  if(top<0) {
    cout<<"\n堆疊是空的\n"; //當堆疊是空的則顯示錯誤
  }
  else {
    cout<<"\npop"<<item[top]<<"from stack\n";
    top--;
  }
}

class Implement: public Parenthesis
{
  public:
    Implement();
    void isvalid(string input);  
};

void Implement::isvalid(char input[]) 
{
  不管三種括號的優先權,(小括號),[中括號],{大括號} 都是等價的
  運算式中即使括號不必要,只要相互對應合法就好 -> () [] {}
  
  if(1)//如果是有效的
    case 1.如果沒有運算式,只有單純括號排列 e.g. (((}{{}(){}]][[[][]
            value=0
    case 2.呼叫：infix_to_postfix 計算postfix 的value
  if(0)//如果是無效的
    case 1.要把括號補齊.排列好
            如果沒有運算式,只有單純括號排列 e.g. (((}{{}(){}]][[[][]
            value=0
    case 2.呼叫：infix_to_postfix 計算postfix 的value
}
------------------------
以下是function

void fix_order()
{

}
修改括號：
(左括號必定保留,右括號去對應
錯誤修正的priority : 更正>補齊=刪掉)
1. 相對應的右括號沒合法,要修改成對應合法的括號
2. 相對應的位置沒有右括號要補滿並且要為對應合法的括號
3. 沒有和它相對應的左括號,即為多餘的右括號,要刪掉

void infix_to_postfix()
{
  1.要把(),[],{}給權重
  2.根據權重 infix_to_postfix
  3.呼叫：計算postfix 的value

}

1.要把(),[],{}給權重
2.根據權重 infix_to_postfix
3.呼叫：計算postfix 的value

void postfix_的value
{
  計算postfix 的value：
  根據運算子的權重來計算...
  因為電腦不會判斷[],{}為運算子
  所以要自己設定...
}


int main()
{
  int a = 1*(2+3)*5;
  cout<<a<<endl;
}

// input:
// {[[()}[]{]][}{}]]][}{))()))}[{{])(

// output:
// False
// {[[()][]{}][]{}}[]{}()[{{}}()]
// 0