#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    int V;
    vector<set<int>> adj;

public:
    Graph(int a) : V(a) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].insert(w);
        adj[w].insert(v);
    }

    int countEdge();

private:
    bool check(int v, int w);
};

int Graph::countEdge() {
    int count = 0;

    for (int i = 0; i < V; ++i) {
        for (int neighbor : adj[i]) {
            if (check(i, neighbor)) {
                ++count;
            }
        }
    }
    return count / 2;
}

bool Graph::check(int v, int w) {
    for (int i : adj[v]) {
        if (i != w && adj[w].find(i) != adj[w].end()) {
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

    int a = g.countEdge();

    cout << "Số cạnh song song trong đồ thị: " << a << endl;

    return 0;
}
