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
#define rev(i, a, b) for (ll i = b; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    for (ll &i : a)
        cin >> i;
    ll ans = INT_MAX, current = 0;
    loop(i, 0, (1 << n) - 1)
    {
        loop(j, 0, n - 1)
        {
            if (i & (1 << j))
            {
                current += a[j];
            }
            else
            {
                current -= a[j];
            }
        }
        current = (current < 0) ? -1 * current : current;
        ans = (ans > current) ? current : ans;
        current = 0;
    }
    cout << ans << "\n";
}