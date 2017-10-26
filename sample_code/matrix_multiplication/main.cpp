#include<iostream>
using namespace std; 

int a[3][3] = 
{ {0,1,2},
  {3,4,5},
  {6,7,8}
};

int b[3][3] = 
{ {1,1,1},
  {1,1,1},
  {1,1,1}
};
int c[3][3];
int n=3;


void mul(int a[3][3],int b[3][3], int c[3][3], int n)
{
  int i, j, k, sum;
  for(i=0;i<n;i++) {
    for (j=0; j<n; j++) {
      sum = 0;
      for(k=0;k<n;k++) {
        sum=sum+a[i][k]*b[k][j];
        c[i][j] = sum;
      }
    printf("%d\t", c[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  mul(a,b,c, n);
}

