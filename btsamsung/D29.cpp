#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    double distance(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

class Graph {
public:
    int V;
    vector<Point> points;
    vector<vector<pair<int, double>>> adjList;

    Graph(int ver, const vector<Point>& pts) : V(ver), points(pts), adjList(V) {}

    void addEdge(int u, int v) {
        double weight = points[u].distance(points[v]);
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    double dijkstra(int src, int dest) {
        vector<double> dist(V, numeric_limits<double>::max());
        dist[src] = 0.0;

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0.0, src});

        while (!pq.empty()) {
            double cur = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == dest) {
                return cur;
            }

            for (const auto& i : adjList[u]) {
                int v = i.first;
                double weight = i.second;

                if (cur + weight < dist[v]) {
                    dist[v] = cur + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1.0;
    }
};

int main() {
    vector<Point> points = {{0, 0}, {1, 2}, {3, 1}, {4, 4}, {2, 2}};
    int ver = points.size();

    Graph g(ver, points);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    double a = g.dijkstra(0, 4);

    if (a != -1.0) {
        cout  << a << "\n";
    } else {
        cout << "No path from source to destination.\n";
    }

    return 0;
}

