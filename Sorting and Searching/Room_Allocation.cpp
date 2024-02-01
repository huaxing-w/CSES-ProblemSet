#include "bits/stdc++.h"
using namespace std;
using pii=pair<int,int>;

/*
这个题就是经典的meeting room问题
和leetcode的253是同一个题目，只不过需要把分配的房间号也写出来，多麻烦了一些
按照第一个key排序，然后处理每一个range
其实这里让我想到了另外一道题就是leetcode的435 无重叠区间
435的话需要按照第二个key排序
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<pair<pii,int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({{a,b},i});
    }
    sort(v.begin(),v.end(),[](auto a, auto b){
        if(a.first.first==b.first.first){
            return a.first.second<b.first.second;
        }
        return a.first.first<b.first.first;
    });
    int total=0;
    int ans[n]={0};
    int cur=0;
    priority_queue<pii,vector<pii>,greater<>>h;
    for(auto& i:v){
        int index=i.second;
        int s=i.first.first;
        int e=i.first.second;
        if(h.empty() || h.top().first>=s){
            h.push({e,++cur});
            ans[index]=cur;
        }
        else{
            auto [end,label]=h.top();
            h.pop();
            h.push({e,label});
            ans[index]=label;
        }
        total=max(total,(int)h.size());
    }
    cout<<total<<"\n";
    for(auto& i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}