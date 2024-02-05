#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9+7;

/*
这个题目感觉是数位dp的前驱版本，和数位dp有着异曲同工之妙
但是这边只需要一个last额外变量就好了
求方案数就是最后是返回1
数位dp中，比方说，数字1的个数，我们为什么需要一个count额外变量呢？
因为我们是在数dfs过程中填了多少个1，所以需要一个额外变量记录本次dfs中，填了多少1，后面方便返回
数方案数就不需要了
*/


int n, m;
vector<int> nums;
vector<vector<int>> dp;

int dfs(int index, int last) {
    if (index == n) {
        return 1; // Successfully reached the end of the array
    }
    if (dp[index][last] != -1) {
        return dp[index][last]; // Return cached result
    }
    int res = 0;
    if (nums[index] != 0) {
        if (abs(nums[index] - last) <= 1) {
            res = (res + dfs(index + 1, nums[index])) % mod;
        }
    } else {
        for (int d = -1; d <= 1; d++) {
            if (1 <= last + d && last + d <= m) {
                res = (res + dfs(index + 1, last + d)) % mod;
            }
        }
    }
    return dp[index][last] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    nums.resize(n);
    dp.assign(n, vector<int>(m+1, -1)); // Initialize memoization table

    for (int i = 0; i < n; i++) cin >> nums[i];

    int ans = 0;
    if (nums[0] != 0) {
        ans = dfs(1, nums[0]); // Start DFS with the first known value
    } else {
        for (int last = 1; last <= m; last++) {
            ans = (ans + dfs(1, last)) % mod; // Try all possible starts
        }
    }
    cout << ans << "\n";
    return 0;
}
