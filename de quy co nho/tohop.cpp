#include<iostream>


using namespace std;


int D[100][100];

void init(int n, int k){
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == j)
            {
                D[i][j] = 1;
            }
            else if (j ==0)
            {
                D[i][j] = 1;
            }
            else
            {
                D[i][j] = 0;
            }
            
            
        }
        

    }
    
}

int C1(int n, int k){
    if(D[n][k] > 0){
        return D[n][k];
    }else
    {
        D[n][k] = C1(n-1, k-1)+ C1(n-1, k);
        return D[n][k];
    }
    
}


int main(int argc, char const *argv[])
{
    init(3, 2);
    cout << C1(3,2) << endl;
    
    return 0;
}
