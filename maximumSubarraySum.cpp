#include <bits/stdc++.h>
#define ll long long
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define F first
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n);
    for (ll &i : x)
        cin >> i;
    ll curSum = x[0], maxSum = x[0];
    for (int i = 1; i < n; i++)
    {
        curSum = (curSum + x[i] > x[i]) ? curSum + x[i] : x[i];
        maxSum = (maxSum > curSum) ? maxSum : curSum;
    }
    cout << maxSum << "\n";
}