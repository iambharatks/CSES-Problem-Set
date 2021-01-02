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
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        if (a > 2 * b)
            cout << "NO\n";
        else
        {
            a %= 3, b %= 3;
            if (a < b)
                swap(a, b);
            if ((a == 2 && b == 1) || (a == b && a == 0))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}