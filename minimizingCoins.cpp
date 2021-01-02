#include <bits/stdc++.h>

using namespace std;
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
const int MAX = 2000000;
ll dp[1000005];
ll N;
vector<ll> c;
ll coinsChange(ll n)
{
    for (ll i = 0; i < N; i++)
        dp[c[i]] = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll res = MAX;
        for (ll j = 0; j < N; j++)
        {
            if (i - c[j] >= 0 && dp[i - c[j]] >= 0)
                res = min(dp[i - c[j]] + 1, res);
        }
        dp[i] = (res == MAX || res == 0) ? -1 : res;
    }
    return dp[n];
}

int main()
{
    boost;
    ll X;
    cin >> N >> X;
    c.resize(N);
    for (ll &i : c)
        cin >> i;
    cout << coinsChange(X);
}