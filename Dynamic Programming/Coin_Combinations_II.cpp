#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

/*
和leetcode的零钱兑换2是一道题
可以用灵神的01背包思想去做，但是这里面的小细节是选了当前硬币还可以接着选当前硬币，因为不是递归到i-1，而是递归到i
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<vector<ll>> memo(n, vector<ll>(x + 1, -1));
    function<ll(ll,ll)>dfs=[&](ll i, ll j)->ll{
        if(i<0){
            if(j==0) return 1;
            return 0;
        }
        ll& cur=memo[i][j];
        if(cur!=-1) return cur;
        if(j<coins[i]) return cur=dfs(i-1,j)%mod;
        return cur=(dfs(i-1,j)+dfs(i,j-coins[i]))%mod;

    };

    cout<<dfs(n-1,x)<<"\n";
    return 0;
}
