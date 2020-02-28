#include<iostream>

using namespace std;

void sinh(int n, int m){
    // khoi tao cau hinh ban dau
    int a[m+1];
    for (int i = 1; i <= m; i++)
    {
        a[i] = i;
    }
        // hien thi cau hinh
    for (int  j = 1; j <= m; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;  
    //  sinh cau hinh ke tiep 
    int i = m;
    while (i>=1)
    {
        while (a[i] == n-m +i && i >=1)
        {
            i--;
        }
        //  da sinh het cau hinhf
        if (i < 1)
        {
            break;
        }

        // sinh cau hinh ke tiep
        a[i] = a[i]+1;
        for (int j = i+1; j <=m; j++)
        {
            a[j] = a[i]+j-i;
        }
        i = m;
        // hien thi cau hinh
        for (int  j = 1; j <= m; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;  
        
    }   
}

int main(int argc, char const *argv[])
{
    int n = 4;
    int m = 3;
    sinh(n, m);
    return 0;
}
