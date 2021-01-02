#include <bits/stdc++.h>

#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define max1(x, y) (x) > (y) ? (x) : (y)
#define s(n) scanint(n)
#define sc(n) scanf(" %c", &n)
#define sl(n) scanf("%ld", &n)
#define sll(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define gcd __gcd
#define loop(i, a, b) for (ll i = a; i <= b; i++)
#define all(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define sz(a) ((int)(a.size()))
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long
#define F first
#define S second

typedef vector<ll> vl;
typedef pair<int, int> pi;

using namespace std;

int main()
{
    boost;
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll max = (x > y) ? x : y;
        ll ans = (max - 1) * (max - 1);
        if (max & 1)
            ans += y + max - x;
        else
            ans += max - y + x;
        cout << ans << "\n";
    }
}