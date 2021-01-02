#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int combinations(vector<int> coin, int x)
{
    int n = coin.size();
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (coin[i] > x)
            continue;kf
        dp[coin[i]] = 1;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int c = 0; c < n; c++)
        {
            if (coin[c] <= i)
                dp[i] = (dp[i] + dp[i - coin[c]]) % mod;
        }
    }
    return dp[x];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for (int &i : coin)
        cin >> i;
    cout << combinations(coin, x);
}