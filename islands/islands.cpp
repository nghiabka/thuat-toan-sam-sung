#include <iostream>
#include <fstream>

using namespace std;

int islandCounter[1000000];
int detectIsland(int **a, int row, int col, int r, int c){
    if (r >= row || c >= col  || r < 0|| c <0)
    {
        return 0;
    }
    if(a[r][c] == 0){
        return 0;
    }else
    {
        a[r][c] =0;
        
        return 1 + detectIsland(a, row,  col, r-1, c-1)+
                    detectIsland(a, row, col, r-1, c)+
                    detectIsland(a, row, col, r-1, c+1)+
                    detectIsland(a, row, col, r, c-1)+
                    detectIsland(a, row, col, r, c+1)+
                    detectIsland(a, row, col, r+1, c-1)+
                    detectIsland(a, row, col, r+1, c+1)+
                    detectIsland(a, row, col, r+1, c);

    }
    
    
}

int isLands(int **a, int n ,int m){
    int isLandsNumber = 0;
    int size;
    int max = 0;
    for (int i = 0; i < m*n; i++)
    {
        islandCounter[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            size = detectIsland(a, n, m, i, j);
            // cout << size << " ";
            if (size)
            {
                isLandsNumber ++;
                max = max > size?max:size;
            }   
        }
    }
    cout << isLandsNumber << endl;
    cout << max << endl;
}


int main(int argc, char const *argv[])
{
    // ifstream fi("input.txt");
    int row, col;
    // fi >>row;
    // fi >> col;
    cin >> row;
    cin >> col;

    int **arr;
    arr = new  int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    for (int  i = 0; i < row; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < col; j++)
        {
            char tmp;
            tmp = s[j];
            // fi >> tmp;
            // cin >> tmp;
            arr[i][j] =  tmp=='0'?0:1;
        }
    }    
    isLands(arr, row, col);
    for (int i = 0; i < row; i++)
    {
        
        delete[] arr[i];
        
    }
    delete[] arr;
    return 0;
}
