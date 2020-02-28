#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef pair<int, int> iPair;
#define INF 0x3f3f3f

int main()
{
    freopen("test.txt", "r", stdin);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> a;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a.push(num);
    }

    double answer;
    while (a.size() > 1)
    {
        int s1 = a.top();
        a.pop();
        int s2 = a.top();
        a.pop();
        answer += double(s1 + s2) / 20;
        a.push(s1 + s2);
    }

    printf("%.2f", answer);
}