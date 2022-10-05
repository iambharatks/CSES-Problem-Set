#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define iambharatks                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define bitcount __builtin_popcount
#define setbits(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define fo(i, j, n) for (ll i = j; i <= n; i++)
#define rev(i, j, n) for (ll i = n; i >= j; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF 2e18
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define read(a)       \
    for (auto &i : a) \
        cin >> i;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 998244353;
const int N = 2e5 + 5;
double eps = 1e-12;
const int mod = 1e9 + 7;

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vll v(n);
    vll maxE, minE;
    multiset<ll> ms;
    fo(i, 0, n - 1)
    {
        cin >> v[i];
        if (i > 0)
            v[i] += v[i - 1];
    }
    ll res = 0;
    ll l = a - 1, j = 0;
    ll len = b - a + 1;
    fo(i, a - 1, n - 1)
    {
        if (ms.size() == len)
        {
            ms.erase(ms.find(v[l++]));
        }
        ms.insert(v[i]);
        if (ms.size() == len)
        {
            maxE.push_back(*ms.rbegin());
        }
    }
    while (ms.size() > 1)
    {
        ms.erase(ms.find(v[l++]));
        maxE.push_back(*ms.rbegin());
    }
    res = maxE[0];
    fo(i, 1, sz(maxE) - 1)
    {
        res = max(res, maxE[i] - v[i - 1]);
    }
    cout << res << '\n';
}

int main()
{
    iambharatks;
    ll t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}