#include <iostream>

using namespace std;


int gcd(int a, int b) {
  if (a <b ) return a;
  return gcd(b, a % b);
}


int addmod(int a, int b){
    int c = 1000000007;
    int mod1 = a%c;
    int mod2 = b%c;
    int mod3 = (mod1 + mod2)%c;
    return mod3;
}

int mulmod(int a, int b){
    int c = 1000000007;
    int mod1 = a%c;
    for (int  i = 0; i < b-1; i++)
    {
        mod1 *= mod1;
    }
    int mod2 = mod1%c;
    return mod2;   
}

int main(int argc, char const *argv[])
{
    int a;
    int b;
    cin >> a; 
    cin >> b;
    cout << mulmod(a, b);
    return 0;
}
