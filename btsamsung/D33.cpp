
#include <iostream>
#include <vector>

using namespace std;

int minCostPath(const vector<vector<int>>& a) {
    int N = a.size();

    vector<vector<int>> dp(N, vector<int>(N, 0));

    dp[0][0] = a[0][0];

    for (int j = 1; j < N; ++j) {
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[N - 1][N - 1];
}

int main() {
    vector<vector<int>> a = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = minCostPath(a);

    cout << result << "\n";

    return 0;
}
