#include <bits/stdc++.h>

using namespace std;
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define ll long long

bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> m(n);
    for (pair<ll, ll> &i : m)
    {
        ll x, y;
        cin >> x >> y;
        i = {x, y};
    }
    sort(m.begin(), m.end(), compare);
    ll prev_end = 0, ans = 0;
    for (auto i : m)
    {
        if (i.first >= prev_end)
        {
            ans++;
            prev_end = i.second;
        }
    }
    cout<<ans<<" ";
}