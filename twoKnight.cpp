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

//Naive approach
ll twoKnight(ll r, ll c, ll n)
{
    if (r == n && c == n)
    {
        return 0;
    }
    ll ans = 0;
    if (r + 1 <= n && c + 2 <= n)
        ans++;
    if (r + 2 <= n && c + 1 <= n)
        ans++;
    if (r + 1 <= n && c - 2 >= 1)
        ans++;
    if (r + 2 <= n && c - 1 >= 1)
        ans++;
    ans = n * n - n * (r - 1) - r - ans;
    if (c == n)
        return ans + twoKnight(r + 1, 1, n);
    else
        return ans + twoKnight(r, c + 1, n);
}

//O(1) waali approach :P
ll solution(ll n)
{
    //total number of ways to place two pieces...
    ll ans = n * n * (n * n - 1) / 2;
    //subtracting two attacking positions ...
    ans -= 4 * (n - 1) * (n - 2);
    return ans;
}

int main()
{
    boost;
    ll n;
    cin >> n;
    loop(i, 1, n)
    {
        cout << solution(i) << "\n";
    }
}