#include "bits/stdc++.h"
using namespace std;
using ll=long long;

const int maxN=2e5;
int n,t,temp[maxN];


/*
最经典的二分搜索没什么好说的
但是这里值得注意的是这个数据类型
这一句是之前一直没有想到过的
cur+=min(mid/temp[i],(ll)1e9);
我是有可能爆ll的，所以要加上这个
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>t;
    for(int i=0;i<n;++i){
        cin>>temp[i];
    }
    ll l=0;
    ll r=1e18;
    while(l<r){
        ll mid=(l+r)/2;
        ll cur=0;
        for(int i=0;i<n;++i){
            cur+=min(mid/temp[i],(ll)1e9);
        }
        if(cur>=t) r=mid;
        else l=mid+1;
    }
    cout<<l<<"\n";
    return 0;
}