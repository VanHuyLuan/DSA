#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

struct Edge {
    int dest, weight;

    Edge(int d, int w) : dest(d), weight(w) {}
};

class Graph {
public:
    int V;  // Số đỉnh
    vector<vector<Edge>> adjList;

    Graph(int ver) : V(ver), adjList(ver) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
    }

    void topo(int v, vector<bool>& visited, stack<int>& stack) {
        visited[v] = true;

        for (const auto& i : adjList[v]) {
            if (!visited[i.dest]) {
                topo(i.dest, visited, stack);
            }
        }

        stack.push(v);
    }

    vector<int> topologicalSort() {
        stack<int> stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topo(i, visited, stack);
            }
        }

        vector<int> result;
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }

        return result;
    }

    void longestPath(int source) {
        vector<int> topoOrder = topologicalSort();
        vector<int> a(V, numeric_limits<int>::min());
        a[source] = 0;

        for (int i = 0; i < V; ++i) {
            int u = topoOrder[i];

            if (a[u] != numeric_limits<int>::min()) {
                for (const auto& j : adjList[u]) {
                    int v = j.dest;
                    int weight = j.weight;

                    if (a[u] + weight > a[v]) {
                        a[v] = a[u] + weight;
                    }
                }
            }
        }

        // In kết quả
        for (int i = 0; i < V; ++i) {
            if (a[i] == numeric_limits<int>::min()) {
                cout << "No path to " << i << "\n";
            } else {
                cout << "To " << i << ": " << a[i] << "\n";
            }
        }
    }
};

int main() {
    int ver = 6;
    Graph g(ver);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 5, 1);

    int source = 0;
    g.longestPath(source);

    return 0;
}

