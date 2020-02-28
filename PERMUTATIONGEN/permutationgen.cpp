#include <iostream>

using namespace std;


void swap(int *a , int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int  next_permutation(int *a, int n){
    // tim chi so lon nhat a[j] < a[j+1]
    int j = n-2;
    while(a[j] > a[j+1]) j--;
    // tim a[k] nho nhat ma lon hon a[j]
    int k = n-1;
    while(a[j] > a[k]) k--;
    swap(a[j], a[k]);
    int r = n-1;
    int s = j+1;
    while(r>s){
        swap(a[r], a[s]);
        r--;
        s++;
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin >>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // check
    int count = 0;
    for (int  i = 0; i < n-1; i++)
    {
        
        if (a[i] >= a[i+1])
        {
            count++;
        }
        else
        {
            break;
        }
        
    }
    if (count == n-1)
    {
        cout << -1;
        return 0;
    }else
    {
         // sinh cau hinh ke tiep
        next_permutation(a, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        
        
        return 0;
    }
   
}
