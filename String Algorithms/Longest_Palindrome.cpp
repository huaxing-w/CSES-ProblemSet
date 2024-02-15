#include "bits/stdc++.h"
using namespace std;

/*
马拉车算法，没有太搞懂说实话
看了一个董晓算法的视频，有个大概的概念了
类似于z函数，马拉车要干这几个事情
首先是有个d函数，然后是盒子大小[l,r]
d函数表述对于每个字符i，他的回文半径是多少，注意这里是算字符本身的，也就是回文长度除2上取整
然后向后枚举，如果对称点在盒子内，直接更新否则从r+1处向后枚举
然后开始暴力枚举来试图夸大半径
然后更新盒子大小

*/

string longestPalindrome(string& s) {
    string ns="$#";
    for(auto& c:s){
        ns+=c;
        ns+="#";
    }
    int d[ns.size()];
    memset(d,0,sizeof(d));
    d[1]=1;
    int maxLen=0;
    int start=0;
    int l,r=0;
    for(int i=2;i<ns.size();i++){
        if(i<=r) d[i]=min(d[r-i+l],r-i+1);
        while(ns[i-d[i]]==ns[i+d[i]]) d[i]++;
        if(i+d[i]-1>r) l=i-d[i]+1,r=i+d[i]-1;
        if(d[i]*2-1>maxLen){
            maxLen=d[i]*2-1;
            start=i-d[i]+1;
        }
    }
    string ans;
    for(int i=start;i<start+maxLen;i++){
        if(ns[i]!='#') ans+=ns[i];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    cout<<longestPalindrome(s)<<"\n";

    return 0;
}