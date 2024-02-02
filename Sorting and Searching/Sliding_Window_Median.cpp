#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

using indexed_set = tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>;

/*
第一次试着使用这个平衡树
原题是leetcode的480

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int temp[n];
    indexed_set s;
    int l=0;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        s.insert({temp[i],i});
        if(i-l+1==k){
            auto y = s.find_by_order((k-1)/2);
            cout<<(*y).first<<" ";
            s.erase({temp[l],l});
            l+=1;
        }
    }
    cout<<"\n";
    return 0;
}