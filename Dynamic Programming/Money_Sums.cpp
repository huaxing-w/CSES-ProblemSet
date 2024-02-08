#include "bits/stdc++.h"
using namespace std;

/*
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    set<int>seen;
    for(int i=0;i<n;i++){
        set<int>temp;
        int cur=0;
        cin>>cur;
        for(auto& num:seen){
            temp.insert(num+cur);
        }
        temp.insert(cur);
        for(auto& j:temp){
            seen.insert(j);
        }
    }
    cout<<seen.size()<<"\n";
    for(auto& i:seen){
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}

这种复杂度也可以过的吗？？？什么情况。。。

下面是传统01背包的做法
现在的问题是，第二个for循环为什么要倒着？
理解这个问题非常关键
加入我现在有2个硬币，2和3

如果我正着loop，dp[2]=1,这里没什么问题
但是我到4的时候,dp[4]=dp[4-2],这里会返回true，但是这个是不对的
我相当于用了2俩次
正确的做法是倒着循环，这样就可以保证只loop一次

这个问题之前就做过，但是现在理解才深刻了一些


*/
const int N=100, X=1e5;
int n,x[N],dp[X+1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    dp[0]=1;
    for(int j=0;j<n;j++){
        for(int i=X;i>=0;i--){
            if(i>=x[j]) dp[i]|=dp[i-x[j]];
        }

    }
    vector<int>ans;
    for(int i=1;i<=X;i++){
        if(dp[i]) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto& i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";

    
    return 0;
}