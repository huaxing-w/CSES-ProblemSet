#include "bits/stdc++.h"
using namespace std;
const int mod=1e9+7;
/*
线性dp，入门题目
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    char grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int ans[n][n];
    memset(ans,0,sizeof(ans));
    ans[0][0]=grid[0][0]=='.'?1:0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*') continue;
            if(i-1>=0 && grid[i-1][j]=='.') ans[i][j]=(ans[i][j]+ans[i-1][j])%mod;
            if(j-1>=0 && grid[i][j-1]=='.') ans[i][j]=(ans[i][j]+ans[i][j-1])%mod;
        }
    }
    cout<<ans[n-1][n-1]<<"\n";
    return 0;
}