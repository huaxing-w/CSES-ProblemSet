#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    array<int,2> temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i][0];
        temp[i][1]=i+1;
    }
    sort(temp,temp+n);
    for(int i=0;i<n;i++){
        int target=x-temp[i][0];
        int l=i+1;
        int r=n-1;
        while(l<r){
            if(temp[l][0]+temp[r][0]==target){
                cout<<temp[i][1]<<" "<<temp[l][1]<<" "<<temp[r][1]<<"\n";
                return 0;
            }
            else if(temp[l][0]+temp[r][0]<target) l+=1;
            else r-=1;
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}