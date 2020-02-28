#include <iostream>
using namespace std;
int x[100];

int U =0;
int M=0;
int n=0;
int k=0;
int L=0;


void display(){
    for (int i = 1; i <= k; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    
}

void UCV(int i){
    if (i==k)
    {
        U = n -M;
        L = U;
    }else
    {
        U = n-M-(k-i);
        L = 1;
    }
    for (int j = L; j <= U; j++)
    {
        x[i] = j;
        M = M+j;
        if (i == k)
        {
            display();
        }else
        {
            UCV(i+1);
        }
        
        M = M-j;
        
    }
    
    
}


int main(int argc, char const *argv[])
{
    cin >> n;
    cin >>k;
    UCV(1);

    return 0;
}
