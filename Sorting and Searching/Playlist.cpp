#include "bits/stdc++.h"
using namespace std;


void solve(){
    int n;
    cin>>n;
    map<int,int>dic;
    int temp[n];
    int j=0;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        // while(seen.find(temp[i])!=seen.end()){
        //     seen.erase(temp[j]);
        //     j+=1;
        // }
        // seen.insert(temp[i]);
        // ans=max(ans,i-j+1);
        j=max(j,dic.find(temp[i])==dic.end()?0:dic[temp[i]]+1);
        //cout<<i<<" "<<j<<" "<<i-j+1<<endl;
        ans=max(ans,i-j+1);
        dic[temp[i]]=i;
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}