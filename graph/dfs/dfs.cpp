#include <iostream>
#include <list>

using namespace std;


class Graph{
    int V; // no of vertices
    //pointer to an array containg list adjacency list
    list<int>  *adj;

    // a recusive function used by DFS
    void DFSUtil(int v, bool visited[]);

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void DFS(int v)

}