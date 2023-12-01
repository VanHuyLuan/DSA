#include <iostream>
#include <vector>
using namespace std;

const int r = 5;
const int c = 5;
bool isValid(int x, int y, const vector<vector<int>>& image, int targetColor, vector<vector<bool>>& visited) {
    return x >= 0 && x < r && y >= 0 && y < c && !visited[x][y] && image[x][y] == targetColor;
}

void floodFillDFS(int x, int y, vector<vector<int>>& image, int targetColor, int newColor, vector<vector<bool>>& visited) {
    visited[x][y] = true;

    image[x][y] = newColor;

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, image, targetColor, visited)) {
            floodFillDFS(newX, newY, image, targetColor, newColor, visited);
        }
    }
}

void floodFill(int x, int y, vector<vector<int>>& image, int newColor) {
    int targetColor = image[x][y];

    vector<vector<bool>> visited(r, vector<bool>(c, false));

    floodFillDFS(x, y, image, targetColor, newColor, visited);
}

void printImage(const vector<vector<int>>& image) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 1}
    };

    cout << "Original Image:" << endl;
    printImage(image);

    int startX = 2;
    int startY = 2;
    int newColor = 2;

    floodFill(startX, startY, image, newColor);

    cout << "\nImage after Floodfill:" << endl;
    printImage(image);

    return 0;
}

