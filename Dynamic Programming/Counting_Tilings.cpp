#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    // dp[i][j] stores the number of ways to fill i x j grid
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    dp[1][1] = 0; // Not possible to fill 1x1 grid
    dp[1][2] = dp[2][1] = 1; // Only one way to fill 1x2 or 2x1 grid

    // Calculate ways for all other dimensions
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // If it's not one of the base cases
            if (!(i == 1 && j == 1) && !(i == 1 && j == 2) && !(i == 2 && j == 1)) {
                int waysFromPrevCol = (j - 1 >= 0) ? dp[i][j - 1] : 0;
                int waysFromPrevPrevCol = (j - 2 >= 0) ? dp[i][j - 2] : 0;
                dp[i][j] = (waysFromPrevCol + waysFromPrevPrevCol) % MOD;
            }
        }
    }

    // Answer for n x m grid
    int answer = dp[n][m];
    cout << answer << endl;

    return 0;
}