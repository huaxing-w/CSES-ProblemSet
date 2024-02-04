#include "bits/stdc++.h"
using namespace std;

/*
技巧性很强
首先还是经典的按第二个key排序，然后有点最长上升子序列的问道，把电影安排到每个人
但是我们希望安排到尽早看完的人身上
用set的话是升序排列，二分查找不好操作
如果拿到了index是0，我们要考虑是不是小于它的情况
但是如果乘上-1，就可以直接判点是不是end的情况了
小技巧
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    array<int,2> temp[n];
    for(int i=0;i<n;i++){
        cin>>temp[i][0]>>temp[i][1];
    }
    sort(temp,temp+n,[](auto& a, auto& b){
        return a[1]<b[1];
    });

    multiset<int>seen;
    int ans=0;
    for(int i=0;i<n;i++){
        int x=-temp[i][0];
        int y=-temp[i][1];
        if(seen.empty()){
            seen.insert(y);
            ans+=1;
        }
        else{
            auto index=seen.lower_bound(x);
            if(index==seen.end()){
                if(seen.size()<k){
                    seen.insert(y);
                    ans+=1;
                }
            }
            else{
                seen.erase(index);
                seen.insert(y);
                ans+=1;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}