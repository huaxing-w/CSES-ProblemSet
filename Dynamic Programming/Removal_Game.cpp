#include "bits/stdc++.h"
using namespace std;
using ll=long long;

/*
这个套路之前也见过，但是没有想起来又
俩个人都play optimal的时候dp要怎么写
如果都是optimal的话，那就是求最小值了
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    vector<vector<ll>>memo(n,vector<ll>(n,-1));

    function<ll(ll,ll)>dfs=[&](ll i, ll j)->ll{
        if(i==j) return temp[i];
        if(i>j) return 0;
        ll& cur=memo[i][j];
        if(cur!=-1) return cur;

        ll a=temp[i]+min(dfs(i+1,j-1),dfs(i+2,j));
        ll b=temp[j]+min(dfs(i+1,j-1),dfs(i,j-2));
        return cur=max(a,b);
    };

    cout<<dfs(0,n-1)<<"\n";

    return 0;
}