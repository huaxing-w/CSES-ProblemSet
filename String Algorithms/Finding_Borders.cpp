#include "bits/stdc++.h"
using namespace std;
/*
Z函数是干嘛的？
Z函数 先求出z函数数组
数组中的每个数表示，当前后缀可以最长匹配多少前缀


*/
vector<int> z_function(string& s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    
    vector<int>z=z_function(s);

    int n=s.size();
    vector<int>ans;
    for(int i=1;i<s.size();i++){
        if(z[i]>=n-i) ans.push_back(n-i);
    }
    sort(ans.begin(),ans.end());
    for(auto& i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}