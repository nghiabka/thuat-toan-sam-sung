#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >>n;
    char a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i];
    // }
    int i = n-1;
    while (a[i] == '1' && i >=0)
    {
        a[i] = '0';
        --i;
    }
    a[i] = '1';
    if (i < 0)
    {
        cout << -1;
        return 0;
    }
    for (int j = 0; j < n; j++)
    {
        cout << a[j];
    }
    
    return 0;
}
