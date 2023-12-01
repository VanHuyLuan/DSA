#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

class Dijkstra {
public:
    int V;
    vector<vector<pair<int, int>>> adjList;
    vector<int> sources;

    Dijkstra(int vertices, const vector<int>& src) : V(vertices + 1), adjList(V), sources(src) {
        initializeGraph();
    }

    void addEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
    }

    void initializeGraph() {
        int au = V - 1;

        for (int i : sources) {
            addEdge(au, i, 0);
        }
    }

    vector<int> dijkstrashort(int k) {
        vector<int> dist(V, numeric_limits<int>::max());
        dist[k] = 0;

        set<pair<int, int>> vertices;
        vertices.insert({0, k});

        while (!vertices.empty()) {
            int u = vertices.begin()->second;
            vertices.erase(vertices.begin());

            for (const auto& i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[u] + weight < dist[v]) {
                    vertices.erase({dist[v], v});
                    dist[v] = dist[u] + weight;
                    vertices.insert({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<int> getshort() {
        vector<int> b(V - 1, numeric_limits<int>::max());

        for (int source : sources) {
            vector<int> dist = dijkstrashort(source);

            for (int i = 0; i < V - 1; ++i) {
                b[i] = min(b[i], dist[i]);
            }
        }

        return b;
    }
};

int main() {
    int ver = 5;
    vector<int> b = {0, 2};  // Đỉnh nguồn

    Dijkstra a(ver, b);

    a.addEdge(0, 1, 10);
    a.addEdge(0, 3, 5);
    a.addEdge(1, 2, 1);
    a.addEdge(2, 3, 2);
    a.addEdge(3, 1, 3);
    a.addEdge(3, 4, 2);
    a.addEdge(4, 0, 7);

    vector<int> shortestPaths = a.getshort();

    for (int i = 0; i < shortestPaths.size(); ++i) {
        cout << "Source " << b[i] << " to Vertex " << i << ": " << shortestPaths[i] << "\n";
    }

    return 0;
}
