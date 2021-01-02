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
    string s;
    cin >> s;
    char prev = s[0];
    ll ans = 1, counter = 1;
    loop(i, 1, s.size() - 1)
    {
        if (s[i] == prev)
        {
            counter++;
        }
        else
        {
            prev = s[i];
            ans = (counter > ans) ? counter : ans;
            counter = 1;
        }
    }
    ans = (counter > ans) ? counter : ans;
    cout << ans << "\n";
}