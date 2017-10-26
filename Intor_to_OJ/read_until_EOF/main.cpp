#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()

{
  freopen("i.in","r", stdin);

  string cmd1, tid;
  int cap;
  float fValue;

  while( cin >> cmd1 >> tid >> cap >> fValue )
  {
    cout << cmd1 << " " << tid << " " << cap << " " << fixed << setprecision(1) << fValue << endl;
  } 
}
