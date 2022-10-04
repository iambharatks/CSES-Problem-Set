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

bool possible(vll &a, ll &k, ll &maxSum)
{
    ll curSum = 0;
    ll cnt = 1;
    fo(i, 0, sz(a) - 1)
    {
        if (a[i] > maxSum)
            return false;
        if (curSum + a[i] > maxSum)
        {
            curSum = a[i];
            cnt++;
        }
        else
            curSum += a[i];
    }
    return cnt <= k;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    fo(i, 0, n - 1) cin >> a[i];
    ll l = 0, r = 1e18, res = 1e18;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (possible(a, k, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res;
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