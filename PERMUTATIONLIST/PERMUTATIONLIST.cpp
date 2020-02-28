 
#include <cstdio> 
#include <cstdlib>
#include <iostream>
#include <algorithm>      // thu vien chua ham swap (hoan vi 2 so)
using namespace std;


int giaithua(int n){
    if (n ==1 || n ==0)
    {
        return 1;
    }else
    {
        return(n*giaithua(n-1));
    }
}
 
int main(int argc, char **argv)
{
    int n, *a, r;
    scanf("%d", &n);
    cin >> r;

    // if (r > giaithua(n)){
    //     cout << -1;
    //     return 0;
    // }else
    {
        
    
    
        
        a = new int[n];
        int count = 1;
        for (int i=0; i<n; i++)          // khoi tao va in ra cau hinh ban dau
        {
            a[i] = i+1;
            // printf("%d   ", a[i]);
        }   
        // printf("n");
        
        int i = n-1;        // i la vi tri ma doan cuoi giam dan
        while (i>0)          // trong khi doan cuoi khong phai bat dau tu vi tri dau tien
        {
            i = n-1;
            while (a[i] < a[i-1])    // tim vi tri dau tien ma doan cuoi giam dan
            {
                i--; 
            }
            
            if (i>0)     // Neu tim duoc i
            {
                int k;      // tim so a[k] nho nhat trong doan giam dan ma a[k] > a[i-1]
                for (k = n-1; k >= i; k--)       
                {
                    if (a[k] > a[i-1])       
                    {
                        break;
                    }
                    
                }
                swap(a[k], a[i-1]);     // hoan vi a[k] va a[i-1]
                
                // dao nguoc doan cuoi giam dan thanh tang dan
                for (int k = i; k < i + (n - i) / 2; k++)    
                {
                    swap(a[k], a[n - 1 - k + i]);
                }
                count ++;
                if (count > 1e9)
                {
                    cout << -1;
                    return -1;
                }
                
                if (count == r)
                {
                    for (int k = 0; k < n; k++)      // in hoan vi ra
                    {
                      cout << a[k] << " ";
                    }
                    cout << endl;
                }
            }
        }
        
        return 0; 
    }
}