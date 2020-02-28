#include <iostream>


using namespace std; 

bool check = false;
int count  =0;

void display(char *a,int n){  // hiển thị cấu hình ra màn hình
 for (int i = 0; i < n; i++){
  cout << a[i] << " ";
 }
 cout << endl;
}

int check_i(char *a, int n, int c){
    for (int  i = 0; i < n-c; i++)
    {
        int flag =0;

        for (int j = 0; j < c; j++)
        {

            if (a[i+j] != '0')
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            continue;
        }
        if (flag == 0)
        {
            return -1;
        }
    }
    return 1;
}

void gen(char *a, int n,int k,  int c){
    int i = n;
    while (a[i] == '1' && i >=0)
    {
        i--;
    }
    if (i < 0)
    {
        check = true; // da duyet het day
    }
    else
    {
        a[i] = '1';
        for (int  j = i+1; j < n; j++)
        {
            a[j] = '0';
        }
        if (check_i(a, n, c))
        {
            count ++;
            if (count == k)
            {
                display(a, n);

            }
            
            // cout << endl;
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int n , k, c;
    cin >> n; 
    cin >> k; 
    cin >> c;
    char *a;
    a = new char[n];
    for (int  i = 0; i < n; i++)
    {
        a[i] ='0';
    }
    display(a, n);

    while (!check)
    {
        gen(a, n, k, c);
        // display(a, n);
    }
    cout << check_i(a, n, 2);
    
    return 0;
}
