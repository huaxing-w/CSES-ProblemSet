#include "bits/stdc++.h"
using namespace std;
using ll=long long;

void solve(){
    ll n,target;
    cin>>n>>target;

    int temp[n];
    unordered_map<ll,ll>dic;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        if(temp[i]<target && dic.count(target-temp[i])){
            cout<<dic[target-temp[i]]<<" "<<i+1<<"\n";
            return;
        }
        if(temp[i]<target){
            dic[temp[i]]=i+1;
        }
        
    }
    
    cout<<"IMPOSSIBLE"<<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    

    return 0;
}