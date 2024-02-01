#include "bits/stdc++.h"
using namespace std;
using ll=long long;

/*
为什么啊？
这几个结论题都没学过啊

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    int temp[n];
    ll total=0;
    for(int i=0;i<n;i++){
        cin>>temp[i];
        total+=temp[i];
    }
    sort(temp,temp+n);
    cout<<max(total,2ll*temp[n-1])<<"\n";
    return 0;
}