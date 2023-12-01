#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

class Graph {
public:
    int V;
    vector<vector<pair<int, int>>> adjList;

    Graph(int ver) : V(ver), adjList(ver) {}

    void addEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    int minKey(const vector<int>& key, const vector<bool>& inMST) {
        int min = INF, minIndex = -1;

        for (int v = 0; v < V; ++v) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }

    void primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);

        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = minKey(key, inMST);

            inMST[u] = true;

            for (const auto& i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (!inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        for (int i = 1; i < V; ++i)
            cout << "Edge: " << i << " - " << parent[i] << " Weight: " << key[i] << "\n";
    }
};

int main() {
    Graph g(100);

   // g.addEdge(0, 1, 2);
   // g.addEdge(0, 3, 8);
   // g.addEdge(1, 2, 3);
    //g.addEdge(1, 3, 5);
    //g.addEdge(1, 4, 1);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y ,w;
        cin >> x >> y >> w;
        g.addEdge(x , y , w);
    }
    g.primMST();

    return 0;
}
