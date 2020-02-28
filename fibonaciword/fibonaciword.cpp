#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void fibWord(int n) 
{ 
    ofstream ofN_1("sn_1.txt");
    ofstream ofN("sn.txt");
    ofN_1 << '0';
    ofN << '1';
    ofN.close();
    ofN_1.close(); 
    // return;
    for (int i=2; i<=n; i++) 
    { 
        // file tmp chiu trach nhiem luu tam N
        ofstream tmp("tmp.txt");
        ifstream fN_in("sn.txt");
        ifstream fn_1("sn_1.txt");
        // copy fn sang tmp255
        while (!fN_in.eof())
        {
            char line[255];
		    fN_in.getline(line, 255);
            tmp << line;
        }
        tmp.close();
        fN_in.close();

        // cong fn-1 voi fn
        ofstream fN_out("sn.txt", ios::app);
        while (!fn_1.eof())
        {
            char line[255];
            fn_1.getline(line, 255);
            fN_out << line;
        }
        fN_out.close();
        // 
        ofstream fn_1_out("sn_1.txt");
        ifstream tmp_in("tmp.txt");
        while (!tmp_in.eof())
        {
            char line[255];
            tmp_in.getline(line, 255);
            fn_1_out << line;
        }
        fn_1_out.close();
        tmp_in.close();

    } 
  
    // return Sn; 
}

int countP(char *fileName, string pattern){
    int buffer_size = 2;
    FILE * file = fopen(fileName, "r");
    int count = 0;
}


int main(int argc, char const *argv[])
{

    int n;
    cin >> n; 
    string p;
    cin >>p;
    fibWord(n);
    // cout << p.length() << endl;
    char *fileName = "sn.txt";
    // cout << countP(fileName, p);
    return 0;
}
