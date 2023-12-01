#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    void boruvkaMST() {
        vector<int> parent(V, -1);
        vector<int> cheapest(V, -1);

        while (true) {
            vector<int> a(V, -1);

            for (const auto& i : edges) {
                int u = i.second.first;
                int v = i.second.second;

                int u1 = findParent(parent, u);
                int v1 = findParent(parent, v);

                if (u1 != v1) {
                    if (a[u1] == -1 || i.first < edges[a[u1]].first)
                        a[u1] = i.second.second;

                    if (a[v1] == -1 || i.first < edges[a[v1]].first)
                        a[v1] = i.second.first;
                }
            }

            int numTrees = 0;
            for (int i = 0; i < V; ++i) {
                if (a[i] != -1) {
                    int u1 = findParent(parent, i);
                    int v1 = findParent(parent, a[i]);

                    if (u1 != v1) {
                        cout << "Edge: " << i << " - " << a[i] << " Weight: " << edges[i].first << "\n";
                        check(parent, u1, v1);
                        ++numTrees;
                        cheapest[u1] = i;
                    }
                }
            }

            if (numTrees <= 1)
                break;
        }
    }

    int findParent(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    void check(vector<int>& parent, int x, int y) {
        int X = findParent(parent, x);
        int Y = findParent(parent, y);
        parent[X] = Y;
    }
};

int main() {
    Graph g(100);

   // g.addEdge(0, 1, 2);
   // g.addEdge(0, 3, 8);
   // g.addEdge(1, 2, 3);
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
    g.boruvkaMST();

    return 0;
}

