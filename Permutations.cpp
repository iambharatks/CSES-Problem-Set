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
    ll n;
    cin >> n;
    if (n == 2 || n == 3)
        cout << "NO SOLUTION\n ";
    else
    {
        for (ll i = 2; i <= n - (n & 1); i += 2)
        {
            cout << i << " ";
        }
        for (ll i = 1; i <= n - 1 + (n & 1); i += 2)
        {
            cout << i << " ";
        }
    }
}