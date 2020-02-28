/*
Cho một đồ thị vô hướng G = (V, E) trong đó V = {1, .., N}. Mỗi cạnh (u, v) E có trọng lượng w (u, v). Tính cây bao trùm tối thiểu của G.

Đầu vào
Dòng 1: N và M (1≤N, M≤105) trong đó N là số nút và M là số cạnh.
Dòng i + 1 (i = 1, Tầm, M): chứa 3 số nguyên dương u, v và w trong đó w là trọng số của cạnh (u, v)

Đầu ra
Viết trọng lượng của cây bao trùm tối thiểu được tìm thấy.

Giải pháp: sử dụng thuật toán Kruskal:
b1: Sắp xếp các cạnh trong tập cạnh E theo thứ tự tăng dần
b2: Khởi tạo cây T = {}; biến đếm cạnh i = 0;
b3: if (T + {ei} không tạo thành chu trình) then { T = T + {ei} }
b4: if T.size < n - 1 then { i++; quay lại bước 3 } else { kết thúc thuật toán }
b5: Tình tổng khối lượng các cạnh trong T
*/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100001

int m, c, n, u[MAX], v[MAX], r[MAX];
long long w[MAX];

void In();
void Pro();
void Sort(int i0, int j0);
int Root(int x);
void Merge(int u, int v);

int main()
{
    // freopen("in.txt", "r", stdin);
    In();
    Pro();
    return 0;
}

void In()
{
    cin >> n >> c >> m;
    for (int i = 1; i <= c; i++)
    {
        cin >> u[i] >> v[i];
        w[i] = 0;
    }
    for (int i = c + 1; i <= m + c; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
}

void Pro()
{
    Sort(1, m + c);
    memset(r, -1, sizeof(r));
    long long res = 0;
    int ru, rv;
    for (int i = 1; i <= m + c; i++)
    {
        ru = Root(u[i]);
        rv = Root(v[i]);
        if (ru != rv)
        {
            Merge(ru, rv);
            res += w[i];
        }
    }
    cout << res;
}

void Sort(int i0, int j0)
{
    if (i0 >= j0)
        return;
    int i = i0, j = j0, x = w[(i + j) / 2];
    do
    {
        while (w[i] < x)
            i++;
        while (w[j] > x)
            j--;
        if (i <= j)
        {
            swap(w[i], w[j]);
            swap(u[i], u[j]);
            swap(v[i], v[j]);
            i++;
            j--;
        }

    } while (i <= j);
    Sort(i0, j);
    Sort(i, j0);
}

int Root(int x)
{
    if (r[x] < 0)
        return x;
    else
    {
        r[x] = Root(r[x]);
        return r[x];
    }
}

void Merge(int u, int v)
{
    if (r[u] < r[v])
    {
        r[v] += r[u];
        r[u] = v;
    }
    else
    {
        r[u] += r[v];
        r[v] = u;
    }
}