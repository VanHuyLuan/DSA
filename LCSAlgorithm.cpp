#include <iostream>
#include <vector>
using namespace std;

int LCS(vector<int>& a, vector<int>& b ,int m , int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(m);
    vector<int> b(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int lengthOfLCS = LCS(a, b , m , n);
    cout << lengthOfLCS << endl;
    return 0;
}
