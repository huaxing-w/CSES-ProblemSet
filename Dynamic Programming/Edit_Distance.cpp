#include "bits/stdc++.h"
using namespace std;

/*
经典的编辑距离，已经记不清第一次学是什么时候了
当时这几个地方就没有搞太懂，现在搞明白了
dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1
这几个值分别是什么意思

dp[i-1][j]+1 
我把第一个string移除了当前的i，这个很好理解

dp[i][j-1]+1
之前就没搞明白这个怎么理解，这里着重强调一下。我现在在第一个string上多加了一个字母，那我当前的i就要和j-1去匹配

abcde
    i
cba
  j

我现在给第一个string多加一个a
abcdea
    i
cba
 j

现在最后一个值相同了，当前的i不变，我需要去匹配j-1项了

dp[i-1][j-1]+1
这个太简单了，i和j都相同了，现在去匹配i-1和j-1

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    int m=a.size();
    int n=b.size();

    int dp[m+1][n+1];
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=m;i++) dp[i][0]=i;
    for(int i=1;i<=n;i++) dp[0][i]=i;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
        }
    }
    cout<<dp[m][n]<<"\n";

    return 0;
}