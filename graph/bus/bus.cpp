#include <iostream>
#include <vector>
#include <algorithm> // Hàm sort
#include <fstream>
using namespace std;

// Cấu trúc để lưu cạnh đồ thị,
// u, v là 2 đỉnh, w là trọng số cạnh
struct edge {
    int u, v, w;
};
// Hàm so sánh để dùng trong hàm sort ở dưới
bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}

// Số đỉnh tối đa trong đề bài
#define N 10005

// 2 mảng sử dụng trong Disjoint Set
int cha[N], hang[N];
vector<edge> edges(10000);

// Tìm xem u thuộc cây nào
int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

// Hợp nhất 2 cây chứ u và v,
// Trả về false nếu không thể hợp nhất
bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}

int main() {
    ifstream file_in("input.txt");
    // Thêm dòng này để cin, cout chạy nhanh
    ios::sync_with_stdio(false); cin.tie(0);

    // Nhập vào số đỉnh và số cạnh
    // int n, m; cin >> n >> m;
    int n, m, c;
    // file_in >> n;
    // file_in >> c ;
    // file_in >> m;
    cin >> n;
    cin >> c ;
    cin >> m;
    // Nhập danh sách các cạnh
    // for (edge &e: edges) cin >> e.u >> e.v >> e.w;
    for (int i = 0; i < c; i++)
    {
        // file_in >> edges[i].u;
        // file_in >> edges[i].v;
        cin >> edges[i].u;
        cin >> edges[i].v;
        edges[i].w =0;
    }
    int count = c;
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, w ;
    //     // file_in >> u;
    //     // file_in >> v;
    //     // file_in >> w;
    //     cin >> u;
    //     cin >> v;
    //     cin >> w;
        
    //     for (int j = 0; j < count ; j++)
    //     {
    //         if ((edges[j].u == u && edges[j].v == v ) || (edges[j].v == u && edges[j].u == v))
    //         {
    //             // cout << u << " " << v << " " << w << endl;
    //             break;
    //         }else
    //         {
    //             edges[count].u =u;
    //             edges[count].v =v;
    //             edges[count].w =w;
    //             count++;
    //         }      
    //     }
        
    // }
    int mang[n];
 
    int i;
    for(i = 0; i < n; i++)
    {
        mang[i] = 0;
    }
 
 
    // in ra cau hinh dau
    for(i = 0; i < n; i++)
    {
        printf("%d", mang[i]);
    }
    printf("\n");
 
 
    //xu ly
    for(i = n - 1; i >= 0; i--)
    {
        if(mang[i] == 0)  // neu gap phan tu 0 dau tien
        {
            mang[i] = 1;  // gan no lai thanh 1
 
            int j;
            for(j = i + 1; j < n; j++)  // gan toan bo phan tu phia sau no thanh 0
            {
                mang[j] = 0;
            }
 
            // in ra day so moi
            for(j = 0; j < n; j++)
            {
                if (mang[j] == 0)
                {
                    continue;
                }
                
                int u, v, w;
                cin >> u;
                cin >> v;
                cin >> w;
                edges[count].u =u;
                edges[count].v =v;
                edges[count].w =w;
            }
 
            i = n;  // gan i = n de khi het vong lap i-- nen i se = n - 1, tu do chay lai tu vi tri cuoi.
                    // gan i = n - 1 la sai vi khi het vong lap hien tai i-- se thanh n - 2.
        }
    }
    
    
    // Sắp xếp lại các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), cmp);

    // Khởi tạo cấu trúc Disjoint Set
    for (int i=1; i<=n; i++) {
        cha[i] = i;
        hang[i] = 0;
    }

    // Lưu tổng trọng số các cạnh trong cây khung nhỏ nhất
    int mst_weight = 0;

    // Duyệt qua các cạnh theo thứ tự đã sắp xếp
    for (edge &e: edges) {
        // Thử hợp nhất 2 cây chứa u và v
        if (join(e.u, e.v)) {
            // Hợp nhất thành công, ta thêm e và kết quả
            mst_weight += e.w;
        }
    }

    // Xuất kết quả
    cout << mst_weight;
    return 0;
}