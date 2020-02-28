#include <iostream>

using namespace std;

int D[1000];

void init(int n){
    for (int  i = 0; i <= n; i++)
    {
        if (i == 0 || i ==1)
        {
            D[i] = 1;
        }else
        {
            D[i] = 0;
        }   
    }  
}

int fibonacy(int n){
    if (D[n] > 0)
    {
        return D[n];
    }else
    {
        D[n] = fibonacy(n-1) + D[n-2];
        return D[n]; 
    }
    
    
}

int main(int argc, char const *argv[])
{
    int n = 4;
    init(n);
    cout << fibonacy(n) << endl;
    
    return 0;
}
