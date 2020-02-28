#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


void swap(float &a, float &b){
    float tmp =a;
    a = b;
    b = tmp;
}

int compare(const void* a, const void* b)
{
	const float* x = (float*) a;
	const float* y = (float*) b;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

void write_to_file(float *a, int n, string fileName){
    ofstream ofile(fileName);
    ofile << n << "\n";
    for (int  i = 0; i < n; i++)
    {
        ofile << a[i] << "\n";
    }
    ofile.close();
}

// merge
void merge(string fileName1, string fileName2){
    ifstream fileIn1(fileName1);
    ifstream fileIn2(fileName2);
    int n1;
    int n2;
    fileIn1 >> n1;
    // cout << n1;
    fileIn2 >> n2;
    // cout << n2;

    int start1 =0;
    int start2 = 0;
    float a1;
    float a2;
    int flag = 0;
    fileIn1 >> a1;
    fileIn2 >> a2;

    while (start1 < n1 && start2 < n2)
    {
        
        // string line1;
        // string line2;
        // getline(fileIn1, line1);
        // getline(fileIn2, line2);
        // cout << line1 << endl;
        if (a1 < a2)
        {
            printf("%0.2f ", a1);
            // printf("%0.2f ", a2);
            start1++;
            fileIn1 >> a1;
            flag = 1;

        }else
        {
            printf("%0.2f ", a2);
            // printf("%0.2f ", a1);
            start2++;
            fileIn2 >> a2;
            flag = 2;
        }
        // cout << start1 << " " << start2 << endl;
    }
    // printf("ok");
    // cout << endl;
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
        float tmp ;
        fileIn2 >> tmp;
        cout << tmp;
        printf("%0.2f ",tmp);
        start2 ++;
    }

    while (start1< n1)
    {
        float tmp ;
        fileIn1 >> tmp;
        printf("%0.2f ",tmp);
        start1++;
    }
    
    
}

int main(int argc, char const *argv[])
{
    int n;
    ofstream fileIn("input.txt");
    // fileIn >> n;
    cin >> n;
    // cout << n << endl;
    float tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        fileIn << tmp;
    }
    int n1 = int(n/2);
    int n2 = n-n1;
   
    
    // cap phat bo nho
    float *arr;
    if(n1 > n2){
        arr = new float[n1];
    }else
    {
        arr = new float[n2];
    }
    // xu ly mang co do dai n1
    for (int  i = 0; i < n1; i++)
    {
        // fileIn >> arr[i];
        scanf("%f", &arr[i]);
    }
    // sort
	qsort(arr,n1,sizeof(float),compare);
    // wirte to file
    write_to_file(arr, n1, "./out1.txt");

    // xu ly mang co do dai n1
    for (int  i = 0; i < n2; i++)
    {
        // fileIn >> arr[i];
        scanf("%f", &arr[i]);

    }
    // sort
    qsort(arr, n2, sizeof(float), compare);
    // wirte to file
    write_to_file(arr, n2, "./out2.txt");
    delete[] arr;

    merge("out1.txt", "out2.txt");
    return 0;
}
