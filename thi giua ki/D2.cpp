#include <iostream>

using namespace std;

int getN(int s){
    int n =0;
    int count = 0;
    int buffer= -1;


    while (count != s)
    {
        n++;
        int tmp_n = n;
        while (1)
        {
            if (n < 10)
            {
                if(buffer != tmp_n){
                    count++;
                    if (count == s)
                    {
                        return tmp_n;
                    }
                    buffer = tmp_n;
                    break;
                }
            }
            
        }
        
        
    }
    
}


int main(int argc, char const *argv[])
{
    int s;
    cin >> s;

    return 0;
}
