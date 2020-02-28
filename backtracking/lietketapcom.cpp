#include <iostream>
using namespace std;

int m,n;
int b[100];

void ghi_nhan(){
    for (int i = 1; i <= m; i++)
    {
        cout << b[i] ;
    }
    cout << endl;
}


void gen(int i){
    for (int j = b[i-1] +1; j <= n-m + i; j++)
    {
        b[i] = j;
        if (i == m)
        {
            ghi_nhan();
        }else
        {
            gen(i+1);
        }
            
    }
    
}

int main(int argc, char const *argv[])
{
    cin >> n;
    cin >> m;
    b[0] = 0;
    gen(1);
    return 0;
}
