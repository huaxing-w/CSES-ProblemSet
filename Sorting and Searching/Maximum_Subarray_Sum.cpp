#include "bits/stdc++.h"
using namespace std;
using ll=long long;

void solve(){
    ll n;
    cin>>n;
    ll temp[n];
    ll ans=INT_MIN;
    ll cur=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        cur=max(temp[i],cur+temp[i]);
        ans=max(ans,cur);
    }
    cout<<ans<<"\n";
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}