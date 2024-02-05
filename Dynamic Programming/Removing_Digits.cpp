#include "bits/stdc++.h"
using namespace std;

/*
记忆化搜索入门题目
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>memo(n+1,-1);

    function<int(int)>dfs=[&](int x)->int{
        if(x==0) return 0;
        if(x<0) return INT_MAX/2;
        int& m=memo[x];
        if(m!=-1) return m;
        string cur=to_string(x);
        int res=INT_MAX/2;
        for(auto& c:cur){
            if(c!='0')
                res=min(res,dfs(x-(c-'0'))+1);
        }
        return m=res;
    };

    cout<<dfs(n)<<"\n";
    return 0;
}