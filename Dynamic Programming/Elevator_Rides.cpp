#include "bits/stdc++.h"
using namespace std;
using ll=long long;

/*
这个题我现在坐着还是有些吃力
这个状态转移我是没想到的，就是对于一个mask，我们试着loop每一种组合，看能不能减小当前的最大run的次数
这里面维护的是俩个值，一个是当前这个状态需要多少次的run，然后来一个新的需要多少次的run
有难度，不太好想
*/
int main(){
    ll n,x;
    cin>>n>>x;
    ll temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    int total=1<<n;
    array<ll,2> dp[total];
    dp[0]={1,0};
    for(int i=1;i<total;i++){
        dp[i]={LLONG_MAX,0};
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                array<ll,2>cur=dp[i^(1<<j)];
                if(cur[1]+temp[j]<=x){
                    cur[1]+=temp[j];
                }
                else{
                    cur[0]+=1;
                    cur[1]=temp[j];
                }
                dp[i]=min(dp[i],cur);
            }
        }
    }
    cout<<dp[total-1][0]<<"\n";
    
    return 0;
}