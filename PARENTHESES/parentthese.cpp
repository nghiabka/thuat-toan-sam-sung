#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int check(string a){
    stack<char> mystack;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '{' || a[i] == '[' || a[i] == '(')
        {
            mystack.push(char(a[i]));
        }else
        {
            char c = mystack.top();
            if ((a[i] == '}' && c== '{')|| (a[i] == ']' && c == '[')|| (a[i] == ')' && c == '(')){
                mystack.pop();
                continue;
            }else
            {
                return 0;
            }
        }
    }
    if (mystack.empty())
    {
        return 1;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    // string fileName;
    // cin >> fileName;
    // ifstream fileIn(fileName);
    int n ;
    // fileIn >>n;
    cin >> n;
    int result[n];
    // cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        string a;
        // fileIn >> a;
        cin >> a;
        int tmp_result = check(a);
        result[i] = tmp_result;
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
