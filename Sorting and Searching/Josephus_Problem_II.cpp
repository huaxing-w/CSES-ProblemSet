#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

/*
我靠这个有点高级
这个是我抄的别人的code
这c++写的有点高级，我有点看不懂
我先去上班了，回来让gpt教教我
这都什么奇奇怪怪的东西
这个indexed_set是什么鬼啊
*/

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define int long long
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    indexed_set s;
    int n,k; cin>>n>>k;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    int ind = k%n;
    while(n--) {
        auto y = s.find_by_order(ind);
        cout<<*y<<' ';
        s.erase(y);
        if (n) ind = (ind%n + k)%n;
    }   
}