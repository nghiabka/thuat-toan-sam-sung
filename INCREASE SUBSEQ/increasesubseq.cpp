#include<iostream>

using namespace std;


int subseq(int *a, int n){
    int list[n];
    list[0] = 1;
    for (int i = 1; i < n; i++)
    {
        list[i] = 1;
        for (int  j = 0; j < i; j++)
        {
            if (a[i] >= a[j] && list[i] <= list[j]+1)
            {
                list[i] = list[j] +1;
            }
        }
    }
    int max = list[0];
    for (int i = 0; i < n; i++)
    {
        max = max>list[i]?max:list[i];
    }
    return max;
}

int lis(int arr[], int n) 
{ 
    int *lis, i, j, max = 0; 
    lis = (int*)malloc(sizeof(int) * n); 
  
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++) 
        lis[i] = 1; 
  
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++) 
        for (j = 0; j < i; j++) 
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) 
                lis[i] = lis[j] + 1; 
  
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++) 
        if (max < lis[i]) 
            max = lis[i]; 
  
    /* Free memory to avoid memory leak */
    free(lis); 
  
    return max; 
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n <0)
    {
        return -1;
    }
    
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << lis(a, n);
    return 0;
}
