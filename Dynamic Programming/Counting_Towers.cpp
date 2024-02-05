#include "bits/stdc++.h"
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int N=1e6;


/*
这个定义dp状态的方法太猛了，之前没做过的话，很难往这个方向去想
俩个状态，最后一层是分开的还是融合的

如果n是分开的
    那么n-1有分开，有融合
        n-1分开的情况, 有4种

            |_|_|
            | | |

            |_| |
            | | |

            | |_|
            | | |

            | | |
            | | |
        
        n-1融合的情况，只有一种
            
            |_|_|
            |   |

如果n是融合的
    那么n-1有分开，有融合
        n-1分开的情况, 有1种

            |_ _|
            | | |
        
        n-1融合的情况，有2种
            
            |_ _|
            |   |
            
            |   |
            |   |

想清楚状态转移，这个问题就好解决了
*/

ll dp[N+1][2]={0};

inline void calc(){
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=N;i++){
        dp[i][0]=(dp[i-1][0]*4%mod+dp[i-1][1]%mod)%mod;
        dp[i][1]=(dp[i-1][1]*2%mod+dp[i-1][0]%mod)%mod;
    }
}



void solve(){
    int n;
    cin>>n;
    cout<<(dp[n][0]+dp[n][1])%mod<<"\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    calc();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}