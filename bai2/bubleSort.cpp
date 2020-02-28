#include <iostream>

using namespace std;

void buble(float *a, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                float tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
            
        }
        
    }
    

}

int main(int argc, char const *argv[])
{
    float arr[100000];
    int n ;
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i];    
    }
    
    buble(arr,6 );
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    
    return 0;
}
