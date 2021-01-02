#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
unsigned long long dp[1000005];
unsigned long long diceCombination(unsigned long long n)
{
    for (int i = 1; i <= 6; ++i)
        dp[i] = 1ll << (i - 1);
    for (unsigned long long i = 7; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) % mod;
    return dp[n];
}
// in other words answer is 2^(n-1);
//O(1) by 1<<(n-1)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long n;
    cin >> n;
    cout << diceCombination(n) << "\n";
}