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

    void unionSets(vector<int>& parent, int x, int y) {
        int X = findParent(parent, x);
        int Y = findParent(parent, y);
        parent[X] = Y;
    }

    void kruskalMST() {
        vector<int> parent(V, -1);
        vector<pair<int, pair<int, int>>> result;

        sort(edges.begin(), edges.end(), greater<pair<int, pair<int, int>>>());

        for (const auto& i : edges) {
            int weight = i.first;
            int u = i.second.first;
            int v = i.second.second;

            int u1 = findParent(parent, u);
            int v1 = findParent(parent, v);

            if (u1 != v1) {
                result.push_back({weight, {u, v}});
                unionSets(parent, u1, v1);
            } else {
                result.pop_back();
            }
        }

        for (const auto& i : result)
            cout << "Edge: " << i.second.first << " - " << i.second.second << " Weight: " << i.first << "\n";
    }
};

int main() {
    Graph g(100);

    //g.addEdge(0, 1, 2);
    //g.addEdge(0, 3, 8);
    //g.addEdge(1, 2, 3);
   // g.addEdge(1, 3, 5);
   // g.addEdge(1, 4, 1);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y ,w;
        cin >> x >> y >> w;
        g.addEdge(x , y , w);
    }
    g.kruskalMST();

    return 0;
}

