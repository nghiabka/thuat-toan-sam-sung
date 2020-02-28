
#include <iostream>

using namespace std;


void swap(float *a, float *b){
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void combsort(float *a, int n){
    int gap = n;
    bool swapped = true;
    float shrink = 1.3;

    while (gap != 1 || swapped == true)
    {
        gap = (int)(gap/shrink);
        if (gap < 1)
        {
            gap =1;
        }
        
        swapped = false;
        for (int i = 0; i < n -gap; i++)
        {
            if(a[i] > a[i+gap]){
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }   
        
    }
    
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    float arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    combsort(arr, n);
    // display
    for (int i = 0; i < n; i++)
    {
        if (i < n-1)
        {
            printf("%0.2f ", arr[i]);
        }else
        {
            printf("%0.2f", arr[i]);
        }
        
        
    }
    return 0;
}
