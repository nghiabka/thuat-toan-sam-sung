#include <iostream>


using namespace std;



int maxsumseq(int *a, int n){
    int smax = a[0];
    int ei = a[1];
    for (int i = 2; i < n; i++)
    {
        ei = a[i] > (a[i]+ei)? a[i]:(a[i]+ei);
        smax = smax > ei? smax:ei;
    }
    return smax;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxsumseq(a, n);
    return 0;
}
