#include "bits/stdc++.h"
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    ll temp[n]={0};
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    unordered_map<ll,ll>count;
    count[0]=1;
    ll cur=0;
    ll ans=0;
    for(auto& i:temp){
        cur+=i;
        ans+=count[cur-x];
        count[cur]+=1;
    }
    cout<<ans<<"\n";
    return 0;
}