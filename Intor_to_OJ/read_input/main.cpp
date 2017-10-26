#include <iostream>
#include <cstdio>

using namespace std;

int main()

{
  freopen("i.in","r", stdin);

  int num;
  char name[255];
  
  while( cin >> num >> name )
  {
    cout << num << " " << name << endl;
  }
 
}
