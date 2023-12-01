#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adj;

public:
    Graph(int a) : V(a) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool EulerCycle();
    bool HamiltonCycle();

private:
    void DFS(int v, vector<bool>& visited);
    int countEdges(int v);
    bool isCyclicConnected();
    bool isCyclicUtil(int v, vector<bool>& visited, int parent);
};

bool Graph::EulerCycle() {
    for (int i = 0; i < V; i++) {
        if (countEdges(i) % 2 != 0) {
            return false;
        }
    }
    return true;
}

bool Graph::HamiltonCycle() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        visited.assign(V, false);
        if (isCyclicUtil(i, visited, -1)) {
            return true;
        }
    }

    return false;
}

int Graph::countEdges(int v) {
    return adj[v].size();
}

void Graph::DFS(int v, vector<bool>& visited) {
    visited[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited);
        }
    }
}

bool Graph::isCyclicConnected() {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, -1)) {
                return true;
            }
        }
    }

    return false;
}

bool Graph::isCyclicUtil(int v, vector<bool>& visited, int parent) {
    visited[v] = true;

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            if (isCyclicUtil(neighbor, visited, v)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    Graph g(100);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        g.addEdge(x , y);
    }

    if (g.EulerCycle()) {
        cout << "Do Thi Co chu trinh Euler.\n";
    } else {
        cout << "Do Thi khong Co chu trinh Euler.\n";
    }

    if (g.HamiltonCycle()) {
        cout << "Do Thi Co chu trinh Hamilton.\n";
    } else {
        cout << "Do Thi khong Co chu trinh Hamilton.\n";
    }

    return 0;
}
