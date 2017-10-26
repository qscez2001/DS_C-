#include<iostream>
using namespace std;

class Implement
{
  public:
    Implement();
    ~Implement();
  
};

主程式
Check the format of parentheses that is valid or not
If true,  
output “True” and   evaluate the value of expression
If false, 
output “False” and 
transform the expression to the correct form and
evaluate the value of expression

Step

一 
呼叫 確認輸入是不是有效的(除了括號錯,不會有其他錯)
判斷 true, false


二 
如果是有效的
case 1.如果沒有運算式,只有單純括號排列 e.g. (((}{{}(){}]][[[][]
        value=0
case 2.呼叫：infix_to_postfix

如果是無效的
呼叫：修改括號
case 1.如果沒有運算式,只有單純括號排列 e.g. (((}{{}(){}]][[[][]
        要把括號補齊.排列好
        value=0
case 2.呼叫：infix_to_postfix


infix_to_postfix：
1.要把(),[],{}給權重
2.根據權重 infix_to_postfix
3.呼叫：計算postfix 的value


------------------------
以下是function

確認輸入是不是有效的：
不管三種括號的優先權,(小括號),[中括號],{大括號} 都是等價的
運算式中即使括號不必要,只要相互對應合法就好 -> () [] {}


修改括號：
(左括號必定保留,右括號去對應
錯誤修正的priority : 更正>補齊=刪掉)
1. 相對應的右括號沒合法,要修改成對應合法的括號
2. 相對應的位置沒有右括號要補滿並且要為對應合法的括號
3. 沒有和它相對應的左括號,即為多餘的右括號,要刪掉

計算postfix 的value：
根據運算子的權重來計算...
因為電腦不會判斷[],{}為運算子
所以要自己設定...


Implement::isvalid(char input[]) 
{
  if(1) calculate it
  if(0)
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