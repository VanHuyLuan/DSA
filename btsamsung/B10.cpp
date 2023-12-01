#include <iostream>
#include <vector>
#include <stack>

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

    vector<int> strongconnect(int startVertex) {
        vector<int> scc;

        vector<bool> visited(ver, false);
        stack<int> stack;

        dfs(startVertex, visited, stack);

        Graph a = transpose();
        fill(visited.begin(), visited.end(), false);

        while (!stack.empty()) {
            int vertex = stack.top();
            stack.pop();

            if (!visited[vertex]) {
                a.dfs(vertex, visited, scc);
            }
        }

        return scc;
    }

private:
    void dfs(int vertex, vector<bool>& visited, stack<int>& stack) {
        visited[vertex] = true;

        for (int i : adjList[vertex]) {
            if (!visited[i]) {
                dfs(i, visited, stack);
            }
        }

        stack.push(vertex);
    }

    void dfs(int vertex, vector<bool>& visited, vector<int>& scc) {
        visited[vertex] = true;
        scc.push_back(vertex);

        for (int i : adjList[vertex]) {
            if (!visited[i]) {
                dfs(i, visited, scc);
            }
        }
    }

    Graph transpose() {
        Graph a(ver);

        for (int i = 0; i < ver; ++i) {
            for (int j : adjList[i]) {
                a.addEdge(j, i);
            }
        }

        return a;
    }
};

int main() {
    Graph g(100);
    //g.addEdge(0, 1);
    //g.addEdge(1, 2);
    //g.addEdge(2, 0);
    //g.addEdge(1, 3);
    //g.addEdge(3, 4);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        g.addEdge(x , y);
    }

    int startVertex = 2;
    vector<int> scc = g.strongconnect(startVertex);

    cout << "Thành phần liên thông mạnh chứa đỉnh " << startVertex << ": ";
    for (int vertex : scc) {
        cout << vertex << " ";
    }

    return 0;
}

