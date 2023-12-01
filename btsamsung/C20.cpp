#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adjList;

    Graph(int ver) : V(ver), adjList(ver) {}

    void addEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    void primMST(vector<int>& subset) {
        set<pair<int, int>> edges;
        vector<bool> inMST(V, false);
        for (int u : subset) {
            for (const auto& i : adjList[u]) {
                int v = i.first;
                int weight = i.second;
                edges.insert({weight, v});
            }
        }

        int startVertex = subset[0];
        inMST[startVertex] = true;


        while (edges.size() > 0) {
            auto it = edges.begin();
            int weight = it->first;
            int u = it->second;
            edges.erase(it);

            if (!inMST[u]) {
                inMST[u] = true;
                cout << "Edge: " << u << " - " << u << " Weight: " << weight << "\n";

                for (const auto& i : adjList[u]) {
                    int v = i.first;
                    int neighborWeight = i.second;
                    if (!inMST[v]) {
                        edges.insert({neighborWeight, v});
                    }
                }
            }
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 6);


    vector<int> a = {0, 1, 2, 3, 4};

    g.primMST(a);

    return 0;
}

