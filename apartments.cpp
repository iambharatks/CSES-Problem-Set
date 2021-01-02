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
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long

using namespace std;

int main()
{
    boost;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> applicant(n, 0), appartment(m, 0);
    for (ll &i : applicant)
        cin >> i;
    for (ll &i : appartment)
        cin >> i;
    sort(all(applicant));
    sort(all(appartment));
    ll i = 0, j = 0;
    ll ans = 0;
    while (i != n && j != m)
    {
        ll l = applicant[i] - k, r = applicant[i] + k;
        if (appartment[j] >= l && appartment[j] <= r)
        {
            j++;
            i++;
            ans++;
        }
        else if (appartment[j] < l)
        {
            j++;
        }
        else 
        {
            i++;
        }
    }
    cout << ans << "\n";
}