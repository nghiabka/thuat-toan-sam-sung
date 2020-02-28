#include <iostream>

using namespace std;

int count =1;

void combinationK(int n, int m, int k){
    int a[m+1];
    for (int i = 1; i <=m; i++)
    {
        a[i] = i;
    }
    if (k ==1)
    {
        for (int i = 1; i <= m; i++)
                {
                    cout << a[i]<< " ";
                }
        return;   
    }
    
    int t = m;
    while (t >=1)
    {
        while (a[t] == n-m+t)
        {
            --t;
        }
        if (t <1)
        {
            cout << -1;
            break;
        }
        a[t] = a[t]+1;
        for (int i = t+1; i <= m; i++)
        {
            a[i] = a[t]+i-t;
        }
        count ++;
        if (count == k)
        {
            for (int i = t+1; i <= m; i++)
                {
                    cout << a[i]<< " ";
                }
            break;
        }
        
        t = m;
        
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int k; cin >> k;
    int m;
    cin >>m;
    combinationK(n, m, k);
    return 0;
}
