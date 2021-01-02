#include <bits/stdc++.h>
#define ll long long
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define F first
using namespace std;

int main()
{
    boost;
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
    {
        ll p;
        cin >> p;
        a[i] = {p, i + 1};
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (a[l].F + a[r].F == x)
            break;
        else if (a[l].F + a[r].F < x)
            l++;
        else
            r--;
    }
    if (l >= r)
        cout << "IMPOSSIBLE\n";
    else
        cout << a[l].second << " " << a[r].second << "\n";
}