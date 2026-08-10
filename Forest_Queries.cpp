#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define iambharatks                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 998244353;
const int N = 2e5 + 5;
double eps = 1e-12;
const int mod = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin>>c;
            mat[i][j] = (c == '*') ? 1 : 0;
            if (i > 0)
                mat[i][j] += mat[i - 1][j];
            if (j > 0)
                mat[i][j] += mat[i][j - 1];
            if (i > 0 && j > 0)
                mat[i][j] -= mat[i - 1][j - 1];
        }
    }
    for(int i = 0 ; i < q;  i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int ans = mat[x2][y2];
        if (x1 > 0)
            ans -= mat[x1 - 1][y2];
        if (y1 > 0)
            ans -= mat[x2][y1 - 1];
        if (x1 > 0 && y1 > 0)
            ans += mat[x1 - 1][y1 - 1];
        cout << ans << endl;
    }

}

int main()
{
    iambharatks;
    long long t = 1;
    // cin >> t;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}