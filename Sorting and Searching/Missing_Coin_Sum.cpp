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
    ll cur=0;
    for(auto& i:temp){
        if(i>cur+1){
            cout<<cur+1<<"\n";
            return;
        }
        cur+=i;
    }
    cout<<cur+1<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}