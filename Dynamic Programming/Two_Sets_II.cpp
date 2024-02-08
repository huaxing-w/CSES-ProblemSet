#include "bits/stdc++.h"
using namespace std;

using ll=long long;


/*
这一道题有太多可以说的地方了

首先这是一道经典的01背包问题，01背包求方案数
求方案数就是最后成功的时候返回1，然后把可行的方案加起来
反正这里就是经典的选或不选，有的是只能不选，有的是可以选可以不选
当然这里用递归还是太慢了， 无法通过所有的case

第二个要说的点是01背包中，第二层循环倒着枚举的问题
这已经是第二次碰见这个事情了，现在总结一下

就拿零钱兑换来说

amount在外侧循环
    物品在内测循环

这个是在求可重复使用硬币，且顺序不一样就选一种方案
————————————————————————————————————————————
物品在外侧循环
    amount在内测从小到大循环

这个是在求可重复使用硬币，set一样就算一种方案，注意这里虽然物品在外侧，但是如果amount从小到大枚举，还是无线背包的模型
————————————————————————————————————————————
物品在外侧循环
    amount在内测从大到小循环

这个才是最经典的01背包模型，物品只能用一次

最后要说的就是如何做除法取余数
也就是求逆元
先求出快速幂
在求出逆元
ll div(ll a, ll b, ll p){
    b=quickpow(b,p-2,p);
    return a*b%p;
}

然后除法取余数就是乘上这个数的逆元取余数

*/

ll quickpow(ll a, ll b, ll c){
    ll ans=1;
    a%=c;
    while(b){
        if(b&1) ans=ans*a%c;
        a=a*a%c;
        b>>=1;
    }
    return ans%c;
}

ll div(ll a, ll b, ll p){
    b=quickpow(b,p-2,p);
    return a*b%p;
}

const int mxN=5e2,M=1e9+7;
int n;
ll dp[mxN*(mxN+1)/2+1];
int main(){
    cin>>n;
    int s=n*(n+1)/2;
    if(s&1){
        cout<<0<<"\n";
        return 0;
    }
    s/=2;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i*(i+1)/2;j>=i;j--){
            dp[j]=(dp[j]+dp[j-i])%M;
        }
    }
    cout<<div(dp[s],2,M)<<"\n";
}


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     ll n;
//     cin>>n;
//     ll temp[n];
//     for(int i=0;i<n;i++){
//         temp[i]=i+1;
//     }
//     ll total=accumulate(temp,temp+n,0);
//     if(total%2!=0){
//         cout<<0<<"\n";
//         return 0;
//     }


//     ll target=total/2;
//     ll mod=1e9+7;
//     vector<vector<ll>>memo(n,vector<ll>(target+1,-1));
//     function<int(int,int)>dfs=[&](int i, int t)->int{
//         if(i<0) return t==0?1:0;
//         ll& cur=memo[i][t];
//         if(cur!=-1) return cur;
//         if(temp[i]>t) return cur=dfs(i-1,t)%mod;
//         return cur=(dfs(i-1,t)%mod+dfs(i-1,t-temp[i])%mod)%mod;
//     };
//     cout << div(dfs(n-1, target),2,mod) << "\n";

//     return 0;
// }