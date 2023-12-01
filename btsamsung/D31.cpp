
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;

    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int ver) : V(ver) {}

    void addEdge(int src, int dest, int weight) {
        edges.emplace_back(src, dest, weight);
    }

    void bellmanFord(int source, vector<int>& pi) {
        pi.assign(V, numeric_limits<int>::max());
        pi[source] = 0;

        for (int i = 1; i < V; ++i) {
            for (const auto& j : edges) {
                int u = j.src;
                int v = j.dest;
                int weight = j.weight;

                if (pi[u] != numeric_limits<int>::max() && pi[u] - pi[v] + weight < 0) {
                    pi[v] = pi[u] + weight;
                }
            }
        }
    }

    void reweightGraph(vector<int>& pi) {
        for (auto& i : edges) {
            if (pi[i.src] != numeric_limits<int>::max()) {
                i.weight = i.weight + pi[i.src] - pi[i.dest];
            }
        }
    }
};

int main() {
    int ver = 5;
    Graph g(ver);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    int n = 0;
    vector<int> pi;
    g.bellmanFord(n, pi);

    for (int i = 0; i < ver; ++i) {
        cout << "pi[" << i << "] = " << pi[i] << "\n";
    }

    g.reweightGraph(pi);
    return 0;
}
