#include <iostream>

using namespace std;

void hanoiTower(int n, char start, char spare, char end){
    if (n ==1)
    {
        cout <<"dich chuyen dia tu " << start << " sang dia " << end << endl;; 
    }else
    {
        hanoiTower(n-1, start, end, spare);
        hanoiTower(1,start, spare, end);
        hanoiTower(n-1, spare, start, end);
    }
    
    
}

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n;
    hanoiTower(n, 'A', 'B', 'C');
    return 0;
}
