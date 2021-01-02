#include <bits/stdc++.h>

using namespace std;
#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
int main()
{
    int n;
    cin >> n;
    vector<pair<int, bool>> customer(2 * n);
    for (int i = 0; i < 2 * n; i += 2)
    {
        int x, y;
        cin >> x >> y;
        customer[i] = {x, 0};
        customer[i + 1] = {y, 1};
    }
    sort(customer.begin(), customer.end());
    long long ans = 0, cur = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (customer[i].second == 0)
        {
            cur++;
        }
        else
        {
            cur--;
        }
        ans = (ans < cur) ? cur : ans;
    }
    cout << ans << "\n";
}