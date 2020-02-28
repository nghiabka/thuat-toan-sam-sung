#include<iostream>

using namespace std;
const int M = 1e9+7;
int modsum(int *a, int n){
    if (n ==1)
    {
        return a[0]%M;
    }else
    {
        return ((a[n-1]%M) + modsum(a, n-1))%M;
    }
    
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin >>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << modsum(a, n);
    
    return 0;
}
