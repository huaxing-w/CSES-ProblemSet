#include "bits/stdc++.h"
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>temp;
    for(int i=0;i<n;i++){
        int cur;
        cin>>cur;
        if(temp.empty() || cur>temp.back()){
            temp.push_back(cur);
        }
        else{
            auto itr=lower_bound(temp.begin(),temp.end(),cur);
            *itr=cur;
        }
    }
    cout<<temp.size()<<"\n";
    return 0;
}