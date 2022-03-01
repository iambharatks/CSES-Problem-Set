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
const ll oo = LONG_LONG_MAX;

// Floyd-warshall APSP
void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    vvll adjMat(n + 1, vll(n + 1, oo));
    vvll dp(n + 1, vll(n + 1, oo));
    fo(i, 1, m)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adjMat[u][v] = min(adjMat[u][v], w);
        adjMat[v][u] = min(adjMat[v][u], w);
    }
    fo(i, 1, n)
    {
        fo(j, 1, n)
        {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = adjMat[i][j];
        }
    }
    fo(k, 1, n)
    {
        fo(i, 1, n)
        {
            fo(j, 1, n)
            {
                if (dp[i][k] == oo || dp[k][j] == oo)
                    continue;
                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    fo(i, 1, n)
        fo(j, 1, n)
            dp[i][j] = (dp[i][j] == oo) ? -1 : dp[i][j];
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        cout << dp[u][v] << '\n';
    }
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