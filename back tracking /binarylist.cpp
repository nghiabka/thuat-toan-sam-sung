#include <iostream>

using namespace std;

int b[1000];

void backtracking(int start, int n){
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            b[i] = j;
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
