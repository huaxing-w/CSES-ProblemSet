#include "bits/stdc++.h"
using namespace std;
/*
约瑟夫问题

用队列可以完美模拟过程，比较无脑

*/
void solve(){
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(!q.empty()){
        int top=q.front();
        q.pop();
        q.push(top);
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}