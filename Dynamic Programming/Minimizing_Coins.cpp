#include "bits/stdc++.h"
using namespace std;

/*
线性dp，入门题目
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int memo[x+1];
    memset(memo,-1,sizeof(memo));
    function<int(int)>dfs=[&](int x)->int{
        if(x<0) return INT_MAX/2;
        if(x==0) return 0;
        int& cur=memo[x];
        if(cur!=-1) return cur;
        int res=INT_MAX/2;
        for(auto& c:coins){
            res=min(res,dfs(x-c)+1);
        }
        return cur=res;
    };
    int ans=dfs(x);
    cout<<(ans==INT_MAX/2?-1:ans)<<"\n";
    return 0;
}