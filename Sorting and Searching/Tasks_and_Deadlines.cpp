#include "bits/stdc++.h"
using namespace std;
using ll=long long;

/*
猜了个结论，然后过了，可是为什么呢
为什么要按照最短完成时间来排序呢？

gpt说的是这是经典的Shortest Processing Time first (SPT)问题
好像以前没有系统学习过
总之先当作结论记下来吧 
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    array<ll,2> temp[n];
    for(int i=0;i<n;i++){
        ll a,d;
        cin>>a>>d;
        temp[i][0]=a;
        temp[i][1]=d;
    }
    sort(temp,temp+n,[](auto a, auto b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    });
    ll ans=0;
    ll cur=0;
    for(auto& i:temp){
        cur+=i[0];
        ans+=i[1]-cur;
    }
    cout<<ans<<"\n";
    return 0;
}