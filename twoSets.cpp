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

using namespace std;

int main()
{
    boost;
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << "NO\n";
    }
    else
    {
        vector<ll> l, r;
        l.PB(n - 1);
        r.PB(n);
        ll left = n - 1, right = n;
        n -= 2;
        while (n != 0)
        {
            if (left < right)
            {
                left += n;
                l.PB(n);
                n--;
            }
            else
            {
                right += n;
                r.PB(n);
                n--;
            }
        }
        cout << "YES\n";
        cout << l.size() << "\n";
        for (ll i = l.size() - 1; i >= 0; i--)
            cout << l[i] << " ";
        cout << "\n"
             << r.size() << "\n";
        for (ll i = r.size() - 1; i >= 0; i--)
            cout << r[i] << " ";
    }
}