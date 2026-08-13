#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define iambharatks                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 998244353;
const int N = 2e5 + 5;
double eps = 1e-12;
const int mod = 1e9 + 7;

void solve()
{
    int n,q;
    cin >> n>> q;
    vector<long long> prefix(n);
    for(int i = 0 ; i < n ; i++){
        cin>>prefix[i];
        if(i > 0)
            prefix[i] += prefix[i-1];
    }
    while(q--){
        int l,r ;
        cin>>l>>r;
        l--;
        r--;
        long long res = prefix[r] - ((l==0)?0:prefix[l-1]);
        cout<<res<<'\n';
    }
}

int main()
{
    iambharatks;
    long long t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}