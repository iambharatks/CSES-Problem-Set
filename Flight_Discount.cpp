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

struct cmp
{
    bool operator()(vll &a, vll &b)
    {
        return a[1] > b[1];
    }
};
void solve()    
{
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vpll> adj;
    ll u, v, w;
    fo(i, 0, m - 1)
    {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    map<ll, vll> mp;
    mp[1] = {1, 0, 0};
    ll res = LONG_LONG_MAX;
    while (!mp.empty())
    {
        vll tp = mp.begin()->second;
        cout << tp[0] << " " << tp[1] << " " << tp[2] << "\n";
        if (tp[0] == n)
        {
            res = min(res, tp[1]);
        }
        mp.erase(mp.begin());
        if (tp[0] == n)
            continue;
        for (auto neigh : adj[tp[0]])
        {
            ll disc = max(tp[2], neigh.S);
            ll dis = tp[1] + neigh.S + tp[2] - tp[2] / 2;
            dis += disc / 2 - disc;
            if (mp.count(neigh.F))
            {
                if (mp[neigh.F][1] == dis && mp[neigh.F][2] > disc)
                    mp[neigh.F] = {neigh.F, dis, disc};
                else if (mp[neigh.F][1] > dis)
                    mp[neigh.F] = {neigh.F, dis, disc};
            }
            else
                mp[neigh.F] = {neigh.F, dis, disc};
        }
    }
    cout << (res == LLONG_MAX ? -1 : res);
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