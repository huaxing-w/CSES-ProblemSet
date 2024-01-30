#include "bits/stdc++.h"
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    int temp[n+1];
    int pos[n+1];
    temp[0]=0;
    pos[0]=0;
    for(int i=1;i<=n;i++){
        cin>>temp[i];
        pos[temp[i]]=i;
    }
    int count=0;
    unordered_set<int>seen;
    for(int i=1;i<=n;i++){
        if(seen.find(temp[i]-1)==seen.end()) count+=1;
        seen.insert(temp[i]);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int num1=temp[a];
        int num2=temp[b];
        if(pos[num1-1]<pos[num1] && b<=pos[num1-1]) count+=1;
        if(pos[num1-1]>pos[num1] && b>=pos[num1-1]) count-=1;
        if(pos[num1+1]>pos[num1] && b>=pos[num1+1]) count+=1;
        if(pos[num1+1]<pos[num1] && b<=pos[num1+1]) count-=1;
        pos[num1]=b;

        if(pos[num2-1]<pos[num2] && a<=pos[num2-1]) count+=1;
        if(pos[num2-1]>pos[num2] && a>=pos[num2-1]) count-=1;
        if(pos[num2+1]>pos[num2] && a>=pos[num2+1]) count+=1;
        if(pos[num2+1]<pos[num2] && a<=pos[num2+1]) count-=1;
        pos[num2]=a;

        swap(temp[a],temp[b]);
        cout<<count<<"\n";
    } 
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}