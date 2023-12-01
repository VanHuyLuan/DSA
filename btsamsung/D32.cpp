
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

class Graph {
public:
    int V;
    vector<vector<int>> a;

    Graph(int ver) : V(ver), a(ver, vector<int>(ver, INF)) {}

    void addEdge(int u, int v, int weight) {
        a[u][v] = weight;
        a[v][u] = weight;
    }

    void prepoGr() {
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }

    int shortestDistance(int u, int v) {
        return a[u][v];
    }
};

int main() {
    int ver = 5;
    Graph g(ver);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);
    g.addEdge(4, 0, 50);

    g.prepoGr();

    int u = 1, v = 3;
    int a = g.shortestDistance(u, v);

    cout << "Shortest distance between " << u << " and " << v << ": " << a << "\n";

    return 0;
}
