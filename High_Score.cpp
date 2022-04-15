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
const ll oo = 1e18;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vvll edges(m);
    vvll g1(n + 1), g2(n + 1);
    fo(i, 0, m - 1)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, -w};
        g1[v].pb(u);
        g2[u].pb(v);
    }
    vll dis(n + 1, oo);
    dis[1] = 0;
    fo(i, 1, n - 1)
    {
        for (auto edge : edges)
        {
            if (dis[edge[1]] > dis[edge[0]] + edge[2])
                dis[edge[1]] = dis[edge[0]] + edge[2];
        }
    }
    vll cycle(n + 1);
    for (auto edge : edges)
    {
        if (dis[edge[1]] > dis[edge[0]] + edge[2])
        {
            dis[edge[1]] = dis[edge[0]] + edge[2];
            cycle[edge[1]] = true;
        }
    }
    queue<ll> q;
    q.push(n);
    vb vis(n + 1, 0);
    vis[n] = true;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (cycle[u])
        {
            cycle[u] = -1;
        }
        for (ll v : g1[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    q.push(1);
    fo(i, 0, n) vis[i] = 0;
    vis[1] = true;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (cycle[u] == -1)
        {
            cout << "-1\n";
            return;
        }
        for (ll v : g2[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << -dis[n] << ln;
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