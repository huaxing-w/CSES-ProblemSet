#include "bits/stdc++.h"
using namespace std;
using pii=pair<int,int>;

/*
我只能说太牛逼了
早上6点开始肝这个题，俩个小时终于把这个题弄懂了
太秀了老铁

先说核心思想，再说细节

第一问 当前range包含多少个其他range
倒着枚举，排序是按照第一个key排序的
那么倒着枚举的时候，新的pair的左边肯定是比之前的靠前的，我们只需要快速求出对于当前的右端点来说，有多少个已经遍历过的右端点在其左边，掐住一个头，然后倒着枚举

第二问 当前range被多少个其他range所包含
正着枚举，差分的思想，在bit上数这一段这一段有多少个已有的range

小细节1，排序的时候，为什么要这样？
    sort(v1.begin(),v1.end(),[](auto a, auto b){
        if(a.first.first==b.first.first){
            return a.first.second>b.first.second;
        }
        return a.first.first<b.first.first;
    });

比如现在有俩段range，起点相同
————————
————————————

倒着枚举的时候，我们希望先把小的处理了，大的才能把小的信息包括进去

小细节2，树状数组离散化
之前很少去体会离散化，导致最开始的时候看不懂代码，用一个mp把其离散化非常的精髓

小细节3，为什么第二问update的时候，每次都是从1开始，不应该是从当前range的左端点开始吗？
我们的mp只记录了右端点，不知道离散化后的左端点，所以不妨从1开始，反正是不影响计算结果的。

*/


const int N=2e5+1;
class bit{
    int t[N+1]={0};
public:
    bit(){

    }
    int lowbit(int x){
        return x&(-x);
    }
    void update(int n, int x, int val){
        while(x<=n){
            t[x]+=val;
            x+=lowbit(x);
        }
    }
    int query(int x){
        int res=0;
        while(x){
            res+=t[x];
            x-=lowbit(x);
        }
        return res;
    }
    void clear(){
        for(int i=0;i<N+1;i++){
            t[i]=0;
        }
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    set<int>seen;
    vector<pair<pii,int>>v1(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v1[i]={{x,y},i};
        seen.insert(y);
    }
    int count=0;
    map<int,int>mp;
    for(auto& i:seen){
        mp[i]=++count;
    }

    sort(v1.begin(),v1.end(),[](auto a, auto b){
        if(a.first.first==b.first.first){
            return a.first.second>b.first.second;
        }
        return a.first.first<b.first.first;
    });
    int ans[n]={0};
    bit tree;
    tree.update(count,mp[v1[n-1].first.second],1);
    for(int i=n-2;i>=0;i--){
        ans[v1[i].second]=tree.query(mp[v1[i].first.second]);
        tree.update(count,mp[v1[i].first.second],1);
    }
    for(int i=0;i<n;i++){
        cout<<(ans[i]>0)<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    tree.clear();
    tree.update(count,1,1);
    tree.update(count,mp[v1[0].first.second]+1,-1);
    for(int i=1;i<n;i++){
        ans[v1[i].second]=tree.query(mp[v1[i].first.second]);
        tree.update(count,1,1);
        tree.update(count,mp[v1[i].first.second]+1,-1);
    }
    for(int i=0;i<n;i++){
        cout<<(ans[i]>0)<<" ";
    }
    cout<<endl;
    return 0;
}