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

ll rec(ll l, ll r, vll &a, vvll &dp, bool turn)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
    {
        if (turn)
            return dp[l][r] = a[l];
        return dp[l][r] = 0;
    }
    if (turn)
        return dp[l][r] = max(rec(l + 1, r, a, dp, !turn) + a[l], rec(l, r - 1, a, dp, !turn) + a[r]);
    return dp[l][r] = min(rec(l + 1, r, a, dp, !turn), rec(l, r - 1, a, dp, !turn));
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    for (ll &i : a)
        cin >> i;
    vvll dp(n, vll(n, 0));
    fo(i, 0, n - 1) dp[i][i] = (n & 1) ? a[i] : 0;
    fo(i, 0, n - 1)
    {
        ll x = 0, y = i + 1;
        while (y < n)
        {
            if ((x + n - y) & 1)
                dp[x][y] = max(dp[x + 1][y] + a[x], dp[x][y - 1] + a[y]);
            else
                dp[x][y] = min(dp[x + 1][y], dp[x][y - 1]);
            x++, y++;
        }
    }
    cout << dp[0][n - 1];
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