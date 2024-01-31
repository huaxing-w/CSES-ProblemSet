#include "bits/stdc++.h"
using namespace std;
using pii=pair<int,int>;

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
    vector<pair<pii,int>>v(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[i]={{x,y},i};
        seen.insert(y);
    }
    int count=0;
    map<int,int>mp;
    for(auto& i:seen){
        mp[i]=++count;
    }

    sort(v.begin(),v.end(),[](auto a, auto b){
        if(a.first.first==b.first.first){
            return a.first.second>b.first.second;
        }
        return a.first.first<b.first.first;
    });
    int ans[n]={0};
    bit tree;
    tree.update(count,mp[v[n-1].first.second],1);
    for(int i=n-2;i>=0;i--){
        ans[v[i].second]=tree.query(mp[v[i].first.second]);
        tree.update(count,mp[v[i].first.second],1);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    tree.clear();
    tree.update(count,1,1);
    tree.update(count,mp[v[0].first.second]+1,-1);
    for(int i=1;i<n;i++){
        ans[v[i].second]=tree.query(mp[v[i].first.second]);
        tree.update(count,1,1);
        tree.update(count,mp[v[i].first.second]+1,-1);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}