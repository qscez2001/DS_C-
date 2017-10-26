#include <iostream>

using namespace std;

int sum(int arr[4], int n)
{                   //執行次數
  int i, total = 0; //1
  for(i=0;i<n;i++)  //n+1
  {
    total+=arr[i];  //n
  }
  return total;     //1
}
int main(void)
{
  int arr[4] = {3, 2, 1, 4};
  int output = sum(arr, 4);
  cout<<output<<endl;
}

