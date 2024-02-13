#include "bits/stdc++.h"
using namespace std;
using ll = long long;

/*
Z-函数牛逼
*/

vector<ll> z_function(string& s) {
    ll n = (ll)s.length();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    // Concatenating pattern with a delimiter and the string
    string temp = s2 + "$" + s1; // Use a character like '$' as a delimiter
    vector<ll> z = z_function(temp);
    ll ans = 0;
    // Start iteration from s2.size() + 1 to skip the pattern and delimiter part
    for (ll i = s2.size() + 1; i < temp.size(); i++) {
        if (z[i] >= s2.size()) ans += 1;
    }
    cout << ans << "\n";
    return 0;
}
