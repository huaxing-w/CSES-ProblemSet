#include "bits/stdc++.h"
using namespace std;

/*
2024-01-29
这个题目出的非常的好，最开始我的写法就是按照题意去模拟
为了不“浪费”我就尽可以的找已经有的里面，只比当前cube大1的cube，然后替换掉，好比我现在的底座是新的更小的cube
我觉得复杂度的话是没有什么问题的，但是还是tle了

然后我就查了一下别人是怎么写的，一下子就震惊了，原来这个就是LIS，最长递增子序列问题，我开始还在纳闷为什么是LIS，后面才想通，LIS的求法就是在模拟整个过程

3 8 2 1 5

我们在求解的过程中，就是在不停的替换“最合适”的cube
3 
3 8 
2 8 
1 8 
1 5 

值得一提的是在传统的LIS的代码中

如果是求严格递增用的是lower_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>stk;
        for(auto& i:nums){
            auto itr=lower_bound(stk.begin(),stk.end(),i);
            if(itr==stk.end()) stk.push_back(i);
            else *itr=i;
        }
        return stk.size();
    }
};

如果是非递减用的是upper_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>stk;
        for(auto& i:nums){
            auto itr=upper_bound(stk.begin(),stk.end(),i);
            if(itr==stk.end()) stk.push_back(i);
            else *itr=i;
        }
        return stk.size();
    }
};

那为什么我们这道题里要用的是upper_bound呢？我们替换cube的时候，是找一个严格大于当前cube的，1不能落在1上面，必须是1 1， 所以是最长非递减子序列





*/


// void solve(){
//     int n;
//     cin>>n;
//     int nums[n];
//     int ans=0;
//     multiset<int>temp;
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//         auto itr=lower_bound(temp.begin(),temp.end(),nums[i]+1);
//         if(itr==temp.end()) ans+=1;
//         else{
//             temp.erase(itr);
//         }
//         temp.insert(nums[i]);
//     }
//     cout<<ans<<"\n";
// }

void solve(){
    int n;
    cin>>n;
    vector<int>temp;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        auto itr=upper_bound(temp.begin(),temp.end(),a);
        if(itr==temp.end()) temp.push_back(a);
        else *itr=a;
    }
    cout<<temp.size()<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}