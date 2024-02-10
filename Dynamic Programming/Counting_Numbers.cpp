#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using lll = __int128; // Using __int128 for calculations

/*
我从早上6点开始做这道题，一直做了俩个小时
终于ac了
类目

数位dp的具体应用，但是这道题出的很不好，他需要用到128的int不然会爆int



*/


// Function to read __int128
void read(lll &x) {
    string s;
    cin >> s;
    x = 0;
    for (char c : s) {
        x = x * 10 + (c - '0');
    }
}

// Function to print __int128
void print(lll x) {
    if (x == 0) { // Directly handle the case of 0
        cout << "0\n";
        return;
    }
    if (x < 0) { cout << "-"; x = -x; }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

lll solve(lll x){
    if(x < 0) return 0; // Ensure non-negative input
    string s = to_string((ll)x); // Conversion workaround; may need adjustment for full __int128 support
    int n = s.size();
    lll memo[n+1][3][3][12];
    memset(memo, -1, sizeof(memo));
    function<lll(int,int,bool,int)>dfs=[&](int index, int is_limit, bool is_num, int prev)->lll{
        if(index == n){
            return is_num; // Ensure 0 is counted if it's within the range
        }
        if(memo[index][is_limit][is_num][prev+1] != -1) return memo[index][is_limit][is_num][prev+1];
        lll res = 0;
        int up = is_limit ? (s[index]-'0') : 9;
        for(int i = 1-is_num; i <= up; ++i){
            if(i == prev) continue;
            res += dfs(index + 1, is_limit && i == up, true, i);
        }
        // Directly account for the case when no digit has been chosen yet
        if (!is_num) {
            res += dfs(index + 1, 0, false, -1); // Adjusted to ensure this path does not prematurely count as valid
        }
        return memo[index][is_limit][is_num][prev+1] = res;
    };
    return dfs(0, 1, false, -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lll a, b;
    read(a);
    read(b);
    // Special handling to ensure 0 is counted correctly in the range
    if(a <= 0) {
        print(solve(b) + 1); // +1 to explicitly include 0 in the count
    } else {
        print(solve(b) - solve(a - 1));
    }
    cout << "\n";
    
    return 0;
}
