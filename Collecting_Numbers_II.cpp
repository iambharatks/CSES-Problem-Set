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
    ll n, m;
    cin >> n >> m;
    vpll a(n);
    vll b(n);
    ll res = 1;
    fo(i, 0, n - 1)
    {
        cin >> a[i].F;
        a[i].S = i;
        b[i] = a[i].F;
    }
    sort(all(a));
    fo(i, 1, n - 1)
    {
        res += a[i].S < a[i - 1].S;
    }
    fo(i, 0, m - 1)
    {
        ll u, v;
        cin >> u >> v;
        u = b[u - 1];
        v = b[v - 1];
        if (u > v)
            swap(u, v);
        ll cnt1 = 0, cnt2 = 0;
        if (u < n)
            cnt1 += a[u].S < a[u - 1].S;
        if (u > 1)
            cnt1 += a[u - 1].S < a[u - 2].S;
        if (v < n)
            cnt1 += a[v].S < a[v - 1].S;
        if (v > 1 && v != u + 1)
            cnt1 += a[v - 1].S < a[v - 2].S;
        swap(b[a[u - 1].S], b[a[v - 1].S]);
        swap(a[u - 1].S, a[v - 1].S);
        if (u < n)
            cnt2 += a[u].S < a[u - 1].S;
        if (u > 1)
            cnt2 += a[u - 1].S < a[u - 2].S;
        if (v < n)
            cnt2 += a[v].S < a[v - 1].S;
        if (v > 1 && u + 1 != v)
            cnt2 += a[v - 1].S < a[v - 2].S;
        res += (cnt2 - cnt1);
        cout << res << "\n";
    }
}

int main()
{
    iambharatks;
    ll t = 1;
    //    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        //    cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}