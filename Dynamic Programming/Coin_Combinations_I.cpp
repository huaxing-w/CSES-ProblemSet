#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
 
ll dfs(vector<ll>& coins, vector<ll>& memo, ll x) {
    if (x < 0) return 0; // Return 0 for negative sum, as it represents no valid way
    if (x == 0) return 1; // Base case: one way to make 0 sum
    ll& cur = memo[x];
    if (cur != -1) return cur; // Use memoized result if available
    ll res = 0;
    for (auto& c : coins) {
        res = (res + dfs(coins, memo, x - c)) % mod;
    }
    return cur = res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<ll> memo(x + 1, -1);
    cout << dfs(coins, memo, x) << "\n";
    return 0;
}