#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    int V;
    vector<set<int>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].insert(w);
        adj[w].insert(v);
    }

    bool Connected();

private:
    void DFS(int v, vector<bool>& visited, set<int>& cutEdges);
    bool isBridge(int u, int v);
};

bool Graph::Connected() {
    if (V < 2) {
        return true;
    }

    set<int> cutEdges;

    vector<bool>a(V, false);
    DFS(0, a, cutEdges);

    return cutEdges.empty();
}

void Graph::DFS(int v, vector<bool>& visited, set<int>& cutEdges) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            DFS(i, visited, cutEdges);
        } else if (v < i && !cutEdges.count(v * V + i)) {
            cutEdges.insert(v * V + i);
            cutEdges.insert(i * V + v);
        }
    }
}

int main() {
    Graph g(100);

    //g.addEdge(0, 1);
    //g.addEdge(1, 2);
    //g.addEdge(2, 3);
    //g.addEdge(3, 0);
    //g.addEdge(2, 4);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        g.addEdge(x , y);
    }

    if (g.Connected()) {
        cout << "Đồ thị có tính chất liên thông cạnh.\n";
    } else {
        cout << "Đồ thị không có tính chất liên thông cạnh.\n";
    }

    return 0;
}
