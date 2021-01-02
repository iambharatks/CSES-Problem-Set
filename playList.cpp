#include <bits/stdc++.h>

using namespace std;
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define S second
#define F first
int main()
{
    boost;
    long long n, ans = 0;
    cin >> n;
    vector<long long> p(n);
    //!unordered_map worked slower in this case
    //!Write reason below when found
    map<long long, long long> mp;
    for (long long &i : p)
        cin >> i;
    for (long long i = 0, j = 0; i < n; i++)
    {
        while (j < n && mp[p[j]] < 1)
        {
            mp[p[j]]++;
            ++j;
        }
        cout << i << " " << j << " " << ans << "\n";
        ans = max(j - i, ans);
        mp[p[i]]--;
    }
    cout << ans << "\n";
}