#include <iostream>
// #include<stdio.h>

using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


int partion(float arr[], int low, int high){
    int pivot = high;
    int left = low;
    int right = high-1;
    while (true)
    {
        while( arr[left] < arr[pivot] && left <= right) left++;
        while (arr[right] > arr[pivot] && right >= left) right--;
        if(left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;    
    }
    swap(arr[left], arr[high]);  
    return left;    
}

void quickSort(float arr[], int low, int high){
    if(low < high){
        int pivot = partion(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}



int main(int argc, char const *argv[])
{
    int n;
    float arr[n];
    cin >> n;
    int mid = int(n/2);
    for (int  i = 0; i < mid; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }

    return 0;
}

