#include "bits/stdc++.h"
using namespace std;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>dp(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>dp[i][j];
        }
    }
    vector<vector<int>>seen(n,vector<int>(m,0));
    int ans=0;
    function<void(int,int)>dfs=[&](int i, int j)->void{
        seen[i][j]=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(0<=nx && nx<n && 0<=ny && ny<m && !seen[nx][ny] && dp[nx][ny]=='.'){
                dfs(nx,ny);
            }
        }
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]=='.' && !seen[i][j]){
                ans+=1;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}