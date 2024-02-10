#include "bits/stdc++.h"
using namespace std;
using ll=long long;

/*
这是个非常经典的问题求最大值的
要点就是找出最不冲突的最大值，然后更新dp
但是细节比较多
比如，dp[i]的意思是前i个最大值是多少，用index来做，而不是想当然的把所有可能的值都枚举出来


*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<array<ll,3>>temp;
    for(int i=0;i<n;i++){
        int s,e,c;
        cin>>s>>e>>c;
        temp.push_back({s,e,c});
    }
    sort(temp.begin(),temp.end(),[](auto a, auto b){
        return a[1]<b[1];
    });
    ll ans=0;
    vector<ll>dp(n);
    dp[0]=temp[0][2];
    function<int(int)>find=[&](int index)->int{
        int l=0;
        int r=index-1;
        while(l<r){
            int mid=(l+r+1)/2;
            if(temp[mid][1]<temp[index][0]){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        if(temp[l][1]>=temp[index][0]) return -1;
        return l;
    };
    for(int i=1;i<n;i++){
        ll s=temp[i][0];
        ll e=temp[i][1];
        ll c=temp[i][2];
        int index=find(i);
        if(index!=-1) c+=dp[index];
        dp[i]=max(dp[i-1],c);
    }
    cout<<dp[n-1]<<"\n";
   
    return 0;
}