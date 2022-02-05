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
vll st;
bool dfs(ll u, vvll &g, vb &vis, ll par)
{
    vis[u] = true;
    st.pb(u);
    for (ll &neigh : g[u])
    {
        if (!vis[neigh])
        {
            if (dfs(neigh, g, vis, u))
                return true;
        }
        else if (neigh != par && st.size() >= 3)
        {
            vll tmp = st;
            reverse(all(tmp));
            while (tmp.back() != neigh)
                tmp.pop_back();
            st = tmp;
            return true;
        }
    }
    st.pop_back();
    return false;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vvll g(n + 1);
    vb vis(n + 1);
    fo(i, 1, m)
    {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // fo(i, 1, n)
    // {
    //     cout << i << "->";
    //     for (int v : g[i])
    //         cout << v << ',';
    //     cout << ln;
    // }
    fo(i, 1, n)
    {
        cout << ln;
        if (!vis[i] && dfs(i, g, vis, -1))
        {
            cout << sz(st) + 1 << ln;
            fo(j, 0, sz(st) - 1) cout << st[j] << ' ';
            cout << st[0] << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
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