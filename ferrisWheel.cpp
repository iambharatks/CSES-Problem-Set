#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> child(n);
    for (long long &i : child)
    {
        cin >> i;
    }
    sort(child.begin(), child.end());
    long long l = 0, r = n - 1, ans = 0;
    while (l <= r)
    {
        if (l == r)
        {
            ans++;
            break;
        }
        if (child[l] + child[r] <= x)
        {
            ans++;
            l++, r--;
        }
        else
        {
            ans++;
            r--;
        }
    }
    cout << ans << "\n";
}