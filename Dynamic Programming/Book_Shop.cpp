#include "bits/stdc++.h"
using namespace std;

/*
最最标准的01背包，应该没有比这个更加标准的01背包了
选或者不选

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> price(n), page(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> page[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j]; // Not taking book i
            if(j >= price[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-price[i-1]] + page[i-1]); // Taking book i
            }
        }
    }

    cout << dp[n][x] << "\n";
    return 0;
}