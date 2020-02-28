#include <iostream>

using namespace std;

void readFromFile(FILE *file)
{
    char buffer[6]; 
	while (!feof(file)) // to read file 
    { 
        // fucntion used to read the contents of file 
        fread(buffer, sizeof(buffer), 1, file); 
        cout << buffer << endl; 
    } 
}

int main(int argc, char const *argv[])
{
    const char *filePath = "input.txt";
	FILE *file;

	file = fopen(filePath, "rb"); //use binary mode
    readFromFile(file);
    return 0;
}
