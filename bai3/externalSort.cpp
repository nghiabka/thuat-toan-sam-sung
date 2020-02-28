
#include <iostream>
#include <fstream>
#include<sstream>
#include <queue>
#include<algorithm>
using namespace std;
 
class Compare
{
public:
    //Ascending order sort
    bool operator() (pair<float, float> pair1, pair<float, float> pair2)
    {
        return pair1.first > pair2.first;
    }
};
 
string ToString(float val) {
    stringstream stream;
    stream << val;
    return stream.str();
}
 
//merge all sorted files into one
string mergeFiles(int counter) {
 
    string fileA, fileB;
 
    std::priority_queue<pair<float, float>, std::vector<pair<float, float> >, Compare> minHeap;
    ifstream* handles = new ifstream[counter];
 
    for (int i = 1; i <= counter; i++) {
        string sortedInputFileName = "output" + ToString(i) + ".txt";
        handles[i - 1].open(sortedInputFileName.c_str());
        float firstValue;
        handles[i - 1] >> firstValue; //first value in the file (minimum in the file)
        minHeap.push(pair<float, float>(firstValue, i - 1));   //second value in pair keeps track of the file from which the number was drawn
    }
 
    string outputFileName = "output.txt";
    ofstream outputFile(outputFileName.c_str());
 
    while (minHeap.size() > 0) {
        pair<float, int> minPair = minHeap.top();
        minHeap.pop();
        outputFile << minPair.first << '\n';
        float nextValue;
        flush(outputFile);
        if (handles[minPair.second] >> nextValue) {
            minHeap.push(pair <float, float>(nextValue, minPair.second));
        }
    }
 
    //clean up
    for (int i = 1; i <= counter; i++) {
        handles[i - 1].close();
    }
    outputFile.close();
    delete[] handles;//free memory
 
    return outputFileName;
}
 
void sortAndWrite(float *values, int size, int numberOfChunks) {
    sort(values, values + size);
    string outputFileName = "output" + ToString(numberOfChunks) + ".txt";
    ofstream outputFile(outputFileName.c_str()); //output file
    for (int i = 0; i < size; i++) {
        outputFile << values[i] << '\n';
    }
    outputFile.close();
}
 
int main() {
    //divide file into chunks of size that fits in your memory
    int n;
    cin >> n;
    ofstream ofile("input3.txt");
    for (int  i = 0; i < n; i++)
    {
        float tmp ;
        scanf("%f", &tmp);
        ofile << tmp << " ";
    }
    
    int numberOfChunks = 1;
    int maxSizeofMemory = 400;//in bytes
    int chunkSize = maxSizeofMemory / sizeof(float); //(4 bytes for integer)
    float* inputValues = new float[chunkSize];
    float readValue = 0;
    int currentCount = 0;
    bool unprocessedData = true;
    ifstream inputFile("input2.txt");
 
    while (inputFile >> readValue) {
        unprocessedData = true;
        inputValues[currentCount++] = readValue;
        if (currentCount == chunkSize) {
            sortAndWrite(inputValues, currentCount, numberOfChunks);
            numberOfChunks++;
            currentCount = 0;
            unprocessedData = false;
        }
    }
    if (unprocessedData) {
        sortAndWrite(inputValues, currentCount, numberOfChunks);
    }
    else {
        numberOfChunks--;
    }
 
    inputFile.close();
    delete[] inputValues; //free memory
    if (numberOfChunks != 0) {
        std::priority_queue<pair<float, float>, std::vector<pair<float, float> >, Compare> minHeap;
        cout << "output is in file : " << mergeFiles(numberOfChunks);
    }
 
    return 0;
}