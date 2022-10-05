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

bool cmp(pll &a, pll &b)
{
    return a.S < b.S || (a.S == b.S && a.F >= b.F);
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vpll movies(n);
    fo(i, 0, n - 1) cin >> movies[i].F >> movies[i].S;
    sort(all(movies), cmp);
    fo(i, 0, n - 1)
    {
        cout << movies[i].F << " " << movies[i].S << '\n';
    }
    multiset<ll> pq;
    ll cnt = 0;
    fo(i, 0, n - 1)
    {
        if (pq.size() < k)
        {
            pq.insert(movies[i].S);
            cnt++;
        }
        else
        {
            auto it = pq.lower_bound(movies[i].F);
            if (*it > movies[i].F && it == pq.begin())
                continue;
            if (it == pq.end() || *it > movies[i].F)
                it--;
            pq.erase(it);
            pq.insert(movies[i].S);
            cnt++;
        }
        for (auto it : pq)
            cout << it << " ";
        cout << '\n';
    }
    cout << cnt << '\n';
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