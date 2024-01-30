#include "bits/stdc++.h"
using namespace std;
using ll=long long;

void solve(){
    ll n;
    cin>>n;
    ll temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    sort(temp,temp+n);
    int mid=-1;
    if(n%2==1){
        mid=temp[n/2];
    }
    else{
        mid=(temp[n/2 -1]+temp[n/2])/2;
    }
    ll ans=0;
    for(auto& i:temp){
        ans+=abs(mid-i);
    }
    cout<<ans<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}