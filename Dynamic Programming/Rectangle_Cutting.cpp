#include "bits/stdc++.h"
using namespace std;


/*
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    vector<vector<int>>memo(a+1,vector<int>(b+1,-1));
    function<int(int,int)>dfs=[&](int x, int y)->int{
        if(x==y) return 0;
        int& cur=memo[x][y];
        if(cur!=-1) return cur;
        int res=INT_MAX/2;
        for(int k=1;k<x;k++){
            res=min(res,dfs(x-k,y)+dfs(k,y)+1);
        }
        for(int k=1;k<y;k++){
            res=min(res,dfs(x,y-k)+dfs(x,k)+1);
        }
        return cur=res;
    };
    cout<<dfs(a,b)<<"\n";
    return 0;
}

递归还是太慢了，无法通过



*/

int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;

    // Initialize DP table
    for(int i = 0; i <= a; ++i) {
        for(int j = 0; j <= b; ++j) {
            if(i == j) {
                dp[i][j] = 0; // No cuts needed for squares
            } else {
                dp[i][j] = INT_MAX;
                // Horizontal cuts
                for(int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
                // Vertical cuts
                for(int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << "\n";
    return 0;
}
