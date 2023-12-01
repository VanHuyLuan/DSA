#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int ver) : V(ver) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int findParent(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    void check(vector<int>& parent, int x, int y) {
        int rootX = findParent(parent, x);
        int rootY = findParent(parent, y);
        parent[rootX] = rootY;
    }

    void kruskalMST() {
        vector<int> parent(V, -1);
        vector<pair<int, pair<int, int>>> result;

        sort(edges.begin(), edges.end());

        for (const auto& i : edges) {
            int weight = i.first;
            int u = i.second.first;
            int v = i.second.second;

            int setU = findParent(parent, u);
            int setV = findParent(parent, v);

            if (setU != setV) {
                result.push_back({weight, {u, v}});
                check(parent, setU, setV);
            }
        }

        cout << "Edges in Minimum Spanning Tree using Kruskal's Algorithm:\n";
        for (const auto& i : result)
            cout << "Edge: " << i.second.first << " - " << i.second.second << " Weight: " << i.first << "\n";
    }
};

int main() {
    Graph g(100);

  //  g.addEdge(0, 1, 2);
  //  g.addEdge(0, 3, 8);
  //  g.addEdge(1, 2, 3);
  //  g.addEdge(1, 3, 5);
    //g.addEdge(1, 4, 1);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y , w;
        cin >> x >> y >> w;
        g.addEdge(x , y , w);
    }
    g.kruskalMST();

    return 0;
}

