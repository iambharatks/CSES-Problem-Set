#include <bits/stdc++.h>

#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define mar1(r, c) (r) > (c) ? (r) : (c)
#define s(n) scanint(n)
#define sc(n) scanf(" %c", &n)
#define sl(n) scanf("%ld", &n)
#define sll(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)
#define INF (int)1e9
#define EPS 1e-9
#define bitcount __builtin_popcount
#define gcd __gcd
#define loop(i, a, b) for (ll i = a; i <= b; i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long
#define F first
#define S second

using namespace std;
bool col[8] = {0}, diag1[15] = {0}, diag2[15] = {0};
ll cnt = 0;
bool obstacle[8][8];
void queen(ll r)
{
    if (r == 8)
    {
        cnt++;
        return;
    }
    loop(c, 0, 7)
    {
        if (col[c] || diag1[r + c] || diag2[c - r + 7] || obstacle[r][c])
            continue;
        col[c] = diag1[r + c] = diag2[c - r + 7] = 1;
        queen(r + 1);
        col[c] = diag1[r + c] = diag2[c - r + 7] = 0;
    }
}
int main()
{
    boost;
    loop(i, 0, 7)
    {
        loop(j, 0, 7)
        {
            char x;
            cin >> x;
            if (x == '*')
                obstacle[i][j] = 1;
        }
    }
    queen(0);
    cout << cnt << "\n";
}