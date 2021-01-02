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

map<string, bool> string_permutation;

void permutation(string s, int l, int r)
{
    if (l == r)
    {
        if (!string_permutation[s])
            string_permutation[s] = true;
        return;
    }
    loop(i, l, r)
    {
        swap(s[l], s[i]);
        permutation(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main()
{
    string s;
    cin >> s;
    permutation(s, 0, s.size() - 1);
    cout << string_permutation.size() << "\n";
    for (auto i : string_permutation)
    {
        cout << i.F << "\n";
    }
}