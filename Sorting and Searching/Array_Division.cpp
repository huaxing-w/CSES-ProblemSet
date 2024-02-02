#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    ll temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    ll l=0;
    ll r=1e15;
    function<bool(ll)>check=[&](ll mid)->bool{
        ll total=1;
        ll cur=0;
        for(auto& i:temp){
            if(i>mid) return false;
            if(cur+i>mid){
                total+=1;
                cur=i;
            }
            else{
                cur+=i;
            }
        }
        return total<=k;

    };
    while(l<r){
        ll mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
    
    return 0;
}