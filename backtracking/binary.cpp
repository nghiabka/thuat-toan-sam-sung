#include <iostream>

using namespace std;


int b[100];
int n;

void ghi_nhan(){
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] ;
    }
    cout << endl;
}


void gen(int i){
    int j;
    for (int j = 0; j <= 1; j++)
    {
        b[i] = j;
        if (i == n)
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
    cin >>n;
    gen(1);
    return 0;
}
