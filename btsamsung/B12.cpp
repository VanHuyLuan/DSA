#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int ver;
    vector<vector<int>> adjList;

public:
    Graph(int v) : ver(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    bool Topo() {
        vector<int> a = topologicalSort();

        for (size_t i = 0; i < a.size() - 1; ++i) {
            if (!hasEdge(a[i], a[i + 1])) {
                return false;
            }
        }

        return true;
    }

private:
    vector<int> topologicalSort() {
        vector<int> result;
        vector<bool> visited(ver, false);

        for (int i = 0; i < ver; ++i) {
            if (!visited[i]) {
                dfs(i, visited, result);
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }

    void dfs(int vertex, vector<bool>& visited, vector<int>& result) {
        visited[vertex] = true;

        for (int i : adjList[vertex]) {
            if (!visited[i]) {
                dfs(i, visited, result);
            }
        }

        result.push_back(vertex);
    }

    bool hasEdge(int u, int v) {
        for (int i : adjList[u]) {
            if (i == v) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g(100);

    //g.addEdge(0, 1);
    //g.addEdge(1, 2);
    //g.addEdge(2, 3);
    //g.addEdge(3, 4);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        g.addEdge(x , y);
    }
    if (g.Topo()) {
        cout << "Đồ thị có thứ tự tô pô duy nhất.\n";
    } else {
        cout << "Đồ thị không có thứ tự tô pô duy nhất.\n";
    }

    return 0;
}

