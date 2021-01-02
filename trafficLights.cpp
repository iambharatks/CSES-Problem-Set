#include <bits/stdc++.h>

using namespace std;
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    boost;
    int x, n;
    cin >> x >> n;
    map<int, int> mp;
    set<int> s;
    s.insert(0);
    s.insert(x);
    mp[x] = 1;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto it = s.lower_bound(p);
        int r = *it;
        --it;
        int l = *it;
        --mp[r - l];
        if (!mp[r - l])
            mp.erase(r - l);
        s.insert(p);
        ++mp[r - p];
        ++mp[p - l];
        cout << (--mp.end())->first << " ";
    }
    return 0;
}