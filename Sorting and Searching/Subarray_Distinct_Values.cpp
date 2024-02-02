#include "bits/stdc++.h"
using namespace std;
using ll=long long;
/*
这个题有个非常精髓的扩展
如果恰好有k个该怎么办？
这就是leetcode的992了
非常精髓的双指针加双指针

___________________
   l1   l2     i

l2是恰好有k-1个
l1是恰好有k个

那从[l2,i] 到 [l1,i]
每一个都是符合条件的
仔细想想是不是这个道理

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    ll temp[n]={0};
    unordered_map<int,int>count;
    ll ans=0;
    ll l=0;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        count[temp[i]]+=1;
        while(count.size()>k){
            count[temp[l]]-=1;
            if(count[temp[l]]==0) count.erase(temp[l]);
            l+=1;
        }
        ans+=i-l+1;
    }
    cout<<ans<<"\n";
    return 0;
}