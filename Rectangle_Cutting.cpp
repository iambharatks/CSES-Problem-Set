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

ll rec(ll n, ll m, vvll &dp)
{
    if (n == 0 || m == 0)
        return max(0ll, max(n, m) - 1);
    if (n == m)
        return 0;
    if (dp[n][m] != LLONG_MAX)
        return dp[n][m];
    fo(i, 1, n - 1) dp[n][m] = min(dp[n][m], rec(n - i, m, dp) + rec(i, m, dp) + 1);
    fo(i, 1, m - 1) dp[n][m] = min(dp[n][m], rec(n, m - i, dp) + rec(n, i, dp) + 1);
    return dp[n][m];
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vvll dp(n + 1, vll(m + 1, INT_MAX));
    // cout << rec(n, m, dp) << "\n";
    fo(i, 1, n) dp[i][0] = i - 1;
    fo(i, 1, m) dp[0][i] = i - 1;
    fo(i, 1, n)
    {
        fo(j, 1, m)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT_MAX;
            fo(k, 1, i - 1) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            fo(k, 1, j - 1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
        }
    }
    cout << dp[n][m];
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