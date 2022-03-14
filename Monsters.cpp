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

ll dr[4] = {-1, 1, 0, 0};
ll dc[4] = {0, 0, -1, 1};
char d[4] = {'D', 'U', 'R', 'L'};
void solve()
{
    ll n, m, sr, sc;
    cin >> n >> m;
    vector<string> mat(n, "");
    queue<pll> q;
    int i = 0;
    vvll dist(n, vll(m, INT_MAX)), M(n, vll(m, INT_MAX));
    vector<vpll> parent(n, vpll(m, {-1, -1}));
    for (string &s : mat)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'M')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
            else if (mat[i][j] == 'A')
            {
                sr = i, sc = j;
                M[sr][sc] = 0;
            }
        }
        i++;
    }
    while (!q.empty())
    {
        ll r = q.front().F, c = q.front().S;
        q.pop();
        fo(i, 0, 3)
        {
            ll nr, nc;
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || mat[nr][nc] == '#')
                continue;
            if (dist[nr][nc] > dist[r][c] + 1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    q.push({sr, sc});
    ll er = -1, ec = -1;
    while (!q.empty())
    {
        ll r = q.front().F, c = q.front().S;
        q.pop();
        if (r == n - 1 || c == m - 1 || r == 0 || c == 0)
        {
            er = r, ec = c;
            break;
        }
        fo(i, 0, 3)
        {
            ll nr, nc;
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || mat[nr][nc] == '#' || mat[nr][nc] == 'M')
                continue;
            if (dist[nr][nc] > M[r][c] + 1)
            {
                q.push({nr, nc});
                M[nr][nc] = M[r][c] + 1;
                parent[nr][nc] = {r, c};
            }
        }
    }
    if (er == -1)
    {
        cout << "NO\n";
        return;
    }
    pll par = {er, ec};
    string ans = "";
    while (par != mp(sr, sc) && par.F != -1)
    {
        fo(i, 0, 3)
        {
            if (parent[par.F][par.S] == mp(par.F + dr[i], par.S + dc[i]))
            {
                ans.push_back(d[i]);
                break;
            }
        }
        par = parent[par.F][par.S];
    }
    cout << "YES\n";
    cout << sz(ans) << ln;
    reverse(all(ans));
    cout << ans << ln;
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