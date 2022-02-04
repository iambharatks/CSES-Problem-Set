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

bool isBipartite(ll v, vvll &g, vll &color)
{
    queue<ll> q;
    q.push(v);
    color[v] = 0;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (ll &neigh : g[v])
        {
            if (color[neigh] == -1)
            {
                color[neigh] = 1 - color[v];
                q.push(neigh);
            }
            else if (color[neigh] == color[v])
                return false;
        }
    }
    return true;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vvll g(n + 1);
    vll color(n + 1, -1);

    fo(i, 0, m - 1)
    {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fo(i, 1, n)
    {
        if (color[i] == -1 && !isBipartite(i, g, color))
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    fo(i, 1, n) cout << color[i] + 1 << ' ';
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