#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


void nhap(string fileName, int n){
    ofstream of(fileName);
    for (int i = 0; i < n; i++)
    {
        float tmp;
        cin >> tmp;
        of << tmp << endl;
    }
    of.close();
}


int compare (const void * a, const void * b)
{
  return ( *(float*)a - *(float*)b );
}

// load du lieu
float * load_data(float *a, FILE * file, int n){
    // cout <<"ok" << endl;

    for (int i = 0; i < n; i++)
    {
        float tmp;
        fscanf(file, "%f", &tmp);
        a[i] = tmp;
    }
    return a;
}


void write_to_file(float * a,int n,  string fileName){
    ofstream of(fileName);
    for (int i = 0; i < n; i++)
    {
        of << a[i] << endl;
    }
    
}

// merge
void merge(string fileName1, string fileName2, int n1, int n2){
    char fileN1[fileName1.size() + 1];
	strcpy(fileN1, fileName1.c_str());

    char fileN2[fileName2.size() + 1];
	strcpy(fileN2, fileName2.c_str());

    FILE * f1 = fopen(fileN1, "r");
    FILE * f2 = fopen(fileN2, "r");

 
    int start1 =0;
    int start2 = 0;
    float a1;
    float a2;
    int flag = 0;
    fscanf(f1, "%f", &a1);
    fscanf(f2, "%f", &a2);

    while (start1 < n1 && start2 < n2)
    {
        if (a1 < a2)
        {
            printf("%0.2f ", a1);
            start1++;
            fscanf(f1, "%f", &a1);
            flag = 1;
 
        }else
        {
            printf("%0.2f ", a2);
            start2++;
            fscanf(f2, "%f", &a2);
            flag = 2;
        }
    }

    if (flag == 2)
    {
        printf("%0.2f ", a1);
        start1++;
    }
 
    if (flag == 1)
    {
        printf("%0.2f ", a2);
        start2++;
    }
    
    while (start2 < n2)
    {

        fscanf(f2, "%f", &a2);
        printf("%0.2f ", a2);
        start2 ++;
    }
 
    while (start1< n1)
    {
        fscanf(f1, "%f", &a1);
        printf("%0.2f ", a1);
        start1++;
    }
    fclose(f1);
    fclose(f2);
    
}

int main(int argc, char const *argv[])
{
    int n =10;
    cin >> n;
    string fileNameInput = "input.txt";
    nhap(fileNameInput, n);
    // read(fileNameInput, n); 
    int n1 = (int)(n/2);
    int n2 = n- n1;
    // 
    char fileName[] = "input.txt";
    FILE *file= fopen(fileName, "r");
    // set 1 mang luu 
    float *a = new float(n1 > n2? n1: n2);
    // load du lieu mangco do dai n1
    a =  load_data(a, file, n1);
    qsort (a, n1, sizeof(float), compare);
    write_to_file(a, n1, "out1.txt");

    a =  load_data(a, file, n2);
    qsort (a, n1, sizeof(float), compare);
    write_to_file(a, n1, "out2.txt");
    fclose(file);
    delete a;
    merge("out1.txt", "out2.txt", n1, n2);
  

    return 0;
}
