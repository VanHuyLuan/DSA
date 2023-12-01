#include <iostream>
#include <vector>
#include <stack>
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

    bool Euler() {
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
        vector<int> a;
        vector<bool> visited(ver, false);
        stack<int> stack;

        for (int i = 0; i < ver; ++i) {
            if (!visited[i]) {
                dfs(i, visited, stack);
            }
        }

        while (!stack.empty()) {
            a.push_back(stack.top());
            stack.pop();
        }

        reverse(a.begin(), a.end());

        return a;
    }

    void dfs(int vertex, vector<bool>& visited, stack<int>& stack) {
        visited[vertex] = true;

        for (int i : adjList[vertex]) {
            if (!visited[i]) {
                dfs(i, visited, stack);
            }
        }

        stack.push(vertex);
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
    //g.addEdge(0, 2);
    //g.addEdge(1, 3);
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

    if (g.Euler()) {
        cout << "Có tồn tại một đường đi có hướng đi qua mỗi đỉnh đúng một lần.\n";
    } else {
        cout << "Không tồn tại một đường đi có hướng đi qua mỗi đỉnh đúng một lần.\n";
    }

    return 0;
}
