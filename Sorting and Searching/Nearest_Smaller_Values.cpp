#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }
    int ans[n]={0};
    stack<int>stk;
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && temp[i]<temp[stk.top()]){
            int index=stk.top();
            stk.pop();
            ans[index]=i+1;
        }
        stk.push(i);
    }
    for(auto& i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}