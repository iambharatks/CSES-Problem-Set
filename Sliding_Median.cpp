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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    multiset<ll> minH, maxH;
    fo(i, 0, n - 1) cin >> a[i];
    vll res(n - k + 1);
    fo(i, 0, k - 1)
    {
        if (maxH.empty())
            maxH.insert(a[i]);
        else if (*maxH.rbegin() >= a[i])
        {
            minH.insert(*maxH.rbegin());
            maxH.erase(--maxH.end());
            maxH.insert(a[i]);
        }
        else
            minH.insert(a[i]);
        while (maxH.size() < minH.size())
        {
            maxH.insert(*minH.begin());
            minH.erase(minH.begin());
        }
    }
    res[0] = *maxH.rbegin();
    fo(i, k, n - 1)
    {
        if (maxH.count(a[i - k]))
            maxH.erase(maxH.find(a[i - k]));
        else
            minH.erase(minH.find(a[i - k]));
        while (maxH.size() < minH.size())
        {
            maxH.insert(*minH.begin());
            minH.erase(minH.begin());
        }
        if (maxH.empty())
            maxH.insert(a[i]);
        else if (*maxH.rbegin() >= a[i])
        {
            minH.insert(*maxH.rbegin());
            maxH.erase(--maxH.end());
            maxH.insert(a[i]);
        }
        else
            minH.insert(a[i]);
        while (maxH.size() < minH.size())
        {
            maxH.insert(*minH.begin());
            minH.erase(minH.begin());
        }
        res[i - k + 1] = *maxH.rbegin();
    }
    fo(i, 0, sz(res) - 1) cout << res[i] << " ";
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