#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >>n;
    int num;
    cin >> num;
    int a[n];
    cout << endl;
    for (int i = n-1; i >=0; i--)
    {
        a[i] = num%10;
        cout << a[i];
        num = (int)num/10;
    }
    cout << endl;
    int i = n-1;
    while (a[i] != 0 && i >=0)
    {
        a[i] =0;
        --i;
    }
    if (i < 0)
    {
        cout << -1;
        return 0;
    }
    
    a[i] = 1;
    // for (int j = i+1; j < n; j++)
    // {
    //     a[j] = 0;
    // }
    for (int t = 0; t < n; t++)
    {
        cout << a[t];
    }
    

    return 0;
}
