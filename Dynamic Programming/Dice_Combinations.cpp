#include "bits/stdc++.h"
using namespace std;
using ll=long long;
const int mod=1e9+7;
/*
线性dp，入门题目
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll memo[n+1];
    memset(memo,-1,sizeof(memo));
    function<ll(ll)>dfs=[&](ll n)->ll{
        if(n==0) return 1;
        if(n<0) return 0;
        ll& cur=memo[n];
        if(cur!=-1) return cur;
        ll res=0;
        for(int i=1;i<=6;i++){
            res=(res+dfs(n-i))%mod;
        }
        return cur=res;
    };
    cout<<dfs(n)<<"\n";
    return 0;
}