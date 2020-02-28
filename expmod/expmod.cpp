#include <iostream>
using namespace std;
 
const int M = 1e9 + 7;
 
long long int powxy(long long int x, long long int y)
{
    if (y == 0)
        return 1;
    if (y & 1)
        cout << y << endl;
        return (x * powxy(x, y - 1)) % M;
    long long int t = powxy(x, y / 2);
    return (t * t) % M;
}
 
long long int pow(long long int x, long long int y)
{
    if (y ==0)
    {
        return 1;
    }
    if (y&1)
    {
        cout << y << endl;
        return (x*pow(x, y-1));
    }
    long long int t = pow(x, y/2);
    return (t*t);

}
 
int main()
{
    // (a + b) % M = ((a % m) + (b % m) % m)
    // long long int a, b;
    // cin >> a; cin >> b;
    // long long int res1 = powxy(a, b);
    // a = 1234;
    // cout << (a&1);
    cout << pow(5, 3);
    return 0;
}