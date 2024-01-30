#include "bits/stdc++.h"
using namespace std;

/*
track长度这个点非常的巧妙，不要总是想着用一些heap什么之类的来track
这样写也非常的优雅
我有个新的element进来，那就先把之前已有的长度--
然后再把新的添加进去，把之前的长度分为左边和右边
维护长度的多少，而不是多长
*/

map<int,int>dic;
set<int>seen;
void solve(){
    int x,n;
    cin>>x>>n;
    dic[x]++;
    seen.insert(0);
    seen.insert(x);
    for(int i=0;i<n;i++){
        int cur;
        cin>>cur;
        auto itr=seen.lower_bound(cur);
        int r=*itr;
        --itr;
        int l=*itr;
        --dic[r-l];
        if(!dic[r-l]) dic.erase(r-l);
        dic[r-cur]+=1;
        dic[cur-l]+=1;
        seen.insert(cur);
        cout<<(--dic.end())->first<<" ";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}