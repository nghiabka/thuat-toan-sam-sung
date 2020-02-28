#include<iostream>

using namespace std;


long maxLeft(int *a, int start, int end){
    long max = a[end];
    int s = 0;
    for(int i = end; i >= start; i--){
        s += a[i];
        max = max > s ? max:s;
    }
    return max;
}



long maxRight(int *a, int start, int end){
    long max = a[start];
    int s = 0;
    for(int i = start; i <= end; i++){
        s += a[i];
        max = max > s ? max:s;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
