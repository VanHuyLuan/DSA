#include <iostream>
#include <vector>
#include <queue>

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

    vector<int> topologicalSort() {
        vector<int> indegree(ver, 0);

        for (int i = 0; i < ver; ++i) {
            for (int j : adjList[i]) {
                indegree[j]++;
            }
        }

        queue<int> a;

        for (int i = 0; i < ver; ++i) {
            if (indegree[i] == 0) {
                a.push(i);
            }
        }

        vector<int> b;

        while (!a.empty()) {
            int vertex = a.front();
            a.pop();
            b.push_back(vertex);

            for (int k : adjList[vertex]) {
                indegree[k]--;

                if (indegree[k] == 0) {
                    a.push(k);
                }
            }
        }

        return b;
    }
};

int main() {
    Graph g(100);
    //g.addEdge(5, 2);
   // g.addEdge(5, 0);
   // g.addEdge(4, 0);
   // g.addEdge(4, 1);
    //g.addEdge(2, 3);
    //g.addEdge(3, 1);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        g.addEdge(x , y);
    }

    vector<int> result = g.topologicalSort();

    cout << "Thứ tự tô pô: ";
    for (int vertex : result) {
        cout << vertex << " ";
    }

    return 0;
}

