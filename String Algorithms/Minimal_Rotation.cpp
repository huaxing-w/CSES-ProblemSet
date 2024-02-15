#include "bits/stdc++.h"
using namespace std;

/*
为什么啊
while(i <= k) i += j - k;
这个while loop到底是为什么啊？？？
想不明白家人们

群友说 是最小表示法
卧槽？没听说过啊家人们，等一下去研究下

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    s+=s;
    int n = s.size();
    int i = 0;
    int ans = 0;
    while (i < n/2) {
        ans = i;
        int k = i, j = i + 1;
        while (j < n && s[j] >= s[k]) {
            if (s[j] > s[k] ) k = i;
            if (s[j] == s[k]) k++;
            j++;
        }
        while(i <= k) i += j - k;
    }
    cout<<s.substr(ans,n/2);

    return 0;
}