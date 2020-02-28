#include <iostream>

using namespace std;


void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


int partion(int arr[], int low, int high){
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

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partion(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}




int main(int argc, const char** argv) {
    int arr[] = {2, 1, 5, 7, 99, 10};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " "; 
    }

    return 0;
}