#include "bits/stdc++.h"
using namespace std;

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
    int n=s.size();
    vector<int>z=z_function(s);
    for(auto& i:z){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        if(z[i]+i>=n) cout<<i<<" ";

    }
    cout<<n<<"\n";

    return 0;
}