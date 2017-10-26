/*
A:5x^4 + 3x^2 + 2
B:6x^3 + 2x^2 + 1
*/

#include<iostream>
#include<iomanip>

using namespace std;

//感覺只是為了有個數字佔住array[0]這個位置
#define DUMMY -1

void output_P(int [], int);
void padd(int [],int [],int []);
char compare(int, int);

int main()
{
  int A[] = { DUMMY,3,4,5,2,3,0,2 };
  int B[] = { DUMMY,3,3,6,2,2,0,1 };
  int C[13] = {DUMMY};
  //將A加B放到C
  padd(A, B, C);
  cout<< "\nA =";
  //A[1]*2+1為 陣列A 的大小
  output_P(A, A[1]*2+1);
  cout<< "\nB =";
  output_P(B, B[1]*2+1);
  cout<< "\nC =";
  output_P(C, C[1]*2+1);
  cout<< "\n";
  //system("PAUSE");
  return 0;
}

void padd(int a[], int b[], int c[])
{
  int p,q,r,m,n;
  char result;
  m = a[1]; n = b[1]; //多項式非零項的個數
  p = q = r = 2;  //指到陣列第二個元素
  while (p<=2*m && q<=2*n)
  {
    //比較a與b的指數
    result = compare(a[p], b[q]);
    switch(result) 
    {
      case '=' :
        c[r+1] = a[p+1]+b[q+1]; //係數相加
        if(c[r+1] != 0) 
        {
          c[r] = a[p]; //指數assifn給c
          r+=2;
        }
        p+=2; q+=2; //移至下一個指數位置
        break;
      case '>' :
        c[r+1] = a[p+1];
        c[r] = a[p];
        p+=2; r+=2;
        break;
      case '<' :
        c[r+1] = b[q+1];
        c[r] = b[q];
        q+=2; r+=2;
        break;
    }
  }
  //表示b的多項式已經結束, 將a多項式的餘項全部搬至c
  while(p<=2*m)
  {
    c[r+1] = a[p+1];
    c[r] = a[p];
    p+=2; r+=2;
  }
  //表示a的多項式已經結束, 將b多項式的餘項全部搬至c
  while(q<=2*n)
  {
    c[r+1] = b[q+1];
    c[r] = b[q];
    q+=2; r+=2;
  }
  c[1] = r/2 - 1; //計算c總共有多少非零項
}

char compare(int x,int y)
{
  //A指數=B指數
  if(x==y){
    return '=';
  } 
  //A指數>B指數
  else if (x>y) {
    return '>';
  }
  //A指數<B指數
  else {
    return '<';
  }
}

void output_P(int p[], int n)
{
  int i;
  cout<<"(";
  for (i = 1; i <= n; i++)
  {
    cout<<setw(3)<<p[i];
  }
  cout<<")";
}