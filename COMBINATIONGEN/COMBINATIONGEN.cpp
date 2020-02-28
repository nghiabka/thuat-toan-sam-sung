#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = *a;    
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;
    cin >> m;
    // nhap cau hinh hien tai;
    int a[m+1];
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    int i = m;
    while (a[i] == n-m+i && i >=1)
    {
        i--;
    }
    if(i < 1){
        cout << -1;
        return -1;
    }

    a[i] = a[i]+1;
    for (int  j = i+1; j <=m; j++)
    {
        a[j] = a[i]+j-i;
    }
    
    for (int t = 1; t <= m; t++)
    {
        cout << a[t] << " ";
    }
    
    return 0;
}
