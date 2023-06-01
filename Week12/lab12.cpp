#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// funtion to print the answers
void printSolution(vector<int>& distance, vector<int>& parent, int V, int source) {
    
    cout << "Source city: " << source << endl;

    for (int i = 0; i < V; i++) {
        cout << "City: " << i << "\t\tDistance: " << distance[i];
        cout << endl;
    }
}

// function to find the vertex with minimum distance
int minDistance(vector<int>& distance, vector<bool>& shortestPathTree, int V) {
    
    int minDist = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!shortestPathTree[v] && distance[v] <= minDist) {
            minDist = distance[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Dijkstra's algorithm
void dijkstra(vector<vector<int>>& graph, int source) {
    
    int V = graph.size();
    vector<int> distance(V, INT_MAX); 
    vector<bool> shortestPathTree(V, false);
    vector<int> parent(V, -1); 

    distance[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distance, shortestPathTree, V);
        shortestPathTree[u] = true;

        for (int v = 0; v < V; v++) {
            if (!shortestPathTree[v] && graph[u][v] != -1 &&
                distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(distance, parent, V, source);
}

int main() {
    
    vector<vector<int>> graph = {
        {-1, 10, -1, -1, 15, 5},
        {10, -1, 10, 30, -1, -1},
        {-1, 10, -1, 12, 5, -1},
        {-1, 30, 12, -1, -1, 20},
        {15, -1, 5, -1, -1, -1},
        {5, -1, -1, 20, -1, -1}
    };

    int numVertices = graph.size();

    dijkstra(graph, 0);
    cout << endl;

    return 0;
}
