#include <iostream>
#include<stdio.h>

using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


//  finde gap between elements
int getNextGap(int gap) 
{ 
    gap = (gap*10)/13; 
  
    if (gap < 1) 
        return 1; 
    return gap; 
}

void combSort(float *a, int n){
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped == true) 
    { 
        // Find next gap 
        gap = getNextGap(gap); 
  
        // Initialize swapped as false so that we can 
        // check if swap happened or not 
        swapped = false; 
  
        // Compare all elements with current gap 
        for (int i=0; i<n-gap; i++) 
        { 
            if (a[i] > a[i+gap]) 
            { 
                swap(a[i], a[i+gap]); 
                swapped = true; 
            } 
        } 
    } 

}

int main() 
{ 
     int n ;
     cin >> n;
     float a[1000000];
     
     for (int i = 0; i < n; i++)
     {
         cin>> a[i];
     }
      

    combSort(a, n); 
  
    for (int i=0; i<n; i++) 
        printf("%0.2f ", a[i]); 
  
    return 0; 
} 