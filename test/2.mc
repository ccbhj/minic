/* A program to perform selection sort on a 10 element array.*/
int x[10];
int minloc(int a[],int low,int high){
    int i;
    int x;
    int k;
    k = low;
    x = a[low];
    i = low + 1;
    while( i < high){
        if( a[i] < x){
            x = a[i];
            k = i;
        }
        i = i + 1;
    }
}
void main(void){
    int i;
    i = 0;
    while( i <10){
        x[i] = input();
        i = i+1;
        sort(x,0,10);
        i = 0;
        while(i<10){
            output(x[i]);
            i= i+1;
        }
    }
}
