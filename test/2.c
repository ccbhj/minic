#include <stdio.h>
/* A program  to perform selection sort on a 10
element  array*/ 
int x[10];
void output(int i) {
  printf("%d", i);
}

int input() {
  int i;
  scanf("%d", &i);
  return i;
}

int minloc(int a[],  int low, int high)
{   int i;  int x;  int k;
    k=low;
    x=a[low];
    i=low+1;
   while(i<high)
    {  
        if(a[i]< x)
        {  x =a[i];
           k=i;
        }
        i=i+1;
    }
      return k;  
}

void sort(int a[], int low,  int high)
{   int i;  int k;
    i=low;
    while(i<high-1) 
    {  int t;
       k=minloc(a, i, high);
       printf("k: %d\n", k);
       t=a[k];
       a[k]= a[i];
       a[i]=t;
       i=i+1;
    }
}

int main (void) {
    x[0] = 6;
    x[1] = 7;
    x[2] = 2;
   
    sort(x, 0, 3);

    int i;
    i = 0;
    while (i < 3) {
      output(x[i]);
      i = i + 1;
    }
}
