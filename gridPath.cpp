#include <bits/stdc++.h>

#define boost                \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define max1(x, y) (x) > (y) ? (x) : (y)
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
#define rev(i, a, b) for (ll i = b; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n, b) ((n >> b) & 1)
#define gc getchar_unlocked
#define ll long long

using namespace std;

ll w = 0, steps = 0;
bool v[7][7];
int reserved[49];

void move(ll r, ll c)
{
    if (r == 6 && c == 0)
    {
        if (steps == 48)
            w++;
        return;
    }
    bool t = v[r][c] || (c > 0 && c < 6 && !v[r][c + 1] && !v[r][c - 1] && ((r == 0 && v[r + 1][c]) || (r == 6 && v[r - 1][c]))) || (r > 0 && r < 6 && !v[r + 1][c] && !v[r - 1][c] && ((c == 0 && v[r][c + 1]) || (c == 6 && v[r][c - 1]))) || (r > 0 && r < 6 && c > 0 && c < 6 && v[r - 1][c] && v[r + 1][c] && !v[r][c - 1] && !v[r][c + 1]) || (r > 0 && r < 6 && c > 0 && c < 6 && v[r][c - 1] && v[r][c + 1] && !v[r - 1][c] && !v[r + 1][c]);
    if (t)
        return;
    v[r][c] = true;
    if (reserved[steps] != -1)
    {

        switch (reserved[steps])
        {
        case 0:
            if (r > 0 && !v[r - 1][c])
            {
                steps++;
                move(r - 1, c);
                steps--;
            }
            break;
        case 2:
            if (r < 6 && !v[r + 1][c])
            {
                steps++;
                move(r + 1, c);
                steps--;
            }
            break;
        case 3:
            if (c > 0 && !v[r][c - 1])
            {
                steps++;
                move(r, c - 1);
                steps--;
            }
            break;
        case 1:
            if (c < 6 && !v[r][c + 1])
            {
                steps++;
                move(r, c + 1);
                steps--;
            }
            break;
        }
        v[r][c] = false;

        return;
    }
    if (r > 0 && !v[r - 1][c])
    {
        steps++;
        move(r - 1, c);
        steps--;
    }
    if (r < 6 && !v[r + 1][c])
    {
        steps++;
        move(r + 1, c);
        steps--;
    }
    if (c > 0 && !v[r][c - 1])
    {
        steps++;
        move(r, c - 1);
        steps--;
    }
    if (c < 6 && !v[r][c + 1])
    {
        steps++;
        move(r, c + 1);
        steps--;
    }
    v[r][c] = false;
}

int main()
{
    //    auto start = chrono::steady_clock::now();

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '?')
            reserved[i] = -1;
        else if (str[i] == 'U')
            reserved[i] = 0;
        else if (str[i] == 'R')
            reserved[i] = 1;
        else if (str[i] == 'D')
            reserved[i] = 2;
        else if (str[i] == 'L')
            reserved[i] = 3;
    }
    move(0, 0);
    cout << w;
    //    auto end = chrono::steady_clock::now();
    //    cout << "\nElapsed time in milliseconds : "
    //         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
    //         << " ms\n";
    return 0;
}