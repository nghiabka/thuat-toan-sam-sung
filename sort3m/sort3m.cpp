#include <iostream>
#include <algorithm>
 
using namespace std;
 
const long MAX_SIZE = 500007;
float a[MAX_SIZE];
 
int main()
{
    int i, j, n;
    cin >> n;
 
    if (n < MAX_SIZE)
    {
        for (i = 0; i < n; scanf("%f", &a[i++]));
        sort(a, a + n);
        for (i = 0; i < n; printf("%.2f ", a[i++]));
        return 0;
    }
 
    FILE *file;
    char fileName[] = "temp.txt";
    file = fopen(fileName, "wb");
 
    // Sort and write file
    for (i = 0; i < MAX_SIZE; scanf("%f", &a[i++]));
    sort(a, a + MAX_SIZE);
    fwrite(a, sizeof(float), MAX_SIZE, file);
    fclose(file);
 
    n -= MAX_SIZE;
 
    for (i = 0; i < n; scanf("%f", &a[i++]));
    sort(a, a + n);
 
    float temp;
    file = fopen(fileName, "rb");
    i = 0, j = 0;
    fread(&temp, sizeof(float), 1, file);
    while (i < n || j < MAX_SIZE)
    {
        if (i == n)
        {
            printf("%.2f ", temp);
            fread(&temp, sizeof(float), 1, file);
            j++;
        }
        else if (j == MAX_SIZE)
        {
            printf("%.2f ", a[i]);
            i++;
        }
        else if (temp < a[i])
        {
            printf("%.2f ", temp);
            fread(&temp, sizeof(float), 1, file);
            j++;
        }
        else
        {
            printf("%.2f ", a[i]);
            i++;
        }
    }
    fclose(file);
    return 0;
}