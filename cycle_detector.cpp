#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    bool dfs(int node, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, recStack))
                    return true;
            } else if (recStack[neighbor]) {
                return true; // back edge found (cycle)
            }
        }

        recStack[node] = false;
        return false;
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool hasCycle() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, recStack))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(6);

    // You can change this graph to test
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    // Uncomment the line below to create a cycle
    // g.addEdge(5, 2);

    if (g.hasCycle())
        cout << "Cycle detected in the graph!" << endl;
    else
        cout << "No cycle in the graph." << endl;

    return 0;
}
