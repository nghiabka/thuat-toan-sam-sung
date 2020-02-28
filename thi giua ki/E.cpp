#include <iostream>

using namespace std;


// void init(){

// }

int cost = 99999;
int tim(){

}



int main(int argc, char const *argv[])
{
    // so bac si
    int m; 
    cin >> m;
    int h_doctor[m];
    int salary_doctor[m];
    for (int i = 0; i < 2*m; i++)
    {
        if (i < m)
        {
            cin >> h_doctor[i];
        }
        else
        {
            cin >> salary_doctor[i];
        }
    }
    // so benh nhan
    int n;
    cin >>n;
    int h_benh_nhan[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h_benh_nhan[i];
    }
    
    return 0;
}
