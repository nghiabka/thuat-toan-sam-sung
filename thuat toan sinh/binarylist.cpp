#include <iostream>

using namespace std;

void generate(int n){
    int a [n];
    // khoi tao cau hinh ban dau
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    // hien thi cau hinh ban dau
    for (int  j = 0; j < n; j++)
        {
            cout << a[j] << " " ;
        }
    cout << endl;
    
    bool stop = false;
    int i = n-1;
    while (!stop)
    {
        while (a[i] != 0)
        {
            --i;
        }
        // neu da liet ke het
        if (i < 0)
        {
            stop = true;
            continue;
        }
        // sinh cau hinh ke tiep
        a[i] = 1;
        for (int  j = i+1; j < n; j++)
        {
            a[j] = 0;
        }
        // hien thi

        for (int  j = 0; j < n; j++)
        {
            cout << a[j] << " " ;
        }
        // gan lai i
        i = n-1;
        cout << endl;
    }
    
    
}

int main(int argc, char const *argv[])
{
    int  n = 3;
    generate(n);
    return 0;
}
