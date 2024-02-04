#include "bits/stdc++.h"
using namespace std;
using ll=long long;

/*
经典好题
这个滑动窗口的写法我以前没学习过，感觉更加的优雅
就是用temp[i-a],tmep[i-b]这种写法
然后之所有用pair是因为之前学习过的，可能会出现重复的，用一个index来方便移除
prefix sum
———————————————————
    a     b
i过了a以后，就把前缀和加入set，答案肯定就是过了a以后的，与前缀和最小值做差
i过了b以后，记得把之前的弹出
很有技巧性
*/

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    ll temp[n+1]={0};
    for(int i=0;i<n;i++){
        cin>>temp[i+1];
        temp[i+1]+=temp[i];
    }
    set<array<ll,2>> s;
    ll ans=-1e18;
    for(int i=0;i<=n;i++){
        if(i>=a){
            s.insert({temp[i-a],i-a});
        }
        if(s.size()){
            ans=max(ans,temp[i]-(*s.begin())[0]);
        }
        if(i>=b){
            s.erase({temp[i-b],i-b});
        }
    }
    cout<<ans<<"\n";
    return 0;
}