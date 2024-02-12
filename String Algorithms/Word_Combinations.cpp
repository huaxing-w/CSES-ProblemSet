#include "bits/stdc++.h"
using namespace std;

using ll = long long;
const ll mod = (ll)1e9+7;

/*
omg,omg,omg
终于过了

这道题一开始，感觉像是个完全背包，但是复杂度过高，substr的compare太费时间了
于是字典树就登场了，这样可以只loop string的长度，然后我以为是个O(N2),但是实际上是O(N2*m)还是太费事了
于是乎，我上网看了别人的写法，发现了这种loop的方法，外层循环逆序，然后内层循环正序
这样可以提前剪纸，之前trie的操作也可以复用，太牛逼了

*/

struct TrieNode{
    TrieNode* children[26]={nullptr};
    bool isEnd=false;
    
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }
    TrieNode* getRoot(){
        return root;
    }


    void insert(string& s){
        TrieNode* node=root;
        for(auto& c:s){
            if(!node->children[c-'a']){
                node->children[c-'a']=new TrieNode();

            }
            node=node->children[c-'a'];
        }
        node->isEnd=true;
    }
    bool check(string& s){
        TrieNode* node=root;
        for(auto& c:s){
            if(!node->children[c-'a']) return false;
            node=node->children[c-'a'];
        }
        return node->isEnd;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    ll k;
    cin >> k;
    Trie t;
    for(int i = 0; i < k; i++){
        string cur;
        cin>>cur;
        t.insert(cur);
    }
  
    ll n = s.size();



    vector<ll> dp(n+1, 0);
    dp[n] = 1; 
    for(int i=n-1;i>=0;i--){
        TrieNode* node=t.getRoot();
        ll cur=0;
        for(int j=i;j<n;j++){
            if(!node->children[s[j]-'a']) break;
            node=node->children[s[j]-'a'];
            if(node->isEnd) cur=(cur+dp[j+1])%mod;
        }
        dp[i]=cur;
    }
    cout<<dp[0]<<"\n";

    return 0;
}