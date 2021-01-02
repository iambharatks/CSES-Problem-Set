#include <bits/stdc++.h>
#define ll long long
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define F first
using namespace std;

int n;
vector<ll> p;
//Method 1.
void solve1(ll sum)
{
    ll curCost = 0, minCost = LONG_LONG_MAX, curSum = 0;
    for (int i = 0; i < n; i++)
    {
        // curCost = (sum - curSum) - p[i] * (n - i) + i * p[i] - curSum;
        curCost = sum - 2 * curSum - p[i] * (n - 2 * i);
        // cout << curCost << " ";
        minCost = (curCost < minCost) ? curCost : minCost;
        curSum += p[i];
    }
    cout << minCost << "\n";
}
//2.Method
// void solve2(ll sum)
// {
//     ll median = p[n / 2];
//     ll curSum = 0;
//     int i;
//     for (i = 0; i < n / 2; i++)
//     {
//         curSum += p[i];
//     }
//     ll minCost = sum - 2 * curSum - median * (n - 2 * i);
//     cout << minCost << "\n";
// }
int main()
{
    boost;
    cin >> n;
    p.resize(n);
    ll sum = 0;
    for (ll &i : p)
    {
        cin >> i;
        sum += i;
    }
    sort(p.begin(), p.end());
    solve1(sum);
}