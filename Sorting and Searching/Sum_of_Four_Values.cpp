#include "bits/stdc++.h"
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin>>n>>x;
    array<ll,2> temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i][0];
        temp[i][1]=i+1;
    }
    
    sort(temp,temp+n);
    for(int i=0;i<n;i++){
        if(temp[i][0]>=x) break;
        if(i>0 && temp[i][0]==temp[i-1][0]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && temp[j][0]==temp[j-1][0]) continue;
            // if(temp[i][0]+temp[j][0]>x){
            //     cout<<"IMPOSSIBLE"<<"\n";
            //     return 0;
            // }
            ll target=x-temp[i][0]-temp[j][0];
            
            ll l=j+1,r=n-1;
            while(l<r){
                if(temp[l][0]+temp[r][0]==target){
                    cout<<temp[i][1]<<" "<<temp[j][1]<<" "<<temp[l][1]<<" "<<temp[r][1]<<"\n";
                    return 0;
                }
                else if(temp[l][0]+temp[r][0]<target) l+=1;
                else r-=1;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}