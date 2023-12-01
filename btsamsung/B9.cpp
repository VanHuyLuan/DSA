#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int ver;
    vector<vector<int>> graph;

public:
    Graph(int v) : ver(v), graph(v) {}

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    bool isEulerianCycle() {
        if (!isStronglyConnected()) {
            return false;
        }

        for (int i = 0; i < ver; ++i) {
            if (graph[i].size() != inDegree(i) || graph[i].size() != outDegree(i)) {
                return false;
            }
        }

        return true;
    }

private:
    bool isStronglyConnected() {
        vector<bool> visited(ver, false);

        dfs(0, visited);

        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }

        fill(visited.begin(), visited.end(), false);

        dfsReverse(ver - 1, visited);

        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }

        return true;
    }

    void dfs(int a, vector<bool>& visited) {
        visited[a] = true;

        for (int neighbor : graph[a]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    void dfsReverse(int a, vector<bool>& visited) {
        visited[a] = true;

        for (int neighbor : graph[a]) {
            if (!visited[neighbor]) {
                dfsReverse(neighbor, visited);
            }
        }
    }

    int inDegree(int a) {
        int count = 0;
        for (size_t i = 0; i < graph.size(); ++i) {
            for (int neighbor : graph[i]) {
                if (neighbor == a) {
                    ++count;
                }
            }
        }
        return count;
    }

    int outDegree(int a) {
        return graph[a].size();
    }
};

int main() {
    Graph g(100);
    //g.addEdge(0, 1);
    //g.addEdge(1, 2);
    //g.addEdge(2, 0);
    //g.addEdge(1, 3);
    //g.addEdge(3, 4);
    //g.addEdge(4, 1);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        g.addEdge(x , y);
    }
    if (g.isEulerianCycle()) {
        cout << "Đồ thị có chu trình Euler.\n";
    } else {
        cout << "Đồ thị không có chu trình Euler.\n";
    }

    return 0;
}
