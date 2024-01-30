#include "bits/stdc++.h"
using namespace std;


void solve(){
    int n;
    cin>>n;
    unordered_set<int>seen;
    int temp[n];
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        if(seen.find(temp[i]-1)==seen.end()){
            ans+=1;
        }
        seen.insert(temp[i]);
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}