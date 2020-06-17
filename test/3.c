#include <stdio.h>
int a[7];

void output(int i) {
  printf("%d", i);
}
int minloc(int a[],  int low, int high)
{   
  int i;  int x;  int k;
  k=low;
  x=a[low];
  i=low+1;
  while(i<high)
  {  
    if(a[i]< x)
    {  
      x =a[i];
      k=i;
    }
    i=i+1;
  }
  return k;  
}

int main(void) {
  a[0] = 3;
  a[1] = 1;
  a[2] = 6;
  a[3] = 2;
  a[4] = 7;
  a[5] = 9;
  a[6] = 5;
  output(minloc(a, 0, 9));
  return 0;
}
